# Smart Campus Parcel System - starter skeleton

One C++17 console project for three members. Menus, input parsing, model defaults,
module wiring and safe destructors are implemented. Data-structure algorithms and
business operations are deliberately unimplemented. Each stub prints
`Not implemented yet` and returns false/null where applicable. Nothing is saved.
This is a learning scaffold, not a completed assignment submission.

## Build and run

From this directory in PowerShell, with GCC on PATH:

```powershell
New-Item -ItemType Directory -Force build | Out-Null
g++ -std=c++17 -Wall -Wextra -Wpedantic -I include src/main.cpp src/task1.cpp src/task2.cpp src/task3.cpp -o build/parcel_system.exe
./build/parcel_system.exe
```

Or with CMake 3.16+ and an installed compiler:

```powershell
cmake -S . -B build
cmake --build build
```

The executable is `build/parcel_system.exe` with a single-configuration generator,
or commonly `build/Debug/parcel_system.exe` with Visual Studio.

## Member responsibilities

| Member | Files | Implementation work |
| --- | --- | --- |
| 1 (you) | `include/task1.hpp`, `src/task1.cpp` | Parcel linked list, intake FIFO queue, registration, lookup, routing and updates |
| 2 | `include/task2.hpp`, `src/task2.cpp` | Linked priority queue, service requests, priorities and request lifecycle |
| 3 | `include/task3.hpp`, `src/task3.cpp` | Circular resource list, round-robin allocation and resource lifecycle |

Shared models are in `include/models.hpp`; menus are in `src/main.cpp`.
Search for `TODO` and `notImplemented` to locate unfinished work. Add parameter
names to stub definitions when implementing them. No STL containers substitute
for the assignment's required structures. Copying owning structures is disabled.

## Contracts to implement together

- Task 1 owns all parcel records. Intake queue nodes contain IDs, not copies of
  parcels. Generate parcel IDs and arrival timestamps on registration; reject
  invalid details and duplicate tracking registrations. Display details and status.
- Process FIFO intake by peeking first. Collection, delivery, special handling and
  return routes create corresponding Task 2 requests; investigation puts the parcel
  on hold. Only dequeue after routing succeeds. Keep the parcel record afterwards.
- `updateParcel` edits descriptive fields while preserving stored ID, arrival time
  and current status; use `updateStatus` for validated lifecycle transitions.
  Completed parcels cannot re-enter intake. Reject updates that break an active
  request; coordinate lifecycle transitions with Task 2.
- Remove only cancelled parcels without active requests. Remove their waiting ID
  too, or skip cancelled/missing/stale entries safely during processing.
- Task 2 owns requests. Generate request IDs, timestamps and increasing sequence
  numbers. Sort urgent before normal and equal priorities by creation sequence.
  Only one active request per parcel. `nextPending` skips other statuses.
- Keep terminal requests until explicit removal; exclude them from active views.
  Completing, returning or cancelling updates the associated parcel and releases
  its resource. Reject repeated terminal operations. Returned parcels get Returned;
  completed collection/delivery get Collected/Delivered. Special handling completion
  places the parcel OnHold for the next staff decision. Cancellation sets Cancelled.
- Task 3 owns resources. Allocate available counters for collection and available
  delivery personnel for delivery/redelivery. Special handling and returns require
  a team-defined resource policy before enabling allocation; their allocation
  currently remains a TODO alongside all other business logic.
- Assignment must update both the resource and request. Validate all changes before
  committing; roll back if any dependent change fails. If an occupied resource goes
  unavailable, clear both assignment references and put its request back to Pending.
  Manual release of an active assignment likewise returns the request to Pending;
  releasing after completion must preserve its terminal status. An unassigned
  terminal request needs no release; invalid request/resource IDs still fail.
- Borrowed pointers from lookup methods are for immediate inspection only. Do not
  retain them across deletion. Keep IDs for long-lived cross-module references.
- Empty collections, unknown IDs and invalid operations must produce clear messages
  once implemented. The current stubs only announce their unimplemented state.

## Suggested implementation order

1. Implement each member's structure operations, including empty and one-node cases.
2. Implement Task 1 registration/search and Task 2 request creation/priority handling.
3. Implement Task 3 registration/allocation and the shared assignment hooks.
4. Connect routing, completion, cancellation and resource release; then expand menus
   or displays if your implementation needs additional information.

## Manual verification checklist

Already applicable to this scaffold:

- Build with warnings enabled; open each task menu and return to the main menu.
- Enter blank, alphabetic, out-of-range and mixed input such as `1x`; retry cleanly.
- Reach an operation and confirm it reports `Not implemented yet`, without claiming success.
- End console input at any prompt; exit cleanly without an infinite loop.

After implementing algorithms and business rules:

- Register parcels A/B/C, process in FIFO order and retain all records afterwards.
- Reject incomplete recipients, duplicate IDs/tracking registrations and unknown IDs.
- Test queue/list removal at head, middle, tail and the only node; empty operations fail safely.
- Prioritize an urgent request ahead of normal requests; equal priorities remain FIFO.
- Reject duplicate active requests, illegal status transitions and repeated completion.
- Allocate only matching available resources; rotate fairly and stop after one full
  ring if none are suitable. Test empty and one-resource rings.
- Test unavailable resources, duplicate assignments, invalid release and interruption
  of an in-progress assignment. Both sides must stay consistent.
- Run registration -> routing -> request -> assignment -> processing -> completion.
  Verify parcel/request statuses and resource availability at every stage.
- Exercise cancellation, return, missing/on-hold parcels and failed dependent updates.
  No failed operation may leave partial state changes.

Tasks 4 and 5, file persistence and authentication are outside this scaffold.
