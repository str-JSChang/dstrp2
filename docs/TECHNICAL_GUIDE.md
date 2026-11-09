# Technical explanation and presentation guide

## 1. System and source map

Member 1 owns parcel records and intake order. Member 2 owns service requests.
Member 3 owns counters and delivery personnel. The console connects the same three
module objects, so completing a request changes the real parcel and frees its
resource immediately. The three-member rule makes Tasks 1-3 the required member
responsibilities. Optional Tasks 4-5, persistence and staff authentication are excluded.

| Area | Files | Purpose |
| --- | --- | --- |
| Shared vocabulary | `include/models.hpp` | Common records, enums, printing, trimming and time helpers |
| Parcel intake | `include/task1.hpp`, `src/task1.cpp` | Parcel list and FIFO intake queue |
| Service work | `include/task2.hpp`, `src/task2.cpp` | Priority queue and request lifecycle |
| Allocation | `include/task3.hpp`, `src/task3.cpp` | Circular resource list and per-type round robin |
| Console | `src/main.cpp` | Input, menus and module wiring |
| Verification | `tests/system_tests.cpp`, `tests/test_console.py` | State assertions and real console workflows |
| Build | `CMakeLists.txt`, `build.ps1` | Warning-enabled compilation and test commands |

The [line-by-line index](LINE_BY_LINE.md) links to every source line's explanation,
including declarations, comments, braces and blanks. Use this guide for the overall
reasoning and those companions for statement-by-statement study.

## 2. C++ concepts used throughout

- `using namespace std;` permits `string`, `cout` and `getline` without `std::`, as
  requested. Header-wide imports follow the reference, although larger libraries
  commonly avoid them to reduce name clashes. `namespace campus` groups our own types.
- Include guards prevent repeated type definitions within one translation unit.
- A `struct` groups fields; a `class` combines operations and private storage.
  `enum class` gives statuses and types named values, avoiding accidental mixing.
- `Node*` stores a node address. `nullptr` means no node. `->` accesses a field
  through its pointer. `&current->value` returns a pointer to a stored record.
- `const Parcel*` allows inspection without modification. Returned pointers are
  borrowed, so do not retain them after the corresponding node is deleted.
- `const string&` avoids copying an input. A by-value `Parcel parcel` is intentionally
  copied so normalization cannot mutate the caller's original object.
- Constructors initialize objects; destructors free every owned node. Owning classes
  delete their copy constructor/assignment to prevent shallow copying and double deletion.
- A reference member such as `ParcelModule& parcels` refers to one existing module.
  In `parcels(parcels)`, the left name is the member and the right name is the parameter.
- `friend class` allows a cooperating module to perform coordinated lifecycle changes.
  It is deliberate coupling, not a security boundary or method-level access control.
  Assignment hooks are private, preventing ordinary console code from forging links.
- `new` creates a node; `delete` frees it. Save the next address before deletion.
  Reading `head->next` after deleting head would be a use-after-free error.
- `swap` exchanges already-prepared values. Completion prepares outcome text before
  mutation, then swaps it into the request without allocating another string.

## 3. Shared records, policies and invariants

A `Parcel` stores its ID, recipient name/ID/contact, carrier, tracking number,
destination, type, arrival time and status. A `ServiceRequest` stores its own ID,
Parcel ID, service, priority, creation sequence/time, recipient, assignment and outcome.
A `Resource` stores ID, name, type, status and assigned Request ID. Empty assignment
strings mean no active assignment. Cross-module references use IDs, not record copies.

Parcel/request IDs are generated as P1/P2 and R1/R2. They restart each process because
there is no persistence. Resource IDs are entered by staff and checked for uniqueness.
Caller-supplied parcel/request IDs are replaced during registration. Stored tracking
numbers must be unique. Comparisons are case-sensitive. `trim` removes outside spaces,
tabs and line endings; it does not remove spaces inside names. Recipient and contact
validation requires nonblank fields; the brief does not specify institutional ID or
telephone formats, so the prototype does not claim to validate those formats.

