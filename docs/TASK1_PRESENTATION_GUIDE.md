# Task 1 presentation and rehearsal guide

Your part is **Parcel Intake, Sorting and Processing**. Present how parcels enter
the system, remain searchable, leave the intake queue and hand over to service
management. Keep Task 2 scheduling and Task 3 allocation as integration context;
their detailed implementations belong to your teammates.

The main demonstration and the hold/missing-recovery sequence below were rehearsed
against the current executable. Other cases are a preparation checklist: distinguish
menu demonstrations, low-level structure checks and code-inspection explanations.

## 1. What to open, and in which order

Use Ctrl+G in your editor to jump to the listed line. These numbers describe the
source at the time of writing; use the function names if you later edit the code.

| Order | File and lines | What to explain |
| --- | --- | --- |
| 1 | `include/models.hpp`, 26-38 | Parcel fields: identity, recipient, delivery details, arrival time and status. |
| 2 | `include/task1.hpp`, 11-30 | ParcelRecords owns a singly linked list containing complete parcels. |
| 3 | `include/task1.hpp`, 32-53 | IntakeQueue owns a second linked structure containing only waiting IDs; front/rear preserve FIFO. |
| 4 | `include/task1.hpp`, 55-74 | ParcelModule connects the list, queue, ID counter and service handoff. |
| 5 | `src/task1.cpp`, 206-231 | registerParcel: validate, check duplicate tracking, assign ID/time, store and enqueue. |
| 6 | `src/task1.cpp`, 137-164 | enqueue/dequeue: trace empty, nonempty and last-node cases. |
| 7 | `src/task1.cpp`, 293-324 | processNext: choose the oldest eligible parcel and route it. |
| 8 | `src/task2.cpp`, 112-172 | Integration only: createRequest validates/inserts work, updates the parcel and removes its waiting ID. |

Do not scroll through every line during the five-minute presentation. Show the
record/queue definitions, registration and routing first. Open the following
sections when asked about a particular behavior:

| Topic | Location |
| --- | --- |
| Required-field validation | `src/task1.cpp`, 8-38, prepareParcel |
| Route mapping | `src/task1.cpp`, 40-51, routeService |
| Insert a record | `src/task1.cpp`, 62-70, ParcelRecords::insert |
| Find a record | `src/task1.cpp`, 72-88, find overloads |
| Duplicate tracking | `src/task1.cpp`, 90-97, hasTrackingNumber |
| Delete a record | `src/task1.cpp`, 99-117, ParcelRecords::remove |
| Display records | `src/task1.cpp`, 119-126, ParcelRecords::display |
| Peek at intake | `src/task1.cpp`, 166-172, IntakeQueue::peek |
| Remove a waiting ID | `src/task1.cpp`, 174-195, IntakeQueue::remove |
| Edit details | `src/task1.cpp`, 245-273, updateParcel |
| Delete a cancelled parcel | `src/task1.cpp`, 275-291, removeParcel |
| Resume a held parcel | `src/task1.cpp`, 326-348, resumeParcel |
| Missing/hold/cancel status | `src/task1.cpp`, 350-374, updateStatus |
| Cleanup | `src/task1.cpp`, 54-60 and 128-135, destructors |
| Task 1 console calls | `src/main.cpp`, 86-190, parcelMenu |
| Trimming and arrival time | `include/models.hpp`, 62-82 |

The two lookup overloads differ in whether callers may modify the returned parcel.
The queue's dequeue operation is useful for explaining FIFO and stale-entry cleanup.
Successful service routing currently removes the selected waiting ID through
IntakeQueue::remove inside Task 2; do not claim processNext directly dequeues every
successful route.

## 2. Mock data and setup

Start a new process for a clean demonstration. Existing data disappears on exit,
and generated IDs restart. If teammates have already added data in the same process,
use the IDs actually printed rather than assuming P1/R1.

```powershell
cd C:\DSTR-P2\dstrp2
.\build\parcel_system.exe
```

Use these two parcels, entered in this order:

| Field, in prompt order | Parcel A -> P1 | Parcel B -> P2 |
| --- | --- | --- |
| Recipient name | Ali | Mei |
| Recipient student/staff ID | TP001 | TP002 |
| Recipient contact | 0123456789 | 0123456789 |
| Delivery company | Campus Courier | Campus Courier |
| Tracking number | TRK001 | TRK002 |
| Campus destination | Block A | Block B |
| Parcel type | Box | Box |

