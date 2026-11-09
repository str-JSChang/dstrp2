# Presenter rehearsal results

28 real-console scenarios passed. Run after compiling:

```bash
python3 tests/presenter_rehearsal.py build/parcel_system
```

On Windows use `python tests/presenter_rehearsal.py build/parcel_system.exe`.

Each scenario starts a fresh process. Exact menu inputs and complete console output are saved
under `build/presenter-rehearsal/` as matching `.input.txt` and `.output.txt` files.

The first scenario follows the visual guide: register two parcels, show records/intake, route P1,
register C1, assign R1, process, verify S1001, complete and inspect all three modules.

| Scenario | Confirmed console evidence |
| --- | --- |
| 01-presenter-collection | Registered parcel P2; Created request R1; Assigned resource C1; Parcel status: Collected; R1 / parcel P1 / Collection / Normal / status Completed; C1 / Counter A / Counter / Available |
| blank-field-1 | All parcel details are required.; Registered parcel P1 |
| blank-field-2 | All parcel details are required.; Registered parcel P1 |
| blank-field-3 | All parcel details are required.; Registered parcel P1 |
| blank-field-4 | All parcel details are required.; Registered parcel P1 |
| blank-field-5 | All parcel details are required.; Registered parcel P1 |
| blank-field-6 | All parcel details are required.; Registered parcel P1 |
| blank-field-7 | All parcel details are required.; Registered parcel P1 |
| duplicate-tracking | Duplicate tracking number.; Registered parcel P2 |
| wrong-recipient-unchanged | Recipient verification failed.; status In progress; resource C1; C1 / Counter A / Counter / Occupied |
| blank-outcome-unchanged | Completion details are required.; status In progress; C1 / Counter A / Counter / Occupied |
| no-resource | No suitable resource is available.; status Pending; resource - |
| wrong-resource-type | Resource type does not match the requested service.; status Pending |
| empty-intake | Intake queue is empty. |
| manual-release | status Pending; resource -; C1 / Counter A / Counter / Available |
| active-edit-blocked | Finish or cancel the active request; P1 / Aina; tracking TRK001; status In progress |
| remove-live-blocked | Only cancelled parcels can be removed. |
| cancel-and-delete | Request and parcel cancelled.; No parcel records.; No parcels waiting.; C1 / Counter A / Counter / Available |
| missing-recover-resume | Request stopped. Parcel status: Missing; Recover missing parcels to On hold first.; Created request R2; status Cancelled; R2 / parcel P1 / Collection / Normal / status Pending; C1 / Counter A / Counter / Available |
| duplicate-active-request | Parcel already has an active request. |
| pending-process-complete-blocked | Assign a resource before processing; Only an in-progress request can be completed.; status Pending |
| service-1-lifecycle | Parcel status: Collected; status Completed; / Available |
| service-2-lifecycle | Parcel status: Delivered; status Completed; / Available |
| service-3-lifecycle | Parcel status: On hold; status Completed; / Available |
| service-4-lifecycle | Parcel status: Delivered; status Completed; / Available |
| service-5-lifecycle | Parcel status: Returned; status Returned; / Available |
| delivered-redelivery-blocked | Completed parcels cannot receive another service. |
| restart-empty | No parcel records.; No parcels waiting.; No active service requests.; No resources registered. |

## Scope and other validation

The separate system suite passed 543 checks across eight suites, including 100 lifetime cycles.
It checks linked-node boundary cases, priority ties, per-type resource rotation, invalid enum values,
unknown IDs, state preservation after rejection, resource links, and every service lifecycle.
The existing console suite also passed 28 scenarios for menus, malformed numbers, EOF and navigation.
These are covered cases, not a proof that every possible input or memory failure is handled.
Execution here used Windows GCC; the Linux command is documented but was not run on a Linux host.