### Invariants

1. The parcel list owns parcel data; intake holds only waiting IDs.
2. Each parcel has at most one active service request.
3. Active requests have matching parcel recipient IDs and expected service statuses.
4. Assigned/InProgress requests reference Occupied resources of the correct type.
   The resource points back to the same Request ID. Pending requests are unassigned.
5. Completed/Cancelled/Returned requests are inactive and unassigned.
6. Collected/Delivered/Returned/Cancelled parcels are terminal and cannot reopen.
7. Rejected normal business operations preserve the existing parcel, request and
   assignment. A failed allocation cannot occupy a resource.

This is a single-threaded application-level consistency design. It is not a database
transaction, distributed lock or concurrent scheduler.

### Service policy

| Service | Active parcel status | Resource | Completed outcome |
| --- | --- | --- | --- |
| Collection | AwaitingCollection | Counter | Collected / request Completed |
| CampusDelivery | AwaitingDelivery | Delivery personnel | Delivered / request Completed |
| Redelivery | AwaitingDelivery | Delivery personnel | Delivered / request Completed |
| SpecialHandling | SpecialHandling | Delivery personnel | OnHold / request Completed |
| ReturnToSender | ReturnPending | Delivery personnel | Returned / request Returned |

An explicit Returned outcome ends a valid in-progress service as Returned.
ReturnToSender always produces Returned, even when the menu outcome is Completed.
SpecialHandling leaves OnHold for the next staff decision. These are documented
team rules, not policies dictated by the assignment.

Redelivery is another attempt on an unfinished parcel. Interrupt a delivery to OnHold,
then create Redelivery. A Delivered parcel cannot reopen. Recover a Missing parcel
to OnHold before creating or resuming a service.

## 4. Task 1 - intake, sorting and processing

### Requirements and code

| Requirement | Implementation |
| --- | --- |
| Register | `registerParcel` validates/normalizes details, rejects duplicate tracking, generates ID/time and enqueues the ID. |
| Maintain/locate | `ParcelRecords` owns records; lookup/display functions expose relevant details and status. |
| Sort/process | `processNext` selects FIFO intake and maps a route to Task 2; investigation instead holds the parcel. |
| Update/remove | Edits preserve identity/time/status; active/terminal edits fail; deletion requires Cancelled and no active request. |
| Exceptions | Empty intake, duplicates, invalid recipient details/routes, unknown IDs and completed parcels are handled. |

### Why a list and a queue?

The singly linked list retains current parcel records. Each node contains a Parcel
and next pointer. The FIFO queue contains only waiting Parcel IDs and has front/rear
pointers. Leaving intake must not destroy the parcel: requests still need its details.

Record insertion is at the head, so record display is newest-inserted first. Intake
processing is separately FIFO. ID lookup follows next until matching or nullptr.
Duplicate tracking is checked by one direct traversal, replacing the ZIP's repeated
generated-ID searches, which could take quadratic time.

### Registration algorithm

1. Trim required fields and reject incomplete data.
2. Traverse records once to reject duplicate tracking.
3. Prepare the next P-number, local timestamp and Received status.
4. Insert the parcel node, then enqueue its ID.
5. If queue allocation throws, remove the inserted record and rethrow.
6. Increment the ID counter after both insertions succeed.

Unexpected runtime exceptions reach main and stop the process with an error message.
This prototype does not attempt recovery after memory exhaustion or counter exhaustion.

### Queue and deletion pointer cases

Enqueue allocates a node with next == nullptr. Empty queue: front and rear both point
to the new node. Nonempty queue: connect the old rear, then advance rear. Dequeue
copies the front ID, advances front and deletes the old node. Removing the final node
must reset rear to nullptr. `remove(id)` also handles arbitrary head/middle/tail/only
removal; removing the tail changes rear to previous.