IDs, arrival times and initial Received status are generated, not entered. For the
edit example, keep all P2 details the same except change Block B to **Block C**.
The current edit screen asks for every descriptive field again; it is not a
single-field edit form. For a duplicate attempt, repeat Parcel A's details and TRK001.

Keep these seven-line blocks available to avoid typing mistakes. Select Register
first, then enter or paste the relevant block into the program's input:

```text
Ali
TP001
0123456789
Campus Courier
TRK001
Block A
Box
```

```text
Mei
TP002
0123456789
Campus Courier
TRK002
Block B
Box
```

Use short data consistently. TP001 is the recipient identifier, TRK001 the carrier
tracking number, P1 the generated parcel identifier, and R1 a separate service ID.

## 3. Five-minute presentation: from opening to handoff

### 0:00-0:25 — Introduce your responsibility

Say:

> My assigned module handles parcel intake. It registers incoming parcels, keeps
> their records searchable, processes waiting parcels in arrival order, and routes
> them to the next stage. It also handles edits, cancellation, missing parcels and holds.

Point briefly to the Parcel fields. Do not read all fields aloud.

### 0:25-1:10 — Register P1 and P2

Menu path: **Main 1 -> Task 1 option 1**. Enter Parcel A. Choose option 1 again and
enter Parcel B. Remain in the Task 1 menu.

Expected messages include Registered parcel P1 and Registered parcel P2.

Say:

> Staff provide recipient and delivery details. The system checks required fields
> and duplicate tracking, then generates the Parcel ID and arrival time. Successful
> registration stores the full record and adds its ID to the waiting queue.

### 1:10-1:45 — Show the two structures

Choose Task 1 **2: Display parcels**, then **7: Display waiting queue**.

Expected record-display order: **P2, P1**. Expected waiting order: **P1, P2**.

Say:

> The record list inserts at its head, so its display is newest first. Processing
> uses a separate FIFO queue, so P1 is still processed before P2. The list owns the
> parcel data; the queue only stores IDs while those parcels wait.

Draw or point to:

```text
Record list:
head -> [P2: full record] -> [P1: full record] -> nullptr

Intake queue:
front -> [P1] -> [P2] -> nullptr
front points to P1; rear points to P2.
```

### 1:45-2:15 — Search and update

Choose **3: Search parcel**, enter P1. Show its details and Received status.
Choose **5: Update parcel details**, enter P2, then enter all P2 fields with Block C.

Say:

> Search follows the record list until it finds the ID. Editing validates the new
> details but preserves the original ID, arrival time and current status. I edit P2
> before creating an active request, because active work protects those details.

If time is short, skip the live edit and explain its code when asked.

### 2:15-3:00 — Process P1 and show integration

Choose **4: Process next waiting parcel -> route 1: Collection -> priority 2: Normal**.
Expected: Created request R1. Search P1 again and show **Awaiting collection**.
Choose option 7 and show only P2 remains waiting.

Say:

> P1 was the oldest waiting parcel. I selected its next action as collection. My
> module calls service management to create a request. After insertion succeeds,
> that shared operation updates P1 and removes its waiting ID. P1 stays in the
> record list, so staff can still search it. It is awaiting collection, not collected yet.

The data structures do not infer a route from parcel type. Staff choose the route.
FIFO chooses which intake parcel is considered next; request priority applies in Task 2.

### 3:00-3:45 — Show validation and deletion

Choose **1: Register** and repeat Parcel A with TRK001. Expect Duplicate tracking number.
Choose **3: Search**, enter P999. Expect Parcel not found.

For cancellation/deletion, choose **8 -> P2 -> 3: Cancel parcel**. P2 becomes Cancelled.
Choose **6: Remove cancelled parcel -> P2**. Then choose **7**: no parcels are waiting.

Say:

> Duplicate registration and unknown searches fail safely. Removing a record is
> restricted to cancelled parcels without active requests. Cancellation also removes
> the waiting ID so that it cannot be processed later. P1 still exists and R1 remains pending.

Cancellation and removal are different: cancellation preserves a record with a
terminal status; removal deletes its node. Do not cancel P1 here because it has active
work; Task 2 must coordinate that cancellation and any resource release.

### 3:45-5:00 — Explain code and finish your part

Open task1.hpp at the record node and queue node, then task1.cpp at enqueue/registerParcel/processNext.

Say:

