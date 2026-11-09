# src/task2.cpp - every line explained

Source: [src/task2.cpp](../../src/task2.cpp)

Physical lines: 251; SHA-256 (LF text): `74c3978e4c235a4d08954287e7b3895570ae69dca5bd2957e88538cb81929130`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#include &quot;task2.hpp&quot;</code> | Include `"task2.hpp"` for Task 2 declarations. |
| 2 | <code>#include &quot;task1.hpp&quot;</code> | Include `"task1.hpp"` for Task 1 declarations. |
| 3 | <code>#include &quot;task3.hpp&quot;</code> | Include `"task3.hpp"` for Task 3 declarations. |
| 4 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 5 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 6 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 7 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 8 | <code>RequestQueue::~RequestQueue() {</code> | Define `RequestQueue::~RequestQueue`. Delete all retained request nodes, including active and terminal records. |
| 9 | <code>    while (head != nullptr) {</code> | Repeat while `(head != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 10 | <code>        Node* next = head-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 11 | <code>        delete head;</code> | Release the node at `head`. Its successor was saved before deletion. |
| 12 | <code>        head = next;</code> | Set `head` to `next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 13 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 14 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 15 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 16 | <code>bool RequestQueue::insert(const ServiceRequest&amp; request) {</code> | Define `RequestQueue::insert`. Reject duplicate IDs and insert by priority then sequence. Earlier/equal sequences remain ahead, preserving stable FIFO ties. |
| 17 | <code>    if (trim(request.id).empty() &#124;&#124; find(request.id) != nullptr) return false;</code> | Test `trim(request.id).empty() &#124;&#124; find(request.id) != nullptr`. Return failure or a false predicate without claiming success. |
| 18 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 19 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 20 | <code>    while (current != nullptr) {</code> | Repeat while `(current != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 21 | <code>        bool earlierPriority = current-&gt;value.priority &lt; request.priority;</code> | Create local `earlierPriority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 22 | <code>        bool earlierSequence = current-&gt;value.priority == request.priority</code> | Create local `earlierSequence` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 23 | <code>            &amp;&amp; current-&gt;value.sequence &lt;= request.sequence;</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 24 | <code>        if (!earlierPriority &amp;&amp; !earlierSequence) break;</code> | Test `!earlierPriority && !earlierSequence`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 25 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 26 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 27 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 28 | <code>    Node* node = new Node{request, current};</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. |
| 29 | <code>    if (previous == nullptr) head = node;</code> | Test `previous == nullptr`. Set `head` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 30 | <code>    else previous-&gt;next = node;</code> | When the preceding condition is false, Set `previous->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 31 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 32 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 33 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 34 | <code>ServiceRequest* RequestQueue::find(const string&amp; id) {</code> | Define `RequestQueue::find`. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 35 | <code>    for (Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 36 | <code>        if (current-&gt;value.id == id) return &amp;current-&gt;value;</code> | Test `current->value.id == id`. Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 37 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 38 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 39 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 40 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 41 | <code>const ServiceRequest* RequestQueue::find(const string&amp; id) const {</code> | Define `RequestQueue::find`. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 42 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 43 | <code>        if (current-&gt;value.id == id) return &amp;current-&gt;value;</code> | Test `current->value.id == id`. Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 44 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 45 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 46 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 47 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 48 | <code>const ServiceRequest* RequestQueue::nextPending() const {</code> | Define `RequestQueue::nextPending`. Find the first Pending node in priority order, skipping assigned, in-progress and terminal records. |
| 49 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 50 | <code>        if (current-&gt;value.status == RequestStatus::Pending) return &amp;current-&gt;value;</code> | Test `current->value.status == RequestStatus::Pending`. Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 51 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 52 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 53 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 54 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 55 | <code>bool RequestQueue::remove(const string&amp; id) {</code> | Define `RequestQueue::remove`. Bypass and delete a specified request node, with a separate head case. |
| 56 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 57 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 58 | <code>    while (current != nullptr &amp;&amp; current-&gt;value.id != id) {</code> | Repeat while `(current != nullptr && current->value.id != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 59 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 60 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 61 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 62 | <code>    if (current == nullptr) return false;</code> | Test `current == nullptr`. Return failure or a false predicate without claiming success. |
| 63 | <code>    if (previous == nullptr) head = current-&gt;next;</code> | Test `previous == nullptr`. Set `head` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 64 | <code>    else previous-&gt;next = current-&gt;next;</code> | When the preceding condition is false, Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 65 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 66 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 67 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 68 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 69 | <code>bool RequestQueue::hasActiveForParcel(const string&amp; id) const {</code> | Define `RequestQueue::hasActiveForParcel`. Detect whether a parcel already has Pending, Assigned or InProgress work. |
| 70 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 71 | <code>        if (current-&gt;value.parcelId == id &amp;&amp; isActive(current-&gt;value.status)) return true;</code> | Test `current->value.parcelId == id && isActive(current->value.status)`. Return success or a true predicate to the caller. |
| 72 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 73 | <code>    return false;</code> | Return failure or a false predicate without claiming success. |
| 74 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 75 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 76 | <code>void RequestQueue::displayActive() const {</code> | Define `RequestQueue::displayActive`. Print only active requests while tracking whether an empty-result message is needed. |
| 77 | <code>    bool found = false;</code> | Create local `found` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 78 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 79 | <code>        if (isActive(current-&gt;value.status)) {</code> | Test `isActive(current->value.status)`. Run the following guarded block only when true. |
| 80 | <code>            printRequest(current-&gt;value);</code> | Call `printRequest` with the shown arguments. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 81 | <code>            found = true;</code> | Set `found` to `true`. |
| 82 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 83 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 84 | <code>    if (!found) cout &lt;&lt; &quot;No active service requests.\n&quot;;</code> | Test `!found`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 85 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 87 | <code>bool ServiceModule::createRequest(ServiceRequest request) {</code> | Define `ServiceModule::createRequest`. Validate recipient/service/priority/parcel eligibility, insert a generated request, then synchronize parcel status and remove intake membership. Terminal and missing parcels are ineligible. |
| 88 | <code>    request.parcelId = trim(request.parcelId);</code> | Set `request.parcelId` to `trim(request.parcelId)`. |
| 89 | <code>    request.recipientId = trim(request.recipientId);</code> | Set `request.recipientId` to `trim(request.recipientId)`. |
| 90 | <code>    request.serviceDetails = trim(request.serviceDetails);</code> | Set `request.serviceDetails` to `trim(request.serviceDetails)`. |
| 91 | <code>    Parcel* parcel = parcels.records.find(request.parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 92 | <code>    if (parcel == nullptr &#124;&#124; request.recipientId.empty() &#124;&#124; request.recipientId != parcel-&gt;recipientId</code> | Begin a multiline guard with `parcel == nullptr &#124;&#124; request.recipientId.empty() &#124;&#124; request.recipientId != parcel->recipientId`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 93 | <code>        &#124;&#124; request.serviceDetails.empty() &#124;&#124; !validService(request.type)</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 94 | <code>        &#124;&#124; (request.priority != RequestPriority::Urgent &amp;&amp; request.priority != RequestPriority::Normal)</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 95 | <code>        &#124;&#124; requests.hasActiveForParcel(request.parcelId)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 96 | <code>        cout &lt;&lt; &quot;Invalid parcel, recipient, service details, priority, or duplicate active request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 97 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 98 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 99 | <code>    if (isTerminal(parcel-&gt;status) &#124;&#124; parcel-&gt;status == ParcelStatus::Missing</code> | Begin a multiline guard with `isTerminal(parcel->status) &#124;&#124; parcel->status == ParcelStatus::Missing`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 100 | <code>        &#124;&#124; (parcel-&gt;status != ParcelStatus::Received &amp;&amp; parcel-&gt;status != ParcelStatus::OnHold</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 101 | <code>            &amp;&amp; parcel-&gt;status != serviceStatus(request.type))) {</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 102 | <code>        cout &lt;&lt; &quot;Parcel status does not allow this service.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 103 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 104 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 105 | <code>    request.id = &quot;R&quot; + to_string(nextRequestNumber);</code> | Set `request.id` to `"R" + to_string(nextRequestNumber)`. |
| 106 | <code>    request.createdAt = currentTimestamp();</code> | Set `request.createdAt` to `currentTimestamp()`. |
| 107 | <code>    request.sequence = nextSequence;</code> | Set `request.sequence` to `nextSequence`. |
| 108 | <code>    request.status = RequestStatus::Pending;</code> | Set `request.status` to `RequestStatus::Pending`. This is a lifecycle/availability change performed after the required guards. |
| 109 | <code>    request.resourceId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 110 | <code>    request.outcomeDetails.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 111 | <code>    if (!requests.insert(request)) return false;</code> | Test `!requests.insert(request)`. Return failure or a false predicate without claiming success. |
| 112 | <code>    // insertion is the last allocating operation; commit the parcel after it succeeds</code> | Comment explaining intent: insertion is the last allocating operation; commit the parcel after it succeeds |
| 113 | <code>    parcel-&gt;status = serviceStatus(request.type);</code> | Set `parcel->status` to `serviceStatus(request.type)`. This is a lifecycle/availability change performed after the required guards. |
| 114 | <code>    parcels.waiting.remove(request.parcelId);</code> | Call `parcels.waiting.remove` with the shown arguments. The call performs its named operation within ServiceModule::createRequest. |
| 115 | <code>    nextRequestNumber++;</code> | Increment `nextRequestNumber` only at this point in the successful operation/test count. |
| 116 | <code>    nextSequence++;</code> | Increment `nextSequence` only at this point in the successful operation/test count. |
| 117 | <code>    cout &lt;&lt; &quot;Created request &quot; &lt;&lt; request.id &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 118 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 119 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 120 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 121 | <code>void ServiceModule::displayActiveRequests() const {</code> | Define `ServiceModule::displayActiveRequests`. Delegate active-request display to the sorted list. |
| 122 | <code>    requests.displayActive();</code> | Call `requests.displayActive` with the shown arguments. The call performs its named operation within ServiceModule::displayActiveRequests. |
| 123 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 124 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 125 | <code>const ServiceRequest* ServiceModule::findRequest(const string&amp; id) const {</code> | Define `ServiceModule::findRequest`. Find retained work for read-only inspection and report an unknown ID. |
| 126 | <code>    const ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 127 | <code>    if (request == nullptr) cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Test `request == nullptr`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 128 | <code>    return request;</code> | Return the value of `request` to the caller. This ends the function once its full return expression is evaluated. |
| 129 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 130 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 131 | <code>const ServiceRequest* ServiceModule::nextRequest() const {</code> | Define `ServiceModule::nextRequest`. Expose the first Pending recommendation, or explain that none exists. Staff may explicitly select another ID. |
| 132 | <code>    const ServiceRequest* request = requests.nextPending();</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 133 | <code>    if (request == nullptr) cout &lt;&lt; &quot;No pending request.\n&quot;;</code> | Test `request == nullptr`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 134 | <code>    return request;</code> | Return the value of `request` to the caller. This ends the function once its full return expression is evaluated. |
| 135 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 136 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 137 | <code>bool ServiceModule::parcelMatches(const ServiceRequest&amp; request) const {</code> | Define `ServiceModule::parcelMatches`. Check the core active-request invariant: its parcel exists, service is valid, recipient matches and parcel status fits the service. |
| 138 | <code>    const Parcel* parcel = parcels.records.find(request.parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 139 | <code>    return parcel != nullptr &amp;&amp; validService(request.type)</code> | Return the value of `parcel != nullptr && validService(request.type)` to the caller. This ends the function once its full return expression is evaluated. |
| 140 | <code>        &amp;&amp; parcel-&gt;recipientId == request.recipientId &amp;&amp; parcel-&gt;status == serviceStatus(request.type);</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 141 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 142 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 143 | <code>bool ServiceModule::processRequest(const string&amp; id) {</code> | Define `ServiceModule::processRequest`. Move only an assigned request with matching parcel/resource metadata to InProgress. |
| 144 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 145 | <code>    if (request == nullptr &#124;&#124; request-&gt;status != RequestStatus::Assigned</code> | Begin a multiline guard with `request == nullptr &#124;&#124; request->status != RequestStatus::Assigned`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 146 | <code>        &#124;&#124; request-&gt;resourceId.empty() &#124;&#124; !parcelMatches(*request)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 147 | <code>        cout &lt;&lt; &quot;Request must have a matching parcel and assigned resource.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 148 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 149 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 150 | <code>    request-&gt;status = RequestStatus::InProgress;</code> | Set `request->status` to `RequestStatus::InProgress`. This is a lifecycle/availability change performed after the required guards. |
| 151 | <code>    cout &lt;&lt; &quot;Request is now in progress.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 152 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 153 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 154 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 155 | <code>bool ServiceModule::completeRequest(const string&amp; id, RequestStatus outcome, const string&amp; details,</code> | Begin the multiline signature of `ServiceModule::completeRequest`. Validate processing state, outcome, details, recipient, parcel and assignment before any release. Calculate the result, release the resource, commit final statuses and swap prepared outcome text. |
| 156 | <code>                                    const string&amp; recipientId, ResourceModule&amp; resources) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 157 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 158 | <code>    string savedDetails = trim(details);</code> | Create local `savedDetails` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 159 | <code>    if (request == nullptr &#124;&#124; request-&gt;status != RequestStatus::InProgress</code> | Begin a multiline guard with `request == nullptr &#124;&#124; request->status != RequestStatus::InProgress`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 160 | <code>        &#124;&#124; (outcome != RequestStatus::Completed &amp;&amp; outcome != RequestStatus::Returned)</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 161 | <code>        &#124;&#124; savedDetails.empty() &#124;&#124; trim(recipientId) != request-&gt;recipientId</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 162 | <code>        &#124;&#124; !parcelMatches(*request) &#124;&#124; !resources.canReleaseRequest(id)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 163 | <code>        cout &lt;&lt; &quot;Completion rejected: check processing state, recipient, details and assignment.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 164 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 165 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 166 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 167 | <code>    ParcelStatus target = ParcelStatus::OnHold;</code> | Create local `target` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 168 | <code>    // finishing a return service always means Returned, even if staff chose Completed</code> | Comment explaining intent: finishing a return service always means Returned, even if staff chose Completed |
| 169 | <code>    if (outcome == RequestStatus::Returned &#124;&#124; request-&gt;type == ServiceType::ReturnToSender) {</code> | Test `outcome == RequestStatus::Returned &#124;&#124; request->type == ServiceType::ReturnToSender`. Run the following guarded block only when true. |
| 170 | <code>        target = ParcelStatus::Returned;</code> | Set `target` to `ParcelStatus::Returned`. |
| 171 | <code>        outcome = RequestStatus::Returned;</code> | Set `outcome` to `RequestStatus::Returned`. |
| 172 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 173 | <code>    else if (request-&gt;type == ServiceType::Collection) target = ParcelStatus::Collected;</code> | Otherwise, test `request->type == ServiceType::Collection`. Set `target` to `ParcelStatus::Collected`. |
| 174 | <code>    else if (request-&gt;type == ServiceType::CampusDelivery &#124;&#124; request-&gt;type == ServiceType::Redelivery)</code> | Begin a multiline guard with `request->type == ServiceType::CampusDelivery &#124;&#124; request->type == ServiceType::Redelivery)`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 175 | <code>        target = ParcelStatus::Delivered;</code> | Set `target` to `ParcelStatus::Delivered`. |
| 176 | <code>    // every validation and string allocation happens before changing the three records</code> | Comment explaining intent: every validation and string allocation happens before changing the three records |
| 177 | <code>    if (!resources.releaseForRequest(id)) return false;</code> | Test `!resources.releaseForRequest(id)`. Return failure or a false predicate without claiming success. |
| 178 | <code>    parcel-&gt;status = target;</code> | Set `parcel->status` to `target`. This is a lifecycle/availability change performed after the required guards. |
| 179 | <code>    request-&gt;status = outcome;</code> | Set `request->status` to `outcome`. This is a lifecycle/availability change performed after the required guards. |
| 180 | <code>    request-&gt;outcomeDetails.swap(savedDetails);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 181 | <code>    cout &lt;&lt; &quot;Request finished. Parcel status: &quot; &lt;&lt; toString(target) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 182 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 183 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 184 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 185 | <code>bool ServiceModule::cancelRequest(const string&amp; id, ResourceModule&amp; resources) {</code> | Define `ServiceModule::cancelRequest`. Validate active work and links, release any assignment, and end both request and parcel as Cancelled. |
| 186 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 187 | <code>    if (request == nullptr &#124;&#124; !isActive(request-&gt;status) &#124;&#124; !parcelMatches(*request)</code> | Begin a multiline guard with `request == nullptr &#124;&#124; !isActive(request->status) &#124;&#124; !parcelMatches(*request)`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 188 | <code>        &#124;&#124; !resources.canReleaseRequest(id)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 189 | <code>        cout &lt;&lt; &quot;Request cannot be cancelled.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 190 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 191 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 192 | <code>    string details = &quot;Cancelled by staff&quot;;</code> | Create local `details` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 193 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 194 | <code>    if (!resources.releaseForRequest(id)) return false;</code> | Test `!resources.releaseForRequest(id)`. Return failure or a false predicate without claiming success. |
| 195 | <code>    parcel-&gt;status = ParcelStatus::Cancelled;</code> | Set `parcel->status` to `ParcelStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 196 | <code>    request-&gt;status = RequestStatus::Cancelled;</code> | Set `request->status` to `RequestStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 197 | <code>    request-&gt;outcomeDetails.swap(details);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 198 | <code>    cout &lt;&lt; &quot;Request and parcel cancelled.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 199 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 200 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 201 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 202 | <code>bool ServiceModule::interruptRequest(const string&amp; id, ParcelStatus status, ResourceModule&amp; resources) {</code> | Define `ServiceModule::interruptRequest`. Stop active work for Missing/OnHold, release its resource, close the request as Cancelled and preserve the parcel recovery path. |
| 203 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 204 | <code>    if (request == nullptr &#124;&#124; !isActive(request-&gt;status) &#124;&#124; !parcelMatches(*request)</code> | Begin a multiline guard with `request == nullptr &#124;&#124; !isActive(request->status) &#124;&#124; !parcelMatches(*request)`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 205 | <code>        &#124;&#124; (status != ParcelStatus::Missing &amp;&amp; status != ParcelStatus::OnHold)</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 206 | <code>        &#124;&#124; !resources.canReleaseRequest(id)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 207 | <code>        cout &lt;&lt; &quot;Request cannot be interrupted with this parcel status.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 208 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 209 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 210 | <code>    string details = status == ParcelStatus::Missing ? &quot;Stopped: parcel missing&quot; : &quot;Stopped: investigation hold&quot;;</code> | Create local `details` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 211 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 212 | <code>    if (!resources.releaseForRequest(id)) return false;</code> | Test `!resources.releaseForRequest(id)`. Return failure or a false predicate without claiming success. |
| 213 | <code>    parcel-&gt;status = status;</code> | Set `parcel->status` to `status`. This is a lifecycle/availability change performed after the required guards. |
| 214 | <code>    request-&gt;status = RequestStatus::Cancelled;</code> | Set `request->status` to `RequestStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 215 | <code>    request-&gt;outcomeDetails.swap(details);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 216 | <code>    cout &lt;&lt; &quot;Request stopped. Parcel status: &quot; &lt;&lt; toString(status) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 217 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 218 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 219 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 220 | <code>bool ServiceModule::removeTerminalRequest(const string&amp; id) {</code> | Define `ServiceModule::removeTerminalRequest`. Reject active or still-assigned work; explicitly delete only a terminal retained request. |
| 221 | <code>    const ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 222 | <code>    if (request == nullptr &#124;&#124; isActive(request-&gt;status) &#124;&#124; !request-&gt;resourceId.empty()) {</code> | Test `request == nullptr &#124;&#124; isActive(request->status) &#124;&#124; !request->resourceId.empty()`. Run the following guarded block only when true. |
| 223 | <code>        cout &lt;&lt; &quot;Only terminal, unassigned requests can be removed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 224 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 225 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 226 | <code>    return requests.remove(id);</code> | Return the value of `requests.remove(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 227 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 228 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 229 | <code>bool ServiceModule::hasActiveRequestForParcel(const string&amp; id) const {</code> | Define `ServiceModule::hasActiveRequestForParcel`. Expose an active-work predicate for Task 1 deletion/edit/status guards. |
| 230 | <code>    return requests.hasActiveForParcel(id);</code> | Return the value of `requests.hasActiveForParcel(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 231 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 232 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 233 | <code>bool ServiceModule::attachResource(const string&amp; id, const string&amp; resourceId) {</code> | Define `ServiceModule::attachResource`. Private allocation hook: attach only Pending, unassigned, parcel-consistent work, then mark it Assigned. |
| 234 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 235 | <code>    if (request == nullptr &#124;&#124; request-&gt;status != RequestStatus::Pending</code> | Begin a multiline guard with `request == nullptr &#124;&#124; request->status != RequestStatus::Pending`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 236 | <code>        &#124;&#124; !request-&gt;resourceId.empty() &#124;&#124; resourceId.empty() &#124;&#124; !parcelMatches(*request)) return false;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 237 | <code>    request-&gt;resourceId = resourceId;</code> | Set `request->resourceId` to `resourceId`. |
| 238 | <code>    request-&gt;status = RequestStatus::Assigned;</code> | Set `request->status` to `RequestStatus::Assigned`. This is a lifecycle/availability change performed after the required guards. |
| 239 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 240 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 241 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 242 | <code>bool ServiceModule::detachResource(const string&amp; id) {</code> | Define `ServiceModule::detachResource`. Private release hook: clear the resource and return Assigned/InProgress work to Pending. Completion commits its terminal state immediately afterwards. |
| 243 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 244 | <code>    if (request == nullptr &#124;&#124; (request-&gt;status != RequestStatus::Assigned</code> | Begin a multiline guard with `request == nullptr &#124;&#124; (request->status != RequestStatus::Assigned`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 245 | <code>        &amp;&amp; request-&gt;status != RequestStatus::InProgress)) return false;</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 246 | <code>    request-&gt;resourceId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 247 | <code>    request-&gt;status = RequestStatus::Pending;</code> | Set `request->status` to `RequestStatus::Pending`. This is a lifecycle/availability change performed after the required guards. |
| 248 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 249 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 250 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 251 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