Record deletion keeps previous/current pointers. At the head, replace head with
current->next. Otherwise bypass current through previous->next. Delete only after
rewiring. Missing IDs return false without changing links.

### Routing and editing

`processNext` validates route/priority, skips stale non-Received waiting entries and
handles the earliest valid parcel. Task 2 creates a service request, then changes
parcel status and removes the waiting ID after insertion succeeds. Investigation
marks OnHold and removes the waiting entry without creating a request. Resume requires
OnHold; Missing must first be explicitly recovered to OnHold.

Edits are blocked during active work because recipient/destination/handling changes
could invalidate the linked request. The replacement retains saved ID, arrival time
and status before swapping into place. Staff status updates only allow Missing,
OnHold or Cancelled without active work. Active exceptions use Task 2 interruption.

### Complexity

P = parcel records, Q = waiting IDs, R = retained requests. String lengths are treated
as bounded; copying/comparing variable strings adds their character costs. Space is O(P+Q).

| Operation | Time |
| --- | --- |
| Record search / duplicate tracking / removal | O(P) |
| Record insert with duplicate-ID check | O(P); pointer linking alone is O(1) |
| FIFO enqueue/dequeue/peek | O(1) |
| Arbitrary waiting-ID removal | O(Q) |
| Registration | O(P) |
| Edit details | O(P+R) |
| Remove cancelled parcel | O(P+R+Q) |
| Normal FIFO service routing | O(P+R); removal is O(1) when the waiting ID is front |
| Routing with many stale IDs | O(Q*P+R) conservative worst case |

A linked list avoids fixed capacity but does not give constant-time arbitrary lookup.
An extra index could improve lookup at the cost of more structures and synchronization.

### Member 1: five-minute demonstration

- 0:00-0:45: Explain record ownership versus temporary intake membership.
- 0:45-1:45: Register two parcels, show newest-first record display versus FIFO waiting order;
  reject duplicate tracking.
- 1:45-2:45: Search and route P1, then show its record remains searchable.
- 2:45-3:45: Trace enqueue/dequeue, especially resetting rear after the last node.
- 3:45-4:30: Explain O(P) search and single-pass duplicate detection.
- 4:30-5:00: Show an empty/held case and state a limitation.

Explain in your own words: "The list owns the record. The queue only holds its ID
while it waits. Processing changes its stage, not whether its record exists."

## 5. Task 2 - service and collection management

### Requirements and code

| Requirement | Implementation |
| --- | --- |
| Create | Validate parcel/recipient/details/type/priority and active duplicates; generate ID/time/sequence. |
| Active work | Linked RequestQueue; display filters Pending/Assigned/InProgress. |
| Decide next | Sorted priority insertion and first-Pending lookup. |
| Process/update | Assign -> process -> verify recipient -> complete/return; cancellation/interruption release resources. |
| Exceptions | Unknown IDs, wrong recipient, ties, duplicates, missing parcels and repeated/invalid operations fail. |

### Priority insertion

Urgent precedes Normal in the enum, so its value compares smaller. Sequence increases
for successful creation. Traverse while existing nodes have earlier priority or the
same priority and an earlier/equal sequence. Insert before the first later node.
Equal sequences remain stable at the structure level; the module generates unique ones.

Terminal requests remain until explicit removal so staff can inspect them and repeated
processing can be rejected. Therefore nextPending is O(R), not necessarily O(1).
It may skip assigned and terminal nodes. The first Pending request is recommended;
staff can explicitly choose another ID to avoid blocking all other work behind a
resource type that is unavailable. Priority is a recommendation, not a hard scheduler.

### Request states

`Pending -> Assigned -> InProgress -> Completed/Returned`

Any active stage can be cancelled. Manual resource release or an unavailable resource
returns its request to Pending with the same original sequence/priority. Interruption
for Missing/OnHold closes only the current request as Cancelled, with an explanatory
outcome, and marks the parcel Missing/OnHold. It preserves a recovery route. Full
cancellation instead makes the parcel terminal Cancelled.