> Each list node owns a Parcel and a next pointer. Each queue node has only a Parcel
> ID and next pointer. Front and rear make queue insertion and removal constant-time.
> Record lookup is linear, so registration including duplicate validation is O(P),
> not O(1). During routing, I validate first and create the next-stage request before
> removing the waiting entry. This prevents losing a parcel when routing fails.

Close with:

> My handoff is P1 awaiting collection with request R1 pending. Service processing
> and counter allocation are handled by the other two modules using that same Parcel ID.

For an integrated group demonstration, Main 0 returns from Task 1. Task 2 option 8
can show R1. A teammate can register a counter, allocate R1, process it and complete
it using TP001. You do not need to explain their internal algorithms in your own five minutes.

### Expected state after each stage

| Stage | P1 | P2 | Waiting queue | Requests |
| --- | --- | --- | --- | --- |
| Both registrations | Received | Received | P1, P2 | None |
| P2 edited | Received | Received, destination Block C | P1, P2 | None |
| P1 routed | AwaitingCollection | Received | P2 | R1 Pending for P1 |
| Duplicate/search rejection | Unchanged | Unchanged | P2 | Unchanged |
| P2 cancelled | AwaitingCollection | Cancelled | Empty | R1 Pending |
| P2 removed | AwaitingCollection | No record | Empty | R1 Pending |

## 4. Validation and what-if checklist

Do not attempt every case in five minutes. Practice them separately, restarting
when a case needs fresh IDs. Tests of low-level node methods or invalid enum values
are code/test explanations, not options available through the normal menu.

### Registration and lookup

| Scenario | How to try it | Actual rule/result |
| --- | --- | --- |
| Missing name, recipient ID, contact, carrier, tracking, destination or type | Leave one required prompt blank, fill the others | prepareParcel rejects the registration; no record or queue node is committed. |
| Spaces-only field | Enter several spaces for a required field | trim makes it empty; rejected. |
| Spaces around a valid name | Enter `  Ali  ` | Outside whitespace is removed; stored as Ali. Internal spaces remain. |
| Duplicate tracking | Register TRK001 twice with otherwise valid fields | Second registration is rejected even if the recipient differs. |
| Same recipient with a different tracking number | TP001 receives TRK001 and TRK003 | Allowed; recipients can receive multiple parcels. |
| Duplicate Parcel ID | Explain generated IDs and ParcelRecords::insert | Staff cannot choose one at registration; the list also rejects duplicate IDs directly. |
| Registration fails, then valid registration succeeds | Attempt duplicate tracking before adding a new valid parcel | Failed validation does not consume the next Parcel ID. |
| Unknown Parcel ID | Search P999 | No dereference; reports Parcel not found. |
| Empty record display | New process -> Task 1 option 2 | Reports No parcel records. |
| Lowercase ID | Search p1 when the record is P1 | No match; ID comparisons are case-sensitive. |
| Letters in contact | Enter a nonblank contact such as abc | Currently accepted. It checks presence, not telephone syntax. State this limitation honestly. |
| Unknown university recipient | Enter a nonblank invented recipient ID | Currently accepted at intake. There is no university-directory lookup. |
| Tracking differs only in case | TRK001 versus trk001 | They are distinct under the current exact, case-sensitive comparison. |

### Updating and removing

| Scenario | Setup/action | Actual rule/result |
| --- | --- | --- |
| Edit a missing record | Update P999, supplying full details | Rejected: Parcel not found. |
| Edit incomplete replacement details | Update an existing nonterminal parcel; blank one field | Rejected; saved details remain unchanged. |
| Change tracking to another parcel's tracking | Edit P2's tracking to TRK001 while P1 exists | Rejected as duplicate. |
| Keep its own tracking during an edit | Edit P2's destination but retain TRK002 | Allowed because duplicate search excludes P2 itself. |
| Edit a parcel with an active request | Route P1, then try editing P1 with all valid fields | Rejected; prevents recipient/destination changes from invalidating active work. |
| Edit a terminal parcel | Try editing after Collected, Delivered, Returned or Cancelled | Rejected even if replacement fields are valid. |
| Change ID/time/status through descriptive edit | Inspect updateParcel | It restores saved ID/time/status before swapping the replacement into storage. |
| Remove a Received or OnHold parcel | Task 1 option 6 on it | Rejected: only Cancelled can be removed. |
| Remove a cancelled parcel without active work | Cancel an unrouted parcel, then option 6 | Allowed; cleans waiting membership before deleting the record node. |
| Active request during deletion | Inspect removeParcel's active-request guard | Rejected even if inconsistent internal state somehow marked the parcel Cancelled. Normal menus prevent that inconsistent combination. |
| Search after deletion | Search its old ID | Not found; the deleted node is no longer reachable. |
| Reuse deleted tracking | Remove its cancelled record, then register that tracking again | Allowed if no remaining record uses it; there is no permanent duplicate archive. |

