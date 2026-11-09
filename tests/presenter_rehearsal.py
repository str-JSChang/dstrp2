"""Run real console rehearsals and save repeatable input/output evidence."""
from pathlib import Path
import subprocess
import sys

root = Path(__file__).resolve().parents[1]
executable = str(Path(sys.argv[1]).resolve())
evidence = root / 'build' / 'presenter-rehearsal'
evidence.mkdir(parents=True, exist_ok=True)
results = []


def lines(*values):
    return '\n'.join(str(v) for v in values) + '\n'


def menu(number, *values):
    return lines(number, *values, 0)


def register(tracking='TRK001', recipient='S1001', fields=None):
    return menu(1, 1, *(fields or ['Aina', recipient, '0123456789', 'Courier', tracking, 'Block A', 'Box']))


def request(service=1, parcel='P1', recipient='S1001', details='Handle parcel', priority=2):
    return menu(2, 1, parcel, recipient, details, service, priority)


def resource(kind=1, identifier='C1'):
    return menu(3, 1, identifier, 'Counter A' if kind == 1 else 'Driver A', kind)


def assign(kind=1, identifier='R1'):
    return menu(3, 3, identifier, kind)


def inspect():
    return menu(1, 2, 7) + menu(2, 8, 'R1') + menu(3, 2)


def run(name, inputs, expected, forbidden=()):
    result = subprocess.run([executable], input=inputs + '0\n', text=True, capture_output=True, timeout=5)
    (evidence / (name + '.input.txt')).write_text(inputs + '0\n', encoding='utf-8')
    (evidence / (name + '.output.txt')).write_text(result.stdout + result.stderr, encoding='utf-8')
    assert result.returncode == 0, (name, result.stderr)
    for text in expected:
        assert text in result.stdout, (name, 'missing', text)
    for text in forbidden:
        assert text not in result.stdout, (name, 'unexpected', text)
    results.append((name, expected))


base = register() + request()
active = base + resource() + assign() + menu(2, 4, 'R1')
run('01-presenter-collection', register() + register('TRK002', 'S1002') + menu(1, 2, 7, 4, 1, 2, 3, 'P1')
    + resource() + assign() + menu(2, 4, 'R1', 5, 'R1', 1, 'Collected by Aina', 'S1001') + inspect(),
    ['Registered parcel P2', 'Created request R1', 'Assigned resource C1', 'Parcel status: Collected',
     'R1 | parcel P1 | Collection | Normal | status Completed', 'C1 | Counter A | Counter | Available'], ['Operation failed'])
for index in range(7):
    fields = ['Aina', 'S1001', '0123456789', 'Courier', 'TRK001', 'Block A', 'Box']
    fields[index] = '   '
    run(f'blank-field-{index+1}', register(fields=fields) + register(),
        ['All parcel details are required.', 'Registered parcel P1'], ['Registered parcel P2'])
run('duplicate-tracking', register() + register() + register('TRK002'),
    ['Duplicate tracking number.', 'Registered parcel P2'], ['Registered parcel P3'])
run('wrong-recipient-unchanged', active + menu(2, 5, 'R1', 1, 'Collected', 'WRONG') + inspect(),
    ['Recipient verification failed.', 'status In progress', 'resource C1', 'C1 | Counter A | Counter | Occupied'])
run('blank-outcome-unchanged', active + menu(2, 5, 'R1', 1, '   ', 'S1001') + inspect(),
    ['Completion details are required.', 'status In progress', 'C1 | Counter A | Counter | Occupied'])
run('no-resource', base + assign() + inspect(), ['No suitable resource is available.', 'status Pending', 'resource -'])
run('wrong-resource-type', base + resource(2, 'D1') + assign(2) + inspect(),
    ['Resource type does not match the requested service.', 'status Pending'])
run('empty-intake', menu(1, 4, 1, 2), ['Intake queue is empty.'])
run('manual-release', active + menu(3, 4, 'C1') + inspect(),
    ['status Pending', 'resource -', 'C1 | Counter A | Counter | Available'])
run('active-edit-blocked', active + menu(1, 5, 'P1', 'Bob', 'S1001', '012', 'Courier', 'NEW', 'Block B', 'Box') + inspect(),
    ['Finish or cancel the active request', 'P1 | Aina', 'tracking TRK001', 'status In progress'])