### Four ZIP regressions corrected

| Observed defect | Corrected behavior |
| --- | --- |
| Direct request leaves parcel Received | Successful creation sets serviceStatus(type) and removes waiting membership. |
| Completion releases resource before rejecting parcel update | Validate request, identity, details, parcel and assignment before release. |
| Completed return service becomes OnHold | ReturnToSender always ends parcel and request as Returned. |
| Delivered accepts an unusable redelivery | Reject all terminal parcels at request creation, including Delivered. |

### Completion algorithm

1. Find request; require InProgress and Completed/Returned outcome.
2. Prepare trimmed outcome text; require entered recipient ID to match.
3. Check parcel existence, expected service status and matching recipient.
4. Check resource existence, Occupied state, compatibility and reverse Request ID.
5. Determine final statuses before any change.
6. Release the validated resource and clear both assignment references.
7. Set final statuses and swap in the prepared outcome string.

Wrong identity, blank outcome, invalid state or inconsistent assignment fails before
release. No allocation is required after release begins. Private resource/service
hooks limit assignment changes to cooperating modules. No const_cast is used.

Cancellation and interruption use the same validation-before-mutation pattern.
Terminal removal rejects active/assigned records. This retained request list is not
the optional Task 4 audit history; explicitly deleted requests are no longer searchable.

### Complexity

R includes retained terminal requests; S = resources. Space is O(R).

| Operation | Time |
| --- | --- |
| Insert/find/next Pending/remove/display | O(R) |
| Create including parcel validation and queue removal | O(P+R+Q) |
| Process | O(P+R) |
| Complete/cancel/interrupt | O(P+R+S) |

These operations make a constant number of traversals, not nested full scans. Retaining
terminal records improves inspection but increases future traversal lengths.

### Member 2: five-minute demonstration

- 0:00-0:45: Explain Parcel ID links and request lifecycle.
- 0:45-1:45: Create normal then urgent work; show next-request ordering.
- 1:45-2:30: Trace sorted insertion and sequence-based FIFO ties.
- 2:30-3:30: Process assigned work; reject the wrong recipient and show unchanged assignment.
- 3:30-4:15: Complete correctly; show parcel and resource updates.
- 4:15-5:00: Explain validate-before-release and why nextPending is O(R).

Explain in your own words: "A rejected completion must not change the assignment.
I check all three records before releasing the resource or changing final status."

## 6. Task 3 - counters and delivery resources

### Requirements and code

| Requirement | Implementation |
| --- | --- |
| Register/maintain | Unique ID, nonblank name, valid type; name edits separate from assignment. |
| Availability | Display type/status/current Request ID. |
| Assign | Validate request and parcel, choose suitable Available node, update both sides. |
| Update/release | Assignment creates Occupied; release/unavailability detaches request. |
| Exceptions | Empty/busy/incompatible/unavailable resources, duplicate assignments and invalid releases fail safely. |

### Circular representation

tail->next is the first node. Empty means tail == nullptr; a one-node ring points
to itself. Lookup/display visit at least one node with do/while, stopping when they
return to the start. A valid nonempty ring has no nullptr end marker.

Empty insertion self-links the new node and initializes both allocation cursors.
Nonempty insertion connects the new node between tail and first, then advances tail.
Duplicate checking makes complete insertion O(S), although splicing alone is O(1).

### Per-type round robin

The two-element built-in pointer array is selection bookkeeping, not resource storage.
Resources stay in the circular linked list. Index 0 tracks counters, index 1 delivery
personnel. From that type's cursor, inspect at most one full cycle. Skip wrong type,
Occupied and Unavailable nodes. On success save the successor as the next starting
position and return the resource. Failure leaves that cursor unchanged.

In a ring C1 -> C2 -> D1 -> C1, one shared cursor can repeatedly select C1 if each
counter request is followed by a D1 allocation. Separate cursors preserve progress
toward C2 despite intervening delivery selections. The tests include this case.
Fairness applies to eligible Available resources of the selected type, not to waiting
time across urgent/normal requests or arbitrary staff overrides.