For the active-edit test, enter valid replacement details. Required-field and duplicate
checks occur before the active-work check, so invalid inputs may trigger an earlier
message. Cancelling the whole request makes its parcel terminal; it does not unlock
that parcel for editing. For investigation and a later corrected service, use the
controlled OnHold interruption/recovery route when appropriate.

### Routing, hold, missing and terminal cases

| Scenario | Setup/action | Actual rule/result |
| --- | --- | --- |
| Empty intake | New process -> option 4 -> Collection -> Normal | Reports Intake queue is empty; creates no request. |
| Cancel route selection | At route prompt choose 0 | Returns without processing the head. |
| Cancel priority selection | Choose a service route, then priority 0 | No request/status/queue changes. |
| Collection route | Received parcel -> route 1 | AwaitingCollection; creates Collection request. |
| Campus delivery route | Received parcel -> route 2 | AwaitingDelivery; creates CampusDelivery request. |
| Special-handling route | Received parcel -> route 3 | SpecialHandling; creates corresponding request. |
| Return route | Received parcel -> route 4 | ReturnPending; creates ReturnToSender request. Actual Returned completion is later in Task 2. |
| Investigation route | Received parcel -> route 5 | OnHold; removes waiting ID and creates no service request or priority prompt. |
| Request creation fails | Inspect processNext and createRequest | Valid head remains waiting unless it was already a stale/nonprocessable entry; no successful handoff is claimed. |
| Stale/non-Received waiting ID | Explain processNext's defensive loop | It discards that queue entry and looks for the next eligible Received record. Normal menus generally clean these entries earlier. |
| Report Missing before a request exists | Option 8 -> parcel ID -> 1 | Marks Missing and removes waiting membership; retains record. |
| Resume while still Missing | Option 9 on a Missing parcel | Rejected; first confirm recovery by changing it to OnHold. |
| Recover and resume | Option 8 -> ID -> 2; then option 9 -> ID -> service route/priority | OnHold then next service; successful request creation sets its active status. |
| Report Missing/hold while request active | Task 1 option 8 on an active parcel | Rejected. Use Task 2 option 9 to close its current request and release a resource consistently. |
| Cancel active parcel | Use Task 2 cancellation rather than Task 1 direct status | Request/resource/parcel updates are coordinated; parcel ends Cancelled. |
| Process a completed parcel again | Explain terminal protection and no waiting membership | It cannot re-enter normal intake or receive another service. Task 1's process action selects waiting work, not an arbitrary completed ID. |
| Invalid route/priority enum from code | Existing C++ tests or inspect guards | Rejected. Normal menu ranges prevent entering such enum values. |

### Input and low-level boundaries

| Scenario | Result/explanation |
| --- | --- |
| Enter abc, 999, -1, blank or 1x at a menu | Retry after an integer/range/extra-character message. Menu parsing belongs to shared console code. |
| Input ends halfway through registration | No partial parcel is committed; menus exit cleanly. |
| One queued parcel is removed | Both front and rear become nullptr. |
| Remove queue head/middle/tail | Link around the removed node; head changes front, tail changes rear. |
| Remove list head/middle/last/only node | previous/current traversal reconnects correctly; empty list ends with head == nullptr. |
| Peek/dequeue an empty queue | Returns false; callers do not access a nonexistent node. |
| Queue becomes empty then gets a new parcel | enqueue initializes front and rear again; no dangling old rear is used. |
| Program exits with nonempty structures | Destructors save next, delete current and advance, freeing each owned node. |
| Copy an owning linked structure | Deleted copy operations prevent shallow copies and double deletion. |
| Storage is full | No fixed array capacity; allocation is limited by available memory. A throwing enqueue rolls back the new parcel record, then the entry-point handler stops with an error. |

## 5. Optional exception demonstration: a separate fresh run

This sequence is longer than the core demo. Use it if the lecturer asks about hold,
missing or recovery. It has its own fresh P1/R1 numbering.

1. Register Parcel A as P1.
2. Task 1 option 4 -> route 5. P1 becomes OnHold; no R1 yet.
3. Task 1 option 9 -> P1 -> Collection -> Normal. Creates R1; P1 AwaitingCollection.
4. Attempt a valid descriptive edit of P1. It must fail because R1 is active.
5. Return to Main, open Task 2 option 9 -> R1 -> Missing. R1 becomes Cancelled with
   an interruption explanation; P1 becomes Missing. Any assigned resource is freed.
