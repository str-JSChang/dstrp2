# tests/system_tests.cpp - every line explained

Source: [tests/system_tests.cpp](../../tests/system_tests.cpp)

Physical lines: 346; SHA-256 (LF text): `59194b49f2f008ba52d20992acc2250cab923d9b5fe025ba9cb2a7e7cd97b796`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#include &quot;task1.hpp&quot;</code> | Include `"task1.hpp"` for Task 1 declarations. |
| 2 | <code>#include &quot;task2.hpp&quot;</code> | Include `"task2.hpp"` for Task 2 declarations. |
| 3 | <code>#include &quot;task3.hpp&quot;</code> | Include `"task3.hpp"` for Task 3 declarations. |
| 4 | <code>#include &lt;stdexcept&gt;</code> | Include `<stdexcept>` for runtime_error for test failures. |
| 5 | <code>#include &lt;sstream&gt;</code> | Include `<sstream>` for string-backed input/output streams. |
| 6 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 7 | <code>using namespace campus;</code> | Make names from `campus` available without repeating that namespace prefix. |
| 8 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 9 | <code>int checks = 0;</code> | Create local `checks` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 10 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 11 | <code>void check(bool condition, const string&amp; message) {</code> | Define `check`. Count a test expectation and throw a runtime_error with its diagnostic if the expectation is false. Unlike assert, release builds keep this check. |
| 12 | <code>    checks++;</code> | Increment `checks` only at this point in the successful operation/test count. |
| 13 | <code>    if (!condition) throw runtime_error(message);</code> | Test `!condition`. Throw the named failure object, transferring control to the nearest matching exception handler. |
| 14 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 15 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 16 | <code>Parcel sampleParcel(const string&amp; tracking = &quot;TRACK1&quot;) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 17 | <code>    Parcel parcel;</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 18 | <code>    parcel.recipientName = &quot;Alice&quot;;</code> | Set `parcel.recipientName` to `"Alice"`. |
| 19 | <code>    parcel.recipientId = &quot;TP001&quot;;</code> | Set `parcel.recipientId` to `"TP001"`. |
| 20 | <code>    parcel.recipientContact = &quot;0123456789&quot;;</code> | Set `parcel.recipientContact` to `"0123456789"`. |
| 21 | <code>    parcel.deliveryCompany = &quot;Campus Courier&quot;;</code> | Set `parcel.deliveryCompany` to `"Campus Courier"`. |
| 22 | <code>    parcel.trackingNumber = tracking;</code> | Set `parcel.trackingNumber` to `tracking`. |
| 23 | <code>    parcel.destination = &quot;Block A&quot;;</code> | Set `parcel.destination` to `"Block A"`. |
| 24 | <code>    parcel.parcelType = &quot;Box&quot;;</code> | Set `parcel.parcelType` to `"Box"`. |
| 25 | <code>    return parcel;</code> | Return the value of `parcel` to the caller. This ends the function once its full return expression is evaluated. |
| 26 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 27 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 28 | <code>struct Fixture {</code> | Begin the struct `Fixture` definition, grouping its fields and operations. |
| 29 | <code>    ParcelModule parcels;</code> | Create local `parcels` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 30 | <code>    ServiceModule services{parcels};</code> | Create local `services` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 31 | <code>    ResourceModule resources{services};</code> | Create local `resources` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 32 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 33 | <code>    void registerParcel(const string&amp; tracking = &quot;TRACK1&quot;) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 34 | <code>        check(parcels.registerParcel(sampleParcel(tracking)), &quot;registration failed&quot;);</code> | Check the test expectation: registration failed. A false condition throws and makes the test run fail. |
| 35 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 36 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 37 | <code>    void registerResource(const string&amp; id, ResourceType type) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 38 | <code>        Resource resource;</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 39 | <code>        resource.id = id;</code> | Set `resource.id` to `id`. |
| 40 | <code>        resource.name = id + &quot; name&quot;;</code> | Set `resource.name` to `id + " name"`. |
| 41 | <code>        resource.type = type;</code> | Set `resource.type` to `type`. |
| 42 | <code>        check(resources.registerResource(resource), &quot;resource registration failed&quot;);</code> | Check the test expectation: resource registration failed. A false condition throws and makes the test run fail. |
| 43 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 44 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 45 | <code>    void create(ServiceType type, const string&amp; parcelId = &quot;P1&quot;,</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 46 | <code>                RequestPriority priority = RequestPriority::Normal) {</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 47 | <code>        ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 48 | <code>        request.parcelId = parcelId;</code> | Set `request.parcelId` to `parcelId`. |
| 49 | <code>        request.recipientId = &quot;TP001&quot;;</code> | Set `request.recipientId` to `"TP001"`. |
| 50 | <code>        request.serviceDetails = &quot;Staff service request&quot;;</code> | Set `request.serviceDetails` to `"Staff service request"`. |
| 51 | <code>        request.type = type;</code> | Set `request.type` to `type`. |
| 52 | <code>        request.priority = priority;</code> | Set `request.priority` to `priority`. |
| 53 | <code>        check(services.createRequest(request), &quot;request creation failed&quot;);</code> | Check the test expectation: request creation failed. A false condition throws and makes the test run fail. |
| 54 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 55 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 56 | <code>    void assignAndProcess(const string&amp; id, ResourceType type) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 57 | <code>        check(resources.assignRequest(id, type), &quot;assignment failed&quot;);</code> | Check the test expectation: assignment failed. A false condition throws and makes the test run fail. |
| 58 | <code>        check(services.processRequest(id), &quot;processing failed&quot;);</code> | Check the test expectation: processing failed. A false condition throws and makes the test run fail. |
| 59 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 60 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 61 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 62 | <code>void testLinkedStructures() {</code> | Define `testLinkedStructures`. Exercise empty/one/multiple-node lists, deletion boundaries, FIFO, priority stability, ring wrap and independent mixed-type cursors. |
| 63 | <code>    ParcelRecords records;</code> | Create local `records` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 64 | <code>    check(records.find(&quot;X&quot;) == nullptr &amp;&amp; !records.remove(&quot;X&quot;), &quot;empty list lookup/remove&quot;);</code> | Check the test expectation: empty list lookup/remove. A false condition throws and makes the test run fail. |
| 65 | <code>    Parcel parcel = sampleParcel();</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 66 | <code>    parcel.id = &quot;A&quot;;</code> | Set `parcel.id` to `"A"`. |
| 67 | <code>    check(records.insert(parcel), &quot;insert A&quot;);</code> | Check the test expectation: insert A. A false condition throws and makes the test run fail. |
| 68 | <code>    check(!records.insert(parcel), &quot;duplicate record ID&quot;);</code> | Check the test expectation: duplicate record ID. A false condition throws and makes the test run fail. |
| 69 | <code>    parcel.id = &quot;B&quot;;</code> | Set `parcel.id` to `"B"`. |
| 70 | <code>    check(records.insert(parcel), &quot;insert B&quot;);</code> | Check the test expectation: insert B. A false condition throws and makes the test run fail. |
| 71 | <code>    parcel.id = &quot;C&quot;;</code> | Set `parcel.id` to `"C"`. |
| 72 | <code>    check(records.insert(parcel), &quot;insert C&quot;);</code> | Check the test expectation: insert C. A false condition throws and makes the test run fail. |
| 73 | <code>    check(records.remove(&quot;B&quot;) &amp;&amp; records.find(&quot;A&quot;) &amp;&amp; records.find(&quot;C&quot;), &quot;middle removal&quot;);</code> | Check the test expectation: middle removal. A false condition throws and makes the test run fail. |
| 74 | <code>    check(records.remove(&quot;C&quot;) &amp;&amp; records.remove(&quot;A&quot;) &amp;&amp; !records.remove(&quot;A&quot;), &quot;head and only removal&quot;);</code> | Check the test expectation: head and only removal. A false condition throws and makes the test run fail. |
| 75 | <code>    check(records.insert(parcel) &amp;&amp; records.remove(&quot;C&quot;), &quot;reuse empty list&quot;);</code> | Check the test expectation: reuse empty list. A false condition throws and makes the test run fail. |
| 76 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 77 | <code>    IntakeQueue queue;</code> | Create local `queue` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 78 | <code>    string id = &quot;unchanged&quot;;</code> | Create local `id` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 79 | <code>    check(queue.empty() &amp;&amp; !queue.dequeue(id) &amp;&amp; !queue.peek(id), &quot;empty intake operations&quot;);</code> | Check the test expectation: empty intake operations. A false condition throws and makes the test run fail. |
| 80 | <code>    check(id == &quot;unchanged&quot;, &quot;empty operation changed output&quot;);</code> | Check the test expectation: empty operation changed output. A false condition throws and makes the test run fail. |
| 81 | <code>    check(!queue.enqueue(&quot; &quot;), &quot;blank queue ID accepted&quot;);</code> | Check the test expectation: blank queue ID accepted. A false condition throws and makes the test run fail. |
| 82 | <code>    queue.enqueue(&quot;A&quot;); queue.enqueue(&quot;B&quot;); queue.enqueue(&quot;C&quot;);</code> | Call `queue.enqueue` with the shown arguments. The call performs its named operation within testLinkedStructures. |
| 83 | <code>    check(queue.peek(id) &amp;&amp; id == &quot;A&quot;, &quot;FIFO head&quot;);</code> | Check the test expectation: FIFO head. A false condition throws and makes the test run fail. |
| 84 | <code>    check(queue.remove(&quot;B&quot;) &amp;&amp; queue.remove(&quot;C&quot;), &quot;queue middle and tail removal&quot;);</code> | Check the test expectation: queue middle and tail removal. A false condition throws and makes the test run fail. |
| 85 | <code>    queue.enqueue(&quot;D&quot;);</code> | Call `queue.enqueue` with the shown arguments. The call performs its named operation within testLinkedStructures. |
| 86 | <code>    check(queue.dequeue(id) &amp;&amp; id == &quot;A&quot;, &quot;FIFO first&quot;);</code> | Check the test expectation: FIFO first. A false condition throws and makes the test run fail. |
| 87 | <code>    check(queue.dequeue(id) &amp;&amp; id == &quot;D&quot; &amp;&amp; queue.empty(), &quot;rear repaired after removal&quot;);</code> | Check the test expectation: rear repaired after removal. A false condition throws and makes the test run fail. |
| 88 | <code>    queue.enqueue(&quot;E&quot;);</code> | Call `queue.enqueue` with the shown arguments. The call performs its named operation within testLinkedStructures. |
| 89 | <code>    check(queue.remove(&quot;E&quot;) &amp;&amp; queue.empty(), &quot;only queue node removal&quot;);</code> | Check the test expectation: only queue node removal. A false condition throws and makes the test run fail. |
| 90 | <code>    queue.enqueue(&quot;F&quot;);</code> | Call `queue.enqueue` with the shown arguments. The call performs its named operation within testLinkedStructures. |
| 91 | <code>    check(queue.dequeue(id) &amp;&amp; id == &quot;F&quot;, &quot;queue reuse after empty&quot;);</code> | Check the test expectation: queue reuse after empty. A false condition throws and makes the test run fail. |
| 92 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 93 | <code>    RequestQueue requests;</code> | Create local `requests` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 94 | <code>    check(!requests.nextPending() &amp;&amp; !requests.remove(&quot;X&quot;), &quot;empty requests&quot;);</code> | Check the test expectation: empty requests. A false condition throws and makes the test run fail. |
| 95 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 96 | <code>    request.id = &quot;N1&quot;; request.sequence = 1;</code> | Set `request.id` to `"N1"; request.sequence = 1`. |
| 97 | <code>    check(requests.insert(request), &quot;normal insertion&quot;);</code> | Check the test expectation: normal insertion. A false condition throws and makes the test run fail. |
| 98 | <code>    request.id = &quot;U1&quot;; request.priority = RequestPriority::Urgent; request.sequence = 2;</code> | Set `request.id` to `"U1"; request.priority = RequestPriority::Urgent; request.sequence = 2`. |
| 99 | <code>    check(requests.insert(request), &quot;urgent insertion&quot;);</code> | Check the test expectation: urgent insertion. A false condition throws and makes the test run fail. |
| 100 | <code>    request.id = &quot;U2&quot;; request.sequence = 3;</code> | Set `request.id` to `"U2"; request.sequence = 3`. |
| 101 | <code>    check(requests.insert(request) &amp;&amp; !requests.insert(request), &quot;duplicate request ID&quot;);</code> | Check the test expectation: duplicate request ID. A false condition throws and makes the test run fail. |
| 102 | <code>    check(requests.nextPending()-&gt;id == &quot;U1&quot;, &quot;urgent first with FIFO ties&quot;);</code> | Check the test expectation: urgent first with FIFO ties. A false condition throws and makes the test run fail. |
| 103 | <code>    requests.find(&quot;U1&quot;)-&gt;status = RequestStatus::Assigned;</code> | Set `requests.find("U1")->status` to `RequestStatus::Assigned`. This is a lifecycle/availability change performed after the required guards. |
| 104 | <code>    check(requests.nextPending()-&gt;id == &quot;U2&quot;, &quot;skip assigned request&quot;);</code> | Check the test expectation: skip assigned request. A false condition throws and makes the test run fail. |
| 105 | <code>    requests.find(&quot;U2&quot;)-&gt;status = RequestStatus::Completed;</code> | Set `requests.find("U2")->status` to `RequestStatus::Completed`. This is a lifecycle/availability change performed after the required guards. |
| 106 | <code>    check(requests.nextPending()-&gt;id == &quot;N1&quot;, &quot;skip terminal request&quot;);</code> | Check the test expectation: skip terminal request. A false condition throws and makes the test run fail. |
| 107 | <code>    check(requests.remove(&quot;U2&quot;) &amp;&amp; requests.remove(&quot;U1&quot;) &amp;&amp; requests.remove(&quot;N1&quot;), &quot;request deletion boundaries&quot;);</code> | Check the test expectation: request deletion boundaries. A false condition throws and makes the test run fail. |
| 108 | <code>    check(!requests.nextPending(), &quot;request queue empty after removal&quot;);</code> | Check the test expectation: request queue empty after removal. A false condition throws and makes the test run fail. |
| 109 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 110 | <code>    ResourceRing ring;</code> | Create local `ring` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 111 | <code>    check(!ring.find(&quot;X&quot;) &amp;&amp; !ring.nextAvailable(ResourceType::CollectionCounter), &quot;empty resource ring&quot;);</code> | Check the test expectation: empty resource ring. A false condition throws and makes the test run fail. |
| 112 | <code>    Resource resource;</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 113 | <code>    resource.id = &quot;A&quot;; resource.name = &quot;A&quot;;</code> | Set `resource.id` to `"A"; resource.name = "A"`. |
| 114 | <code>    check(ring.insert(resource) &amp;&amp; !ring.insert(resource), &quot;ring duplicate ID&quot;);</code> | Check the test expectation: ring duplicate ID. A false condition throws and makes the test run fail. |
| 115 | <code>    check(ring.nextAvailable(resource.type)-&gt;id == &quot;A&quot;, &quot;single-node ring&quot;);</code> | Check the test expectation: single-node ring. A false condition throws and makes the test run fail. |
| 116 | <code>    resource.id = &quot;B&quot;; check(ring.insert(resource), &quot;second ring node&quot;);</code> | Set `resource.id` to `"B"; check(ring.insert(resource), "second ring node")`. |
| 117 | <code>    check(ring.nextAvailable(resource.type)-&gt;id == &quot;A&quot;, &quot;ring cursor after insertion&quot;);</code> | Check the test expectation: ring cursor after insertion. A false condition throws and makes the test run fail. |
| 118 | <code>    check(ring.nextAvailable(resource.type)-&gt;id == &quot;B&quot;, &quot;round-robin second&quot;);</code> | Check the test expectation: round-robin second. A false condition throws and makes the test run fail. |
| 119 | <code>    check(ring.nextAvailable(resource.type)-&gt;id == &quot;A&quot;, &quot;round-robin wrap&quot;);</code> | Check the test expectation: round-robin wrap. A false condition throws and makes the test run fail. |
| 120 | <code>    ring.find(&quot;A&quot;)-&gt;status = ResourceStatus::Unavailable;</code> | Set `ring.find("A")->status` to `ResourceStatus::Unavailable`. This is a lifecycle/availability change performed after the required guards. |
| 121 | <code>    ring.find(&quot;B&quot;)-&gt;status = ResourceStatus::Occupied;</code> | Set `ring.find("B")->status` to `ResourceStatus::Occupied`. This is a lifecycle/availability change performed after the required guards. |
| 122 | <code>    check(!ring.nextAvailable(resource.type), &quot;all resources unavailable stops after one cycle&quot;);</code> | Check the test expectation: all resources unavailable stops after one cycle. A false condition throws and makes the test run fail. |
| 123 | <code>    check(!ring.nextAvailable(ResourceType::DeliveryPersonnel), &quot;wrong-type ring scan&quot;);</code> | Check the test expectation: wrong-type ring scan. A false condition throws and makes the test run fail. |
| 124 | <code>    ring.find(&quot;A&quot;)-&gt;status = ResourceStatus::Available;</code> | Set `ring.find("A")->status` to `ResourceStatus::Available`. This is a lifecycle/availability change performed after the required guards. |
| 125 | <code>    ring.find(&quot;B&quot;)-&gt;status = ResourceStatus::Available;</code> | Set `ring.find("B")->status` to `ResourceStatus::Available`. This is a lifecycle/availability change performed after the required guards. |
| 126 | <code>    resource.id = &quot;D&quot;; resource.type = ResourceType::DeliveryPersonnel;</code> | Set `resource.id` to `"D"; resource.type = ResourceType::DeliveryPersonnel`. |
| 127 | <code>    check(ring.insert(resource), &quot;insert mixed resource type&quot;);</code> | Check the test expectation: insert mixed resource type. A false condition throws and makes the test run fail. |
| 128 | <code>    check(ring.nextAvailable(ResourceType::CollectionCounter)-&gt;id == &quot;B&quot;, &quot;counter cursor preserved&quot;);</code> | Check the test expectation: counter cursor preserved. A false condition throws and makes the test run fail. |
| 129 | <code>    check(ring.nextAvailable(ResourceType::DeliveryPersonnel)-&gt;id == &quot;D&quot;, &quot;select delivery resource&quot;);</code> | Check the test expectation: select delivery resource. A false condition throws and makes the test run fail. |
| 130 | <code>    check(ring.nextAvailable(ResourceType::CollectionCounter)-&gt;id == &quot;A&quot;, &quot;separate cursors prevent mixed-type starvation&quot;);</code> | Check the test expectation: separate cursors prevent mixed-type starvation. A false condition throws and makes the test run fail. |
| 131 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 132 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 133 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 134 | <code>void testParcelValidation() {</code> | Define `testParcelValidation`. Verify required fields, duplicate tracking, edit protection, cancellation/deletion and FIFO behavior after removal. |
| 135 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 136 | <code>    Parcel parcel = sampleParcel();</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 137 | <code>    parcel.recipientName = &quot; \t &quot;;</code> | Set `parcel.recipientName` to `" \t "`. |
| 138 | <code>    check(!f.parcels.registerParcel(parcel), &quot;whitespace recipient accepted&quot;);</code> | Check the test expectation: whitespace recipient accepted. A false condition throws and makes the test run fail. |
| 139 | <code>    f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testParcelValidation. |
| 140 | <code>    check(!f.parcels.registerParcel(sampleParcel()), &quot;duplicate tracking accepted&quot;);</code> | Check the test expectation: duplicate tracking accepted. A false condition throws and makes the test run fail. |
| 141 | <code>    f.registerParcel(&quot;TRACK2&quot;);</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testParcelValidation. |
| 142 | <code>    check(f.parcels.findParcel(&quot;P2&quot;) != nullptr, &quot;failed registration consumed ID&quot;);</code> | Check the test expectation: failed registration consumed ID. A false condition throws and makes the test run fail. |
| 143 | <code>    parcel = sampleParcel(&quot;TRACK2&quot;);</code> | Set `parcel` to `sampleParcel("TRACK2")`. |
| 144 | <code>    check(!f.parcels.updateParcel(&quot;P1&quot;, parcel, f.services), &quot;duplicate tracking edit accepted&quot;);</code> | Check the test expectation: duplicate tracking edit accepted. A false condition throws and makes the test run fail. |
| 145 | <code>    parcel = sampleParcel(&quot;NEW&quot;); parcel.recipientName = &quot;  Bob  &quot;;</code> | Set `parcel` to `sampleParcel("NEW"); parcel.recipientName = "  Bob  "`. |
| 146 | <code>    check(f.parcels.updateParcel(&quot;P1&quot;, parcel, f.services), &quot;valid edit failed&quot;);</code> | Check the test expectation: valid edit failed. A false condition throws and makes the test run fail. |
| 147 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;recipientName == &quot;Bob&quot;, &quot;trimmed name&quot;);</code> | Check the test expectation: trimmed name. A false condition throws and makes the test run fail. |
| 148 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::Received, &quot;edit changed status&quot;);</code> | Check the test expectation: edit changed status. A false condition throws and makes the test run fail. |
| 149 | <code>    check(!f.parcels.removeParcel(&quot;P1&quot;, f.services), &quot;live parcel removed&quot;);</code> | Check the test expectation: live parcel removed. A false condition throws and makes the test run fail. |
| 150 | <code>    check(f.parcels.updateStatus(&quot;P1&quot;, ParcelStatus::Cancelled, f.services), &quot;cancel unprocessed parcel&quot;);</code> | Check the test expectation: cancel unprocessed parcel. A false condition throws and makes the test run fail. |
| 151 | <code>    check(f.parcels.removeParcel(&quot;P1&quot;, f.services), &quot;cancelled parcel removal&quot;);</code> | Check the test expectation: cancelled parcel removal. A false condition throws and makes the test run fail. |
| 152 | <code>    check(f.parcels.processNext(Route::Collection, f.services), &quot;FIFO after cancelled removal&quot;);</code> | Check the test expectation: FIFO after cancelled removal. A false condition throws and makes the test run fail. |
| 153 | <code>    check(f.services.findRequest(&quot;R1&quot;)-&gt;parcelId == &quot;P2&quot;, &quot;processed wrong FIFO parcel&quot;);</code> | Check the test expectation: processed wrong FIFO parcel. A false condition throws and makes the test run fail. |
| 154 | <code>    check(!f.parcels.processNext(Route::Collection, f.services), &quot;empty intake accepted&quot;);</code> | Check the test expectation: empty intake accepted. A false condition throws and makes the test run fail. |
| 155 | <code>    check(!f.parcels.findParcel(&quot;UNKNOWN&quot;), &quot;unknown parcel found&quot;);</code> | Check the test expectation: unknown parcel found. A false condition throws and makes the test run fail. |
| 156 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 157 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 158 | <code>void testEveryServiceLifecycle() {</code> | Define `testEveryServiceLifecycle`. Run every service type from direct request creation through assignment/processing/completion and verify all three records. |
| 159 | <code>    for (int value = 0; value &lt;= 4; value++) {</code> | Run the counted/traversal loop `for (int value = 0; value <= 4; value++) {`. Its initialization, condition and increment control each iteration. |
| 160 | <code>        Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 161 | <code>        ServiceType type = static_cast&lt;ServiceType&gt;(value);</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 162 | <code>        ResourceType resourceType = serviceResource(type);</code> | Create local `resourceType` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 163 | <code>        f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testEveryServiceLifecycle. |
| 164 | <code>        f.registerResource(&quot;RES&quot;, resourceType);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testEveryServiceLifecycle. |
| 165 | <code>        f.create(type);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testEveryServiceLifecycle. |
| 166 | <code>        check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == serviceStatus(type), &quot;direct request did not synchronize parcel&quot;);</code> | Check the test expectation: direct request did not synchronize parcel. A false condition throws and makes the test run fail. |
| 167 | <code>        check(!f.parcels.processNext(Route::Collection, f.services), &quot;direct request left parcel in intake&quot;);</code> | Check the test expectation: direct request left parcel in intake. A false condition throws and makes the test run fail. |
| 168 | <code>        check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Done&quot;, &quot;TP001&quot;, f.resources), &quot;unassigned completion&quot;);</code> | Check the test expectation: unassigned completion. A false condition throws and makes the test run fail. |
| 169 | <code>        check(!f.services.processRequest(&quot;R1&quot;), &quot;unassigned processing&quot;);</code> | Check the test expectation: unassigned processing. A false condition throws and makes the test run fail. |
| 170 | <code>        f.assignAndProcess(&quot;R1&quot;, resourceType);</code> | Call `f.assignAndProcess` with the shown arguments. The call performs its named operation within testEveryServiceLifecycle. |
| 171 | <code>        check(!f.services.processRequest(&quot;R1&quot;), &quot;repeated processing&quot;);</code> | Check the test expectation: repeated processing. A false condition throws and makes the test run fail. |
| 172 | <code>        check(f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Done&quot;, &quot;TP001&quot;, f.resources), &quot;valid completion failed&quot;);</code> | Check the test expectation: valid completion failed. A false condition throws and makes the test run fail. |
| 173 | <code>        ParcelStatus expected = type == ServiceType::Collection ? ParcelStatus::Collected</code> | Create local `expected` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 174 | <code>            : type == ServiceType::SpecialHandling ? ParcelStatus::OnHold</code> | Continue the conditional expression: choose this value when its corresponding condition is true/false. |
| 175 | <code>            : type == ServiceType::ReturnToSender ? ParcelStatus::Returned : ParcelStatus::Delivered;</code> | Continue the conditional expression: choose this value when its corresponding condition is true/false. |
| 176 | <code>        check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == expected, &quot;wrong final parcel status&quot;);</code> | Check the test expectation: wrong final parcel status. A false condition throws and makes the test run fail. |
| 177 | <code>        RequestStatus expectedRequest = type == ServiceType::ReturnToSender ? RequestStatus::Returned : RequestStatus::Completed;</code> | Create local `expectedRequest` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 178 | <code>        check(f.services.findRequest(&quot;R1&quot;)-&gt;status == expectedRequest, &quot;wrong final request status&quot;);</code> | Check the test expectation: wrong final request status. A false condition throws and makes the test run fail. |
| 179 | <code>        check(f.resources.findResource(&quot;RES&quot;)-&gt;status == ResourceStatus::Available, &quot;resource not freed&quot;);</code> | Check the test expectation: resource not freed. A false condition throws and makes the test run fail. |
| 180 | <code>        check(f.services.findRequest(&quot;R1&quot;)-&gt;resourceId.empty(), &quot;request resource ID not cleared&quot;);</code> | Check the test expectation: request resource ID not cleared. A false condition throws and makes the test run fail. |
| 181 | <code>        check(f.resources.findResource(&quot;RES&quot;)-&gt;assignedRequestId.empty(), &quot;resource request ID not cleared&quot;);</code> | Check the test expectation: resource request ID not cleared. A false condition throws and makes the test run fail. |
| 182 | <code>        if (type == ServiceType::CampusDelivery) {</code> | Test `type == ServiceType::CampusDelivery`. Run the following guarded block only when true. |
| 183 | <code>            ServiceRequest retry;</code> | Create local `retry` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 184 | <code>            retry.parcelId = &quot;P1&quot;; retry.recipientId = &quot;TP001&quot;;</code> | Set `retry.parcelId` to `"P1"; retry.recipientId = "TP001"`. |
| 185 | <code>            retry.type = ServiceType::Redelivery; retry.serviceDetails = &quot;Retry delivered parcel&quot;;</code> | Set `retry.type` to `ServiceType::Redelivery; retry.serviceDetails = "Retry delivered parcel"`. |
| 186 | <code>            check(!f.services.createRequest(retry), &quot;redelivery on delivered parcel accepted&quot;);</code> | Check the test expectation: redelivery on delivered parcel accepted. A false condition throws and makes the test run fail. |
| 187 | <code>            check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::Delivered,</code> | Check the test expectation: P1. A false condition throws and makes the test run fail. |
| 188 | <code>                  &quot;rejected redelivery altered delivered parcel&quot;);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 189 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 190 | <code>        check(!f.services.cancelRequest(&quot;R1&quot;, f.resources), &quot;terminal request cancelled again&quot;);</code> | Check the test expectation: terminal request cancelled again. A false condition throws and makes the test run fail. |
| 191 | <code>        check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Again&quot;, &quot;TP001&quot;, f.resources), &quot;repeated completion&quot;);</code> | Check the test expectation: repeated completion. A false condition throws and makes the test run fail. |
| 192 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 193 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 194 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 195 | <code>void testFailedCompletionIsUnchanged() {</code> | Define `testFailedCompletionIsUnchanged`. Reject wrong recipient, blank details, invalid outcome and unsafe parcel edits; verify existing parcel/request/resource state remains unchanged before a successful retry. |
| 196 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 197 | <code>    f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testFailedCompletionIsUnchanged. |
| 198 | <code>    f.registerResource(&quot;C1&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testFailedCompletionIsUnchanged. |
| 199 | <code>    f.create(ServiceType::Collection);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testFailedCompletionIsUnchanged. |
| 200 | <code>    check(f.resources.assignRequest(&quot;R1&quot;, ResourceType::CollectionCounter), &quot;assignment&quot;);</code> | Check the test expectation: assignment. A false condition throws and makes the test run fail. |
| 201 | <code>    check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Done&quot;, &quot;TP001&quot;, f.resources), &quot;completion before processing&quot;);</code> | Check the test expectation: completion before processing. A false condition throws and makes the test run fail. |
| 202 | <code>    check(f.services.processRequest(&quot;R1&quot;), &quot;start processing&quot;);</code> | Check the test expectation: start processing. A false condition throws and makes the test run fail. |
| 203 | <code>    check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Done&quot;, &quot;WRONG&quot;, f.resources), &quot;incorrect collection identity&quot;);</code> | Check the test expectation: incorrect collection identity. A false condition throws and makes the test run fail. |
| 204 | <code>    check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot; \t &quot;, &quot;TP001&quot;, f.resources), &quot;blank outcome details&quot;);</code> | Check the test expectation: blank outcome details. A false condition throws and makes the test run fail. |
| 205 | <code>    check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Pending, &quot;Done&quot;, &quot;TP001&quot;, f.resources), &quot;invalid outcome&quot;);</code> | Check the test expectation: invalid outcome. A false condition throws and makes the test run fail. |
| 206 | <code>    check(!f.parcels.updateStatus(&quot;P1&quot;, ParcelStatus::Missing, f.services), &quot;unsafe active parcel mutation&quot;);</code> | Check the test expectation: unsafe active parcel mutation. A false condition throws and makes the test run fail. |
| 207 | <code>    check(!f.parcels.updateParcel(&quot;P1&quot;, sampleParcel(&quot;NEW&quot;), f.services), &quot;active parcel edit&quot;);</code> | Check the test expectation: active parcel edit. A false condition throws and makes the test run fail. |
| 208 | <code>    const ServiceRequest* request = f.services.findRequest(&quot;R1&quot;);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 209 | <code>    check(request-&gt;status == RequestStatus::InProgress &amp;&amp; request-&gt;resourceId == &quot;C1&quot;, &quot;failed completion altered request&quot;);</code> | Check the test expectation: failed completion altered request. A false condition throws and makes the test run fail. |
| 210 | <code>    check(f.resources.findResource(&quot;C1&quot;)-&gt;status == ResourceStatus::Occupied</code> | Check the test expectation: C1. A false condition throws and makes the test run fail. |
| 211 | <code>        &amp;&amp; f.resources.findResource(&quot;C1&quot;)-&gt;assignedRequestId == &quot;R1&quot;, &quot;failed completion freed resource&quot;);</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 212 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::AwaitingCollection, &quot;failed completion changed parcel&quot;);</code> | Check the test expectation: failed completion changed parcel. A false condition throws and makes the test run fail. |
| 213 | <code>    check(f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Verified&quot;, &quot;TP001&quot;, f.resources), &quot;retry completion&quot;);</code> | Check the test expectation: retry completion. A false condition throws and makes the test run fail. |
| 214 | <code>    ServiceRequest redelivery;</code> | Create local `redelivery` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 215 | <code>    redelivery.parcelId = &quot;P1&quot;; redelivery.recipientId = &quot;TP001&quot;;</code> | Set `redelivery.parcelId` to `"P1"; redelivery.recipientId = "TP001"`. |
| 216 | <code>    redelivery.type = ServiceType::Redelivery; redelivery.serviceDetails = &quot;Try again&quot;;</code> | Set `redelivery.type` to `ServiceType::Redelivery; redelivery.serviceDetails = "Try again"`. |
| 217 | <code>    check(!f.services.createRequest(redelivery), &quot;completed parcel reopened&quot;);</code> | Check the test expectation: completed parcel reopened. A false condition throws and makes the test run fail. |
| 218 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 219 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 220 | <code>void testResourceInterruptionAndRecovery() {</code> | Define `testResourceInterruptionAndRecovery`. Test wrong/busy/unavailable resource handling and an in-progress parcel reported Missing, recovered to OnHold, resumed and returned. |
| 221 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 222 | <code>    f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 223 | <code>    f.registerResource(&quot;D1&quot;, ResourceType::DeliveryPersonnel);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 224 | <code>    f.create(ServiceType::CampusDelivery);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 225 | <code>    check(!f.resources.assignRequest(&quot;R1&quot;, ResourceType::CollectionCounter), &quot;wrong resource type assigned&quot;);</code> | Check the test expectation: wrong resource type assigned. A false condition throws and makes the test run fail. |
| 226 | <code>    f.assignAndProcess(&quot;R1&quot;, ResourceType::DeliveryPersonnel);</code> | Call `f.assignAndProcess` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 227 | <code>    check(!f.resources.assignRequest(&quot;R1&quot;, ResourceType::DeliveryPersonnel), &quot;duplicate active assignment&quot;);</code> | Check the test expectation: duplicate active assignment. A false condition throws and makes the test run fail. |
| 228 | <code>    check(f.resources.updateStatus(&quot;D1&quot;, ResourceStatus::Unavailable), &quot;make occupied resource unavailable&quot;);</code> | Check the test expectation: make occupied resource unavailable. A false condition throws and makes the test run fail. |
| 229 | <code>    check(f.services.findRequest(&quot;R1&quot;)-&gt;status == RequestStatus::Pending</code> | Check the test expectation: R1. A false condition throws and makes the test run fail. |
| 230 | <code>        &amp;&amp; f.services.findRequest(&quot;R1&quot;)-&gt;resourceId.empty(), &quot;interruption did not detach request&quot;);</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 231 | <code>    check(!f.resources.assignRequest(&quot;R1&quot;, ResourceType::DeliveryPersonnel), &quot;unavailable resource selected&quot;);</code> | Check the test expectation: unavailable resource selected. A false condition throws and makes the test run fail. |
| 232 | <code>    check(!f.resources.releaseResource(&quot;D1&quot;), &quot;released unassigned resource&quot;);</code> | Check the test expectation: released unassigned resource. A false condition throws and makes the test run fail. |
| 233 | <code>    check(f.resources.updateStatus(&quot;D1&quot;, ResourceStatus::Available), &quot;restore availability&quot;);</code> | Check the test expectation: restore availability. A false condition throws and makes the test run fail. |
| 234 | <code>    f.assignAndProcess(&quot;R1&quot;, ResourceType::DeliveryPersonnel);</code> | Call `f.assignAndProcess` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 235 | <code>    check(f.services.interruptRequest(&quot;R1&quot;, ParcelStatus::Missing, f.resources), &quot;report missing during processing&quot;);</code> | Check the test expectation: report missing during processing. A false condition throws and makes the test run fail. |
| 236 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::Missing, &quot;missing parcel status&quot;);</code> | Check the test expectation: missing parcel status. A false condition throws and makes the test run fail. |
| 237 | <code>    check(f.services.findRequest(&quot;R1&quot;)-&gt;status == RequestStatus::Cancelled, &quot;interrupted request still active&quot;);</code> | Check the test expectation: interrupted request still active. A false condition throws and makes the test run fail. |
| 238 | <code>    check(!f.services.completeRequest(&quot;R1&quot;, RequestStatus::Completed, &quot;Done&quot;, &quot;TP001&quot;, f.resources), &quot;missing parcel completed&quot;);</code> | Check the test expectation: missing parcel completed. A false condition throws and makes the test run fail. |
| 239 | <code>    check(!f.parcels.resumeParcel(&quot;P1&quot;, Route::CampusDelivery, f.services), &quot;missing parcel resumed without recovery&quot;);</code> | Check the test expectation: missing parcel resumed without recovery. A false condition throws and makes the test run fail. |
| 240 | <code>    check(f.parcels.updateStatus(&quot;P1&quot;, ParcelStatus::OnHold, f.services), &quot;mark recovered parcel&quot;);</code> | Check the test expectation: mark recovered parcel. A false condition throws and makes the test run fail. |
| 241 | <code>    check(f.parcels.resumeParcel(&quot;P1&quot;, Route::CampusDelivery, f.services), &quot;resume recovered parcel&quot;);</code> | Check the test expectation: resume recovered parcel. A false condition throws and makes the test run fail. |
| 242 | <code>    f.assignAndProcess(&quot;R2&quot;, ResourceType::DeliveryPersonnel);</code> | Call `f.assignAndProcess` with the shown arguments. The call performs its named operation within testResourceInterruptionAndRecovery. |
| 243 | <code>    check(f.services.completeRequest(&quot;R2&quot;, RequestStatus::Returned, &quot;Unable to deliver&quot;, &quot;TP001&quot;, f.resources), &quot;return delivery&quot;);</code> | Check the test expectation: return delivery. A false condition throws and makes the test run fail. |
| 244 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::Returned, &quot;returned delivery status&quot;);</code> | Check the test expectation: returned delivery status. A false condition throws and makes the test run fail. |
| 245 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 246 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 247 | <code>void testCancellationAndHold() {</code> | Define `testCancellationAndHold`. Test intake hold, resume, active-deletion guards, pending cancellation and in-progress cancellation with release. |
| 248 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 249 | <code>    f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testCancellationAndHold. |
| 250 | <code>    f.registerResource(&quot;C1&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testCancellationAndHold. |
| 251 | <code>    check(f.parcels.processNext(Route::InvestigationHold, f.services), &quot;intake hold&quot;);</code> | Check the test expectation: intake hold. A false condition throws and makes the test run fail. |
| 252 | <code>    check(f.parcels.resumeParcel(&quot;P1&quot;, Route::Collection, f.services), &quot;resume held parcel&quot;);</code> | Check the test expectation: resume held parcel. A false condition throws and makes the test run fail. |
| 253 | <code>    check(!f.parcels.removeParcel(&quot;P1&quot;, f.services), &quot;removed active parcel&quot;);</code> | Check the test expectation: removed active parcel. A false condition throws and makes the test run fail. |
| 254 | <code>    check(!f.services.removeTerminalRequest(&quot;R1&quot;), &quot;removed active request&quot;);</code> | Check the test expectation: removed active request. A false condition throws and makes the test run fail. |
| 255 | <code>    check(f.services.cancelRequest(&quot;R1&quot;, f.resources), &quot;cancel pending request&quot;);</code> | Check the test expectation: cancel pending request. A false condition throws and makes the test run fail. |
| 256 | <code>    check(f.parcels.findParcel(&quot;P1&quot;)-&gt;status == ParcelStatus::Cancelled, &quot;parcel not cancelled&quot;);</code> | Check the test expectation: parcel not cancelled. A false condition throws and makes the test run fail. |
| 257 | <code>    check(f.services.removeTerminalRequest(&quot;R1&quot;), &quot;remove cancelled request&quot;);</code> | Check the test expectation: remove cancelled request. A false condition throws and makes the test run fail. |
| 258 | <code>    check(f.parcels.removeParcel(&quot;P1&quot;, f.services), &quot;remove cancelled parcel&quot;);</code> | Check the test expectation: remove cancelled parcel. A false condition throws and makes the test run fail. |
| 259 | <code>    f.registerParcel(&quot;TRACK2&quot;);</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testCancellationAndHold. |
| 260 | <code>    f.create(ServiceType::Collection, &quot;P2&quot;);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testCancellationAndHold. |
| 261 | <code>    f.assignAndProcess(&quot;R2&quot;, ResourceType::CollectionCounter);</code> | Call `f.assignAndProcess` with the shown arguments. The call performs its named operation within testCancellationAndHold. |
| 262 | <code>    check(f.services.cancelRequest(&quot;R2&quot;, f.resources), &quot;cancel in-progress request&quot;);</code> | Check the test expectation: cancel in-progress request. A false condition throws and makes the test run fail. |
| 263 | <code>    check(f.resources.findResource(&quot;C1&quot;)-&gt;status == ResourceStatus::Available, &quot;cancel did not release resource&quot;);</code> | Check the test expectation: cancel did not release resource. A false condition throws and makes the test run fail. |
| 264 | <code>    check(!f.services.cancelRequest(&quot;R2&quot;, f.resources), &quot;cancel twice&quot;);</code> | Check the test expectation: cancel twice. A false condition throws and makes the test run fail. |
| 265 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 266 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 267 | <code>void testPriorityAndRoundRobin() {</code> | Define `testPriorityAndRoundRobin`. Verify urgent-first FIFO recommendations, alternating counters, all-busy failure and reuse after manual release. |
| 268 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 269 | <code>    f.registerResource(&quot;C1&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 270 | <code>    f.registerResource(&quot;C2&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 271 | <code>    f.registerParcel(&quot;A&quot;); f.registerParcel(&quot;B&quot;); f.registerParcel(&quot;C&quot;);</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 272 | <code>    f.create(ServiceType::Collection, &quot;P1&quot;);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 273 | <code>    f.create(ServiceType::Collection, &quot;P2&quot;, RequestPriority::Urgent);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 274 | <code>    f.create(ServiceType::Collection, &quot;P3&quot;, RequestPriority::Urgent);</code> | Call `f.create` with the shown arguments. The call performs its named operation within testPriorityAndRoundRobin. |
| 275 | <code>    check(f.services.nextRequest()-&gt;id == &quot;R2&quot;, &quot;urgent FIFO recommendation&quot;);</code> | Check the test expectation: urgent FIFO recommendation. A false condition throws and makes the test run fail. |
| 276 | <code>    check(f.resources.assignRequest(&quot;R2&quot;, ResourceType::CollectionCounter), &quot;allocate first counter&quot;);</code> | Check the test expectation: allocate first counter. A false condition throws and makes the test run fail. |
| 277 | <code>    check(f.services.findRequest(&quot;R2&quot;)-&gt;resourceId == &quot;C1&quot;, &quot;first round-robin counter&quot;);</code> | Check the test expectation: first round-robin counter. A false condition throws and makes the test run fail. |
| 278 | <code>    check(f.services.nextRequest()-&gt;id == &quot;R3&quot;, &quot;next equal-priority request&quot;);</code> | Check the test expectation: next equal-priority request. A false condition throws and makes the test run fail. |
| 279 | <code>    check(f.resources.assignRequest(&quot;R3&quot;, ResourceType::CollectionCounter), &quot;allocate second counter&quot;);</code> | Check the test expectation: allocate second counter. A false condition throws and makes the test run fail. |
| 280 | <code>    check(f.services.findRequest(&quot;R3&quot;)-&gt;resourceId == &quot;C2&quot;, &quot;second round-robin counter&quot;);</code> | Check the test expectation: second round-robin counter. A false condition throws and makes the test run fail. |
| 281 | <code>    check(!f.resources.assignRequest(&quot;R1&quot;, ResourceType::CollectionCounter), &quot;all occupied allocation&quot;);</code> | Check the test expectation: all occupied allocation. A false condition throws and makes the test run fail. |
| 282 | <code>    check(f.resources.releaseResource(&quot;C1&quot;), &quot;manual release&quot;);</code> | Check the test expectation: manual release. A false condition throws and makes the test run fail. |
| 283 | <code>    check(f.services.findRequest(&quot;R2&quot;)-&gt;status == RequestStatus::Pending, &quot;manual release did not requeue&quot;);</code> | Check the test expectation: manual release did not requeue. A false condition throws and makes the test run fail. |
| 284 | <code>    check(f.resources.assignRequest(&quot;R1&quot;, ResourceType::CollectionCounter), &quot;allocate after release&quot;);</code> | Check the test expectation: allocate after release. A false condition throws and makes the test run fail. |
| 285 | <code>    check(f.services.findRequest(&quot;R1&quot;)-&gt;resourceId == &quot;C1&quot;, &quot;round-robin wrap allocation&quot;);</code> | Check the test expectation: round-robin wrap allocation. A false condition throws and makes the test run fail. |
| 286 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 287 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 288 | <code>void testInvalidOperations() {</code> | Define `testInvalidOperations`. Reject nonexistent IDs, bad enums, wrong recipients, duplicate active work and invalid resource changes. |
| 289 | <code>    Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 290 | <code>    check(!f.services.nextRequest(), &quot;empty next request&quot;);</code> | Check the test expectation: empty next request. A false condition throws and makes the test run fail. |
| 291 | <code>    check(!f.services.processRequest(&quot;X&quot;), &quot;unknown request processing&quot;);</code> | Check the test expectation: unknown request processing. A false condition throws and makes the test run fail. |
| 292 | <code>    check(!f.services.cancelRequest(&quot;X&quot;, f.resources), &quot;unknown cancellation&quot;);</code> | Check the test expectation: unknown cancellation. A false condition throws and makes the test run fail. |
| 293 | <code>    check(!f.resources.assignRequest(&quot;X&quot;, ResourceType::CollectionCounter), &quot;unknown assignment&quot;);</code> | Check the test expectation: unknown assignment. A false condition throws and makes the test run fail. |
| 294 | <code>    check(!f.resources.releaseResource(&quot;X&quot;), &quot;unknown resource release&quot;);</code> | Check the test expectation: unknown resource release. A false condition throws and makes the test run fail. |
| 295 | <code>    check(!f.resources.updateStatus(&quot;X&quot;, ResourceStatus::Available), &quot;unknown resource update&quot;);</code> | Check the test expectation: unknown resource update. A false condition throws and makes the test run fail. |
| 296 | <code>    check(!f.parcels.processNext(static_cast&lt;Route&gt;(99), f.services), &quot;invalid route&quot;);</code> | Check the test expectation: invalid route. A false condition throws and makes the test run fail. |
| 297 | <code>    f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within testInvalidOperations. |
| 298 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 299 | <code>    request.parcelId = &quot;P1&quot;; request.recipientId = &quot;WRONG&quot;; request.serviceDetails = &quot;Collect&quot;;</code> | Set `request.parcelId` to `"P1"; request.recipientId = "WRONG"; request.serviceDetails = "Collect"`. |
| 300 | <code>    check(!f.services.createRequest(request), &quot;incorrect recipient request&quot;);</code> | Check the test expectation: incorrect recipient request. A false condition throws and makes the test run fail. |
| 301 | <code>    request.recipientId = &quot;TP001&quot;; request.type = static_cast&lt;ServiceType&gt;(99);</code> | Set `request.recipientId` to `"TP001"; request.type = static_cast<ServiceType>(99)`. |
| 302 | <code>    check(!f.services.createRequest(request), &quot;invalid service enum&quot;);</code> | Check the test expectation: invalid service enum. A false condition throws and makes the test run fail. |
| 303 | <code>    request.type = ServiceType::Collection; request.priority = static_cast&lt;RequestPriority&gt;(99);</code> | Set `request.type` to `ServiceType::Collection; request.priority = static_cast<RequestPriority>(99)`. |
| 304 | <code>    check(!f.services.createRequest(request), &quot;invalid priority&quot;);</code> | Check the test expectation: invalid priority. A false condition throws and makes the test run fail. |
| 305 | <code>    request.priority = RequestPriority::Normal;</code> | Set `request.priority` to `RequestPriority::Normal`. |
| 306 | <code>    check(f.services.createRequest(request), &quot;valid request after invalid requests&quot;);</code> | Check the test expectation: valid request after invalid requests. A false condition throws and makes the test run fail. |
| 307 | <code>    check(!f.services.createRequest(request), &quot;duplicate active request&quot;);</code> | Check the test expectation: duplicate active request. A false condition throws and makes the test run fail. |
| 308 | <code>    check(f.services.findRequest(&quot;R1&quot;) != nullptr, &quot;failed request consumed ID&quot;);</code> | Check the test expectation: failed request consumed ID. A false condition throws and makes the test run fail. |
| 309 | <code>    f.registerResource(&quot;C1&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within testInvalidOperations. |
| 310 | <code>    check(!f.resources.updateStatus(&quot;C1&quot;, ResourceStatus::Occupied), &quot;occupied without assignment&quot;);</code> | Check the test expectation: occupied without assignment. A false condition throws and makes the test run fail. |
| 311 | <code>    check(!f.resources.updateStatus(&quot;C1&quot;, static_cast&lt;ResourceStatus&gt;(99)), &quot;invalid resource status&quot;);</code> | Check the test expectation: invalid resource status. A false condition throws and makes the test run fail. |
| 312 | <code>    Resource duplicate;</code> | Create local `duplicate` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 313 | <code>    duplicate.id = &quot;C1&quot;; duplicate.name = &quot;Duplicate&quot;;</code> | Set `duplicate.id` to `"C1"; duplicate.name = "Duplicate"`. |
| 314 | <code>    check(!f.resources.registerResource(duplicate), &quot;duplicate resource ID&quot;);</code> | Check the test expectation: duplicate resource ID. A false condition throws and makes the test run fail. |
| 315 | <code>    check(!f.resources.updateResourceDetails(&quot;C1&quot;, &quot; \t&quot;), &quot;empty resource name&quot;);</code> | Check the test expectation: empty resource name. A false condition throws and makes the test run fail. |
| 316 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 317 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 318 | <code>int main() {</code> | Define `main`. Program entry point; execute the system/test suite and translate exceptions into an error message and nonzero exit code. |
| 319 | <code>    ostringstream captured;</code> | Create local `captured` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 320 | <code>    streambuf* original = cout.rdbuf(captured.rdbuf());</code> | Create local `original` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 321 | <code>    try {</code> | Begin an exception-protected operation whose failures are handled by the following catch. |
| 322 | <code>        testLinkedStructures();</code> | Call `testLinkedStructures` with the shown arguments. Exercise empty/one/multiple-node lists, deletion boundaries, FIFO, priority stability, ring wrap and independent mixed-type cursors. |
| 323 | <code>        testParcelValidation();</code> | Call `testParcelValidation` with the shown arguments. Verify required fields, duplicate tracking, edit protection, cancellation/deletion and FIFO behavior after removal. |
| 324 | <code>        testEveryServiceLifecycle();</code> | Call `testEveryServiceLifecycle` with the shown arguments. Run every service type from direct request creation through assignment/processing/completion and verify all three records. |
| 325 | <code>        testFailedCompletionIsUnchanged();</code> | Call `testFailedCompletionIsUnchanged` with the shown arguments. Reject wrong recipient, blank details, invalid outcome and unsafe parcel edits; verify existing parcel/request/resource state remains unchanged before a successful retry. |
| 326 | <code>        testResourceInterruptionAndRecovery();</code> | Call `testResourceInterruptionAndRecovery` with the shown arguments. Test wrong/busy/unavailable resource handling and an in-progress parcel reported Missing, recovered to OnHold, resumed and returned. |
| 327 | <code>        testCancellationAndHold();</code> | Call `testCancellationAndHold` with the shown arguments. Test intake hold, resume, active-deletion guards, pending cancellation and in-progress cancellation with release. |
| 328 | <code>        testPriorityAndRoundRobin();</code> | Call `testPriorityAndRoundRobin` with the shown arguments. Verify urgent-first FIFO recommendations, alternating counters, all-busy failure and reuse after manual release. |
| 329 | <code>        testInvalidOperations();</code> | Call `testInvalidOperations` with the shown arguments. Reject nonexistent IDs, bad enums, wrong recipients, duplicate active work and invalid resource changes. |
| 330 | <code>        // repeat object lifetimes to exercise deletion of nonempty linked structures</code> | Comment explaining intent: repeat object lifetimes to exercise deletion of nonempty linked structures |
| 331 | <code>        for (int i = 0; i &lt; 100; i++) {</code> | Run the counted/traversal loop `for (int i = 0; i < 100; i++) {`. Its initialization, condition and increment control each iteration. |
| 332 | <code>            Fixture f;</code> | Create local `f` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 333 | <code>            f.registerParcel();</code> | Call `f.registerParcel` with the shown arguments. The call performs its named operation within main. |
| 334 | <code>            f.registerResource(&quot;C1&quot;, ResourceType::CollectionCounter);</code> | Call `f.registerResource` with the shown arguments. The call performs its named operation within main. |
| 335 | <code>            f.create(ServiceType::Collection);</code> | Call `f.create` with the shown arguments. The call performs its named operation within main. |
| 336 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 337 | <code>        cout.rdbuf(original);</code> | Call `cout.rdbuf` with the shown arguments. The call performs its named operation within main. |
| 338 | <code>        cout &lt;&lt; &quot;PASS: 8 suites, &quot; &lt;&lt; checks &lt;&lt; &quot; checks, including 100 lifetime cycles.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 339 | <code>        return 0;</code> | Return normal exit/back/EOF value for this function. |
| 340 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 341 | <code>    catch (const exception&amp; error) {</code> | Handle the selected exception; perform rollback or restore captured output before reporting the failure. |
| 342 | <code>        cout.rdbuf(original);</code> | Call `cout.rdbuf` with the shown arguments. The call performs its named operation within main. |
| 343 | <code>        cerr &lt;&lt; &quot;FAIL after &quot; &lt;&lt; checks &lt;&lt; &quot; checks: &quot; &lt;&lt; error.what() &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue the error message to standard error. |
| 344 | <code>        return 1;</code> | Return a nonzero failure exit code. |
| 345 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 346 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