### Assignment, release and cleanup

Assignment checks Pending/unassigned status, matching parcel state and resource type.
It prepares the Request ID string, selects a resource, uses the private attachment
hook, swaps the prepared Request ID into the resource and sets Occupied. Failure
from wrong type/no capacity changes no assignment. Staff cannot directly mark an
unassigned resource Occupied.

canReleaseRequest checks both directions of the link. Pending unassigned requests
need no physical release, enabling cancellation before allocation. releaseForRequest
detaches Assigned/InProgress work and resets the resource to Available. Completion
then immediately sets the request terminal. Manual release leaves Pending instead.
An occupied resource becoming Unavailable first releases safely, then changes status.

Destruction breaks tail->next to nullptr, turning the ring into a linear chain, then
deletes each node once. Empty, single-node and multi-node rings are all supported.

### Complexity

S resources use O(S) space; two cursors use O(1).

| Operation | Time |
| --- | --- |
| Register including uniqueness | O(S) |
| Lookup/select/display/destructor | O(S) |
| Assignment with request/parcel checks | O(S+R+P) |
| Release/status update | O(S+R) |

The ring is appropriate for repeated allocation but cannot promise O(1) selection
or fairness between service requests of different priorities.

### Member 3: five-minute demonstration

- 0:00-0:45: Explain resource states and circular links.
- 0:45-1:45: Register two counters and a driver; show type compatibility.
- 1:45-2:45: Alternate allocations between counters and explain independent cursors.
- 2:45-3:30: Reject an incompatible type or all-busy allocation.
- 3:30-4:15: Make an occupied resource unavailable; show its request becomes Pending.
- 4:15-5:00: Trace the bounded scan and ring destruction; explain O(S).

Explain in your own words: "The cursor remembers the next search position. A full
unsuccessful cycle returns, so an all-busy ring cannot loop forever."

## 7. Concrete integrated demonstration

1. Run `./build.ps1 -Test`, then `./build/parcel_system.exe`.
2. Register Alice / TP001 / 0123456789 / Campus Courier / TRACK1 / Block A / Box.
   Expect P1 Received. Add TRACK2 to demonstrate FIFO.
3. Process next for Collection/Normal. Expect R1 Pending and P1 AwaitingCollection.
   P2 stays Received and becomes the front waiting ID.
4. Register C1 / Counter A / CollectionCounter, then assign R1 to a counter.
   Expect C1 Occupied/R1 and R1 Assigned/C1.
5. Process R1. Attempt completion with details but recipient WRONG. It must fail
   without freeing C1. Retry with TP001: P1 Collected, R1 Completed, C1 Available.
6. Attempt to process R1 again; it fails. Show direct Task 2 creation works for a
   different parcel. Show a return service finishes Returned even when choosing Completed.
7. Interrupt another active delivery as Missing. Its request closes and resource frees.
   Recover the parcel to OnHold before resuming or creating redelivery.

Do not reuse terminal P1 for redelivery. Explain the lifecycle rule instead of
changing state merely to force a demo through.

## 8. Verification and limits

The C++ runner uses check() rather than assert(), so release builds retain checks.
Eight suites cover node boundaries, parcel validation, every service type, rejected
completion invariants, interruption/recovery, cancellation, priority/allocation and
invalid operations. There are 543 checks including 100 repeated lifetimes destroying
nonempty structures. This is not a runtime memory/leak proof.

The Python runner executes the real binary with input scripts and a five-second
timeout. Twenty-eight scenarios cover menus, malformed/overflow input, EOF, remaining
menu actions and a full collection workflow. Successful integration requires expected
states and rejects failure/stub output. Unknown-ID navigation checks clean exit;
deeper business assertions are in C++.