6. Task 1 option 9 -> P1 -> Campus delivery -> Normal. It must reject while Missing.
7. Task 1 option 8 -> P1 -> On hold/recovered. This is explicit staff confirmation.
8. Task 1 option 9 -> P1 -> Campus delivery -> Normal. Creates R2; P1 AwaitingDelivery.

Explain:

> A missing parcel must not silently restart delivery. The previous request is
> closed, the parcel remains searchable, and staff explicitly confirm recovery
> before a new request is created.

## 6. Pointer traces and complexity to explain at the code

### Enqueue P2 after P1

Start with front == rear, both pointing to P1. Allocate a P2 queue node with next
nullptr. Set rear->next to the new node, then rear to the new node. Front stays P1.
Both pointer updates are constant-time, independent of queue length.

### Dequeue the only node

Copy the ID out while its node is alive. Save old = front. Move front to front->next,
which is nullptr. Set rear to nullptr, then delete old. The output ID is a string
copy, not a reference into deleted storage.

### Delete a middle record

For head -> P3 -> P2 -> P1 -> nullptr, removing P2 finds previous=P3/current=P2.
Set previous->next to current->next, making P3 point to P1, then delete P2. Head
remains P3. Do not delete current before reading its next pointer.

### Why successful routing calls remove rather than blindly dequeue

Service requests can also be created directly from Task 2 for a chosen parcel.
That parcel might be in the middle of intake. Removing its exact ID keeps waiting
membership correct for either entry point. Normal FIFO processNext chooses the
front, so finding/removing that selected ID is immediate.

Let P be saved parcels, Q waiting IDs and R retained service requests. Treat field
lengths as bounded for these node-count bounds; string work adds character costs.

| Operation | Honest complexity |
| --- | --- |
| Linked-list lookup, tracking duplicate check, removal | O(P) |
| Record insertion including duplicate-ID search | O(P); changing head alone is O(1) |
| Queue enqueue/dequeue/peek | O(1) |
| Arbitrary waiting-ID removal | O(Q) |
| Registration including both validation traversals | O(P), not O(P squared) |
| Edit with active-request check | O(P+R) |
| Remove cancelled parcel including queue cleanup | O(P+R+Q) upper bound |
| Normal FIFO service routing | O(P+R), excluding exceptional stale-entry scans |
| Worst stale-entry routing scan | O(Q*P+R) conservative upper bound |
| Task 1 storage | O(P+Q) nodes plus their field strings |

The record list can contain terminal parcels that are not waiting. P and Q are
therefore different sizes. Two sequential O(P) scans remain O(P), not O(P squared).

## 7. Logical questions and suggested answers

Use these to practice; explain in your own words and point to the relevant code.

**1. Which structures did you choose?** A singly linked list for authoritative parcel
records and a linked FIFO queue for temporary intake order. Both are implemented manually.

**2. Why not only a queue?** Processing removes waiting membership, but staff still
need the record for search, status updates and service completion.

**3. Why not store full Parcel copies in both?** Separate copies could disagree after
an edit/status update. The queue's ID refers back to the authoritative record.

**4. Why does P2 display before P1?** Record insertion is at head. FIFO order comes
from the separate intake queue, not the record-display order.

**5. Is routing itself automatic sorting by urgency?** No. FIFO chooses the next
intake parcel; staff classify its route. Task 2 uses urgency to order created requests.

**6. Can an urgent parcel skip ahead in intake?** Not through normal processNext:
that operation is FIFO. Urgency applies after routing. Direct Task 2 service creation
is a separate staff-selected path and removes that parcel's waiting ID.

**7. Why both front and rear?** Front supports O(1) next selection/removal; rear lets
enqueue append without traversing the whole queue.

**8. What happens if rear is not reset after the last removal?** It could reference
freed storage; a later enqueue might write through that invalid pointer.

**9. Why use peek before changing the queue?** It identifies the candidate without
losing it. The service insertion must succeed before successful routing removes membership.

**10. Does FIFO prohibit administrative cancellation from the middle?** Normal service
selection stays FIFO. Cancellation/hold/direct-service actions explicitly withdraw
an ID that is no longer eligible for normal intake; they do not reorder other waiting IDs.

