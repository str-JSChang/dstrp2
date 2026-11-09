from pathlib import Path
import subprocess
import sys

executable = str(Path(sys.argv[1]).resolve())
checks = 0


def run_case(name, input_text, expected, rejected=()):
    global checks
    result = subprocess.run([executable], input=input_text, text=True,
                            capture_output=True, timeout=5)
    if result.returncode != 0:
        raise AssertionError(f"{name}: exit {result.returncode}: {result.stderr}")
    for fragment in expected:
        if fragment not in result.stdout:
            raise AssertionError(f"{name}: missing {fragment!r}\n{result.stdout}")
    for fragment in rejected:
        if fragment in result.stdout:
            raise AssertionError(f"{name}: unexpected {fragment!r}\n{result.stdout}")
    checks += 1


run_case("navigation", "1\n0\n2\n0\n3\n0\n0\n",
         ["TASK 1", "TASK 2", "TASK 3", "Goodbye."])
run_case("bad choices", "\nabc\n999999999999999999999\n-1\n4\n1x\n0\n",
         ["Enter a number from 0 to 3.", "Goodbye."])
run_case("EOF at main", "", ["Goodbye."])
run_case("EOF while registering", "1\n1\nAlice\n", ["Goodbye."], ["Registered parcel"])

# Register and route a collection, allocate a counter, process, verify and complete.
register = "1\n1\nAlice\nTP001\n012345\nCourier\nTRACK1\nBlock A\nBox\n"
route = "4\n1\n2\n0\n"
counter = "3\n1\nC1\nCounter A\n1\n3\nR1\n1\n0\n"
complete = "2\n4\nR1\n5\nR1\n1\nCollected by recipient\nTP001\n0\n"
inspect = "1\n3\nP1\n0\n3\n2\n0\n0\n"
run_case("integrated collection", register + route + counter + complete + inspect,
         ["Registered parcel P1", "Created request R1", "Assigned resource C1",
          "Request is now in progress", "Parcel status: Collected", "C1 | Counter A | Counter | Available"],
         ["Operation failed", "Not implemented"])

# Reach every remaining menu action, using unknown IDs for safe rejection paths.
parcel_actions = {
    2: "", 3: "UNKNOWN\n", 4: "1\n2\n",
    5: "UNKNOWN\nAlice\nTP001\n012\nCourier\nT\nA\nBox\n",
    6: "UNKNOWN\n", 7: "", 8: "UNKNOWN\n1\n", 9: "UNKNOWN\n1\n2\n"
}
service_actions = {
    1: "UNKNOWN\nTP001\nCollect\n1\n2\n", 2: "", 3: "", 4: "UNKNOWN\n",
    5: "UNKNOWN\n1\nDone\nTP001\n", 6: "UNKNOWN\n", 7: "UNKNOWN\n",
    8: "UNKNOWN\n", 9: "UNKNOWN\n1\n"
}
resource_actions = {
    1: "C1\nCounter A\n1\n", 2: "", 3: "UNKNOWN\n1\n",
    4: "UNKNOWN\n", 5: "UNKNOWN\n3\n", 6: "UNKNOWN\nNew name\n"
}
for menu, actions in enumerate((parcel_actions, service_actions, resource_actions), 1):
    for action, prompts in actions.items():
        run_case(f"menu {menu} action {action}", f"{menu}\n{action}\n{prompts}0\n0\n",
                 ["Goodbye."], ["Not implemented"])
print(f"PASS: {checks} console scenarios.")