GCC builds use warnings and -Werror. An additional -fanalyzer build performs static
path checks. No runtime address/leak sanitizer was run. CMake is provided but was
not installed here; the direct GCC/PowerShell build is the verified path.

IDs are case-sensitive; names can contain spaces. No persistence means no saved data
or permanent tracking duplicate archive after deletion. There is no staff login,
concurrent resource locking or storage recovery. Recipient-ID comparison is a prototype
check, not secure identity verification. No large-scale benchmark was performed.

Deleting a cancelled parcel can leave an inactive terminal request with its former
Parcel ID as historical text. It cannot be processed. Explicitly remove that terminal
request too if both records should be gone. Task 4 would provide richer retained history.

## 9. Likely questions

**Why not std containers?** The brief requires manual structures; nodes and links
are implemented explicitly. Strings/streams are library utilities, not substitute containers.

**Why two Task 1 structures?** Waiting membership ends before the parcel record's
usefulness ends. A queue alone would discard searchable data too early.

**What if priorities tie?** Sequence preserves creation order; timestamps are displayed
but are not used for tie-breaking because two requests can share the same second.

**Can normal work starve?** Yes, continual urgent arrivals can precede it. There is
no aging mechanism. Staff may explicitly select another request when necessary.

**Why O(R) insertion and nextPending?** Insertion searches for position; Pending lookup
may skip retained assigned/terminal nodes. No hidden heap or index is used.

**What if all resources are busy?** A full bounded cycle returns nullptr, leaving the
request Pending and all assignments unchanged.

**Why two cursors?** Driver allocations must not reset counter rotation, and vice versa.

**Main technical challenge?** Keeping parcel/request/resource state consistent. The
ZIP released too early; the fix validates the whole operation before mutation.

**Why explicit missing recovery?** Staff confirm recovery by moving Missing to OnHold;
the system must not silently start delivery of a parcel still reported missing.

**How is deletion safe?** Save the successor first; ring destruction breaks the cycle;
owning structures cannot be shallow-copied.

**Does testing guarantee an A+ or zero mistakes?** No. Tests establish covered behavior.
Marks depend on the rubric and each member's ability to trace, justify and modify code.

## 10. Reading the expanded syntax

The readability revision keeps the same data structures, lifecycle rules and
asymptotic complexity. It uses braces for branches, explicit types instead of auto,
and separate checks with specific messages. Display labels and menu enum values
are selected through ordinary if/else blocks rather than conditional expressions.

The shared readPriority helper reads a choice, returns false on Cancel/EOF, and
writes the selected RequestPriority through its reference argument on success.
Its callers check that result before using the priority. Investigation holds do
not ask for a priority because they do not create service requests.

A lookup now declares its result first, then checks it separately:

```cpp
const Parcel* parcel = parcels.findParcel(id);
if (parcel != nullptr) {
    printParcel(*parcel);
}
```

Node allocation intentionally retains initialization of the stored data:

```cpp
Node* node = new Node{parcel};
node->next = head;
head = node;
```

The braces after Node initialize the node's Parcel value during allocation. If
copying a parcel string throws, C++ releases that new allocation automatically.
The next pointer starts with its in-class nullptr default; the following line
explicitly connects it to the old head. Allocating an empty node and assigning
its record afterwards would need an extra exception handler to avoid a leak.
The initializer is a small piece of syntax worth understanding rather than removing.

Destructors, const references, scoped enums, deleted copying and private integration
hooks remain because they protect ownership and consistency. The longer formatting
makes execution order visible; it does not remove validation or change FIFO,
priority ordering, per-type round robin or the validate-before-release rule.

## 11. Preparation

Read your header and implementation together. Draw three-node examples; trace
head/front/rear/cursor changes. Practice one successful path and one rejection.
Use the line companions to resolve unfamiliar syntax. Explain the actual validation
costs rather than claiming ideal O(1) operations that the complete code does not offer.
Follow the brief's individual AI-usage declaration requirements. These notes support
understanding and do not replace your individual contribution.