**11. How do you prevent duplicate Parcel IDs?** Generated monotonically increasing
IDs avoid normal collisions; the record structure also checks ID uniqueness on insertion.

**12. Are IDs globally unique forever?** No. Counters restart on a fresh run because
there is no persistence. Uniqueness is within this running prototype's stored records.

**13. Why check tracking as well as Parcel ID?** Automatically assigning a fresh ID
alone would let the same physical tracking registration be entered repeatedly.

**14. Why does the duplicate edit check accept its own tracking?** exceptId excludes
the parcel being edited, while still detecting another record with that tracking.

**15. Does a nonblank recipient ID prove it is a real student?** No. Intake only
checks required information. Later requests match the stored ID; there is no university lookup.

**16. What happens if search fails?** Return nullptr and print a useful message.
The caller checks the pointer before accessing fields.

**17. What is the difference between const and non-const find?** Both search the same
list. The public-facing const result permits inspection; internal mutable lookup supports updates.

**18. Why return a pointer instead of a Parcel copy?** It avoids copying the whole
record and identifies existing storage. It is borrowed and becomes invalid after node deletion.

**19. Why reject active-request edits?** Changing recipient/destination/handling
information could invalidate already-created service work. The lifecycle must resolve that first.

**20. Can cancelled/collected parcels reopen?** No. They are terminal. Hold/missing
recovery is a controlled nonterminal path; cancellation is not a general undo feature.

**21. What is the difference between OnHold and Missing?** OnHold is retained for
staff investigation/review and can resume. Missing requires explicit recovery to OnHold first.

**22. Why cannot Task 1 directly change an active parcel to Missing?** It might leave
a live request/resource processing a missing parcel. Task 2 interruption closes/detaches
that work and updates the parcel coherently.

**23. What if a required service cannot be created?** createRequest returns false
before committing status/queue changes. The valid waiting parcel is not silently lost.

**24. Why friend class ServiceModule?** It grants that cooperating module controlled
access for synchronized status and intake changes. Ordinary menu code cannot mutate private storage.

**25. Does declaring a friend remove all design risks?** No. It couples the modules;
the cooperating implementation must still preserve the invariants and be tested.

**26. Why keep try/catch during registration?** Record insertion happens before queue
allocation. If the second allocation throws, rollback removes the partial registration.

**27. Why initialize node data with new Node{parcel}?** If copying a string fails
during initialization, C++ releases that allocation automatically. Pointer linkage
is performed separately after construction succeeds.

**28. What does swap do in updateParcel?** After validation and preserving saved
identity/time/status, it exchanges the prepared replacement with the stored record.
The old details leave with the local replacement instead of partially overwriting fields.

**29. Why disable copying of your structures?** A shallow copy would share node
pointers; both destructors could delete the same nodes. No deep-copy feature is needed here.

**30. Can you claim all operations are O(1)?** No. Only specific queue operations
are O(1). Record validation/search and integration perform traversals.

**31. What improvement did review produce?** Direct tracking traversal replaced repeated
ID searches. We also ensure service creation synchronizes parcel status and waiting
membership, and failed completion does not release resources prematurely.

**32. What is your main limitation?** In-memory storage and O(P) ID lookup. The
prototype also assumes authorized staff and does not verify real-world recipient identities.

**33. What small modification might you be asked to make?** Add a field, change the
allowed edit rule, print the queue length or adjust duplicate policy. Explain every
place it affects: model, input, validation, display, tests and integration as applicable.

**34. How would you add a waiting count?** Maintain a counter consistently on enqueue,
dequeue and arbitrary removal, or traverse to count in O(Q). The maintained version
needs extra invariant checks; the current code does not already implement it.

**35. What if a cancelled parcel is removed but a terminal request remains?** The
request retains the former Parcel ID as inactive historical text. It cannot be
processed; staff can explicitly remove that terminal request too.

## 8. Last rehearsal checklist

- Start a fresh process, and keep the mock inputs available.
- Practice the main sequence in Section 3 without the optional exception sequence.
- Confirm that you can explain P1/P2 display order versus processing order.
- Open the four key views beforehand: Parcel fields, node definitions, registration,
  and processNext. Be ready to jump to enqueue/dequeue or removal if asked.
- Explain state at the end: AwaitingCollection is not Collected; Pending is not Completed.
- Do not say contact format, university identity, staff authentication or persistence
  is implemented when it is not.
- Treat the scripts as study notes. Trace the pointers and describe your own assigned
  contribution accurately, including the assignment's AI-usage declaration requirements.