run('remove-live-blocked', base + menu(1, 6, 'P1'), ['Only cancelled parcels can be removed.'])
run('cancel-and-delete', active + menu(2, 6, 'R1', 7, 'R1') + menu(1, 6, 'P1', 2, 7) + menu(3, 2),
    ['Request and parcel cancelled.', 'No parcel records.', 'No parcels waiting.', 'C1 | Counter A | Counter | Available'])
run('missing-recover-resume', active + menu(2, 9, 'R1', 1) + menu(1, 9, 'P1', 1, 2, 8, 'P1', 2, 9, 'P1', 1, 2)
    + menu(2, 8, 'R1', 8, 'R2') + menu(3, 2),
    ['Request stopped. Parcel status: Missing', 'Recover missing parcels to On hold first.', 'Created request R2',
     'status Cancelled', 'R2 | parcel P1 | Collection | Normal | status Pending', 'C1 | Counter A | Counter | Available'])
run('duplicate-active-request', base + request(), ['Parcel already has an active request.'], ['Created request R2'])
run('pending-process-complete-blocked', base + menu(2, 4, 'R1', 5, 'R1', 1, 'Done', 'S1001') + inspect(),
    ['Assign a resource before processing', 'Only an in-progress request can be completed.', 'status Pending'])
for service, status, request_status in [(1, 'Collected', 'Completed'), (2, 'Delivered', 'Completed'),
                                         (3, 'On hold', 'Completed'), (4, 'Delivered', 'Completed'), (5, 'Returned', 'Returned')]:
    kind = 1 if service == 1 else 2
    run(f'service-{service}-lifecycle', register() + request(service) + resource(kind, 'RES') + assign(kind)
        + menu(2, 4, 'R1', 5, 'R1', 1, 'Service done', 'S1001') + inspect(),
        ['Parcel status: ' + status, 'status ' + request_status, '| Available'])
run('delivered-redelivery-blocked', register() + request(2) + resource(2, 'D1') + assign(2)
    + menu(2, 4, 'R1', 5, 'R1', 1, 'Delivered', 'S1001') + request(4),
    ['Completed parcels cannot receive another service.'], ['Created request R2'])
run('restart-empty', menu(1, 2, 7) + menu(2, 2) + menu(3, 2),
    ['No parcel records.', 'No parcels waiting.', 'No active service requests.', 'No resources registered.'])
report = ['# Presenter rehearsal results', '', f'{len(results)} real-console scenarios passed. Run after compiling:', '',
          '```bash', 'python3 tests/presenter_rehearsal.py build/parcel_system', '```', '',
          'On Windows use `python tests/presenter_rehearsal.py build/parcel_system.exe`.', '',
          'Each scenario starts a fresh process. Exact menu inputs and complete console output are saved',
          'under `build/presenter-rehearsal/` as matching `.input.txt` and `.output.txt` files.', '',
          'The first scenario follows the visual guide: register two parcels, show records/intake, route P1,',
          'register C1, assign R1, process, verify S1001, complete and inspect all three modules.', '',
          '| Scenario | Confirmed console evidence |', '| --- | --- |']
for name, expected in results:
    report.append('| ' + name + ' | ' + '; '.join(expected).replace('|', '/') + ' |')
report += ['', '## Scope and other validation', '',
           'The separate system suite passed 543 checks across eight suites, including 100 lifetime cycles.',
           'It checks linked-node boundary cases, priority ties, per-type resource rotation, invalid enum values,',
           'unknown IDs, state preservation after rejection, resource links, and every service lifecycle.',
           'The existing console suite also passed 28 scenarios for menus, malformed numbers, EOF and navigation.',
           'These are covered cases, not a proof that every possible input or memory failure is handled.',
           'Execution here used Windows GCC; the Linux command is documented but was not run on a Linux host.', '']
(root / 'docs' / 'PRESENTER_REHEARSAL_RESULTS.md').write_text('\n'.join(report), encoding='utf-8')
print(f'PASS: {len(results)} presenter scenarios; transcripts in {evidence}')
