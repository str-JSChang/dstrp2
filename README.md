# Smart Campus Parcel System

Integrated C++17 console prototype for Tasks 1, 2 and 3 of the three-member assignment.
It uses manually implemented linked structures and coordinated status updates.
Data lives in memory until the program exits.

## Build, test and run

In PowerShell, from this folder:

```powershell
./build.ps1 -Test
./build/parcel_system.exe
```

Requirements: GCC supporting C++17 on PATH; Python 3 for the console tests.
The script builds with `-Wall -Wextra -Wpedantic -Werror` and stops on failed builds
or tests. To build only the application, run `./build.ps1`.

Alternative CMake configuration (CMake 3.16+, a C++ compiler):

```powershell
cmake -S . -B build-cmake
cmake --build build-cmake
Push-Location build-cmake
ctest --output-on-failure
Pop-Location
```

For Visual Studio generators use `cmake --build build-cmake --config Debug` and
`ctest -C Debug --output-on-failure` from the build directory. The application then
resides in `build-cmake/Debug/parcel_system.exe`. Python console tests register in
CTest when Python is found. C++ tests register when BUILD_TESTING is enabled.
The GCC/PowerShell route was tested here; CMake was not installed on this machine.

## Work division

| Member | Source | Structures |
| --- | --- | --- |
| 1 | `src/task1.cpp`, `include/task1.hpp` | Parcel linked list and ID-only FIFO intake queue |
| 2 | `src/task2.cpp`, `include/task2.hpp` | Sorted linked priority queue for service requests |
| 3 | `src/task3.cpp`, `include/task3.hpp` | Circular resource list with separate per-type allocation cursors |

`include/models.hpp` defines shared records, statuses and printing/time helpers.
`src/main.cpp` supplies menus and connects the modules.

## Presentation and code explanations

For your own Task 1 demonstration, use [the Task 1 rehearsal guide](docs/TASK1_PRESENTATION_GUIDE.md).
It gives exact code locations, mock data, a five-minute script, validation scenarios
and logical questions with suggested answers.

Read [the technical and presentation guide](docs/TECHNICAL_GUIDE.md) first for each
task's requirements, algorithms, complexity, integration rules, timed demonstration,
Q&A preparation, regression findings and limits.

[The line-by-line index](docs/LINE_BY_LINE.md) links to explanations of every physical
line in the application, headers, tests and build scripts. Source checksums identify
the exact version explained.

## Quick demonstration

1. Register a parcel in Task 1; its generated ID starts at P1.
2. Process the next parcel for collection with normal priority; R1 is created.
3. Register counter C1 in Task 3, then assign R1 to a counter.
4. Process R1 in Task 2, then complete with outcome details and its recipient ID.
5. Search P1 and display resources: P1 is Collected and C1 is Available.

For active requests with missing/held parcels use Task 2 option 9. It closes the
current request, releases its resource and marks the parcel Missing/OnHold. Recover
a missing parcel to OnHold in Task 1 before resuming a service. Delivered parcels
cannot reopen for redelivery; redelivery applies only to unfinished parcels.

## Verification and limits

- 543 C++ checks across eight suites, including 100 object-lifetime cycles.
- 28 subprocess console scenarios, including a complete collection workflow.
- GCC warnings treated as errors, with additional `-fanalyzer` review.
- Regressions cover direct request synchronization, unchanged state on rejected
  completion, return-to-sender status and rejecting redelivery of delivered parcels.

Tests establish covered behavior, not a guarantee of zero defects. No runtime
address/leak sanitizer was run. There is no persistence, staff authentication,
network service or optional Tasks 4 and 5. Recipient-ID matching is a prototype
collection check, not secure identity verification.

The source follows `dsa_assignment` conventions: include guards, `using namespace std;`,
camelCase names, four spaces, same-line opening braces, short comments and explicit
pointer traversal. The readability revision expands branches and validation, uses
explicit types and replaces nested conditional expressions with if/else blocks. The reference directory is unchanged. Understand your contribution
and follow the assignment's individual AI-usage declaration requirements.
