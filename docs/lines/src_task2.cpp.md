# src/task2.cpp - every line explained

Source: [src/task2.cpp](../../src/task2.cpp)

Physical lines: 402; SHA-256 (LF text): `941f300e2d128b8043d43ce7ccacfbccf55bb86c2636b84fe74eb16b90fcad64`.

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
| 17 | <code>    if (trim(request.id).empty() &#124;&#124; find(request.id) != nullptr) {</code> | Test `trim(request.id).empty() &#124;&#124; find(request.id) != nullptr`. Run the following guarded block only when true. |
| 18 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 19 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 20 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 21 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 22 | <code>    while (current != nullptr) {</code> | Repeat while `(current != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 23 | <code>        bool earlierPriority = current-&gt;value.priority &lt; request.priority;</code> | Create local `earlierPriority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 24 | <code>        bool earlierSequence = current-&gt;value.priority == request.priority</code> | Create local `earlierSequence` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 25 | <code>            &amp;&amp; current-&gt;value.sequence &lt;= request.sequence;</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 26 | <code>        if (!earlierPriority &amp;&amp; !earlierSequence) {</code> | Test `!earlierPriority && !earlierSequence`. Run the following guarded block only when true. |
| 27 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 28 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 29 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 30 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 31 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 32 | <code>    Node* node = new Node{request}; // allocate with the record before changing any links</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. Comment: allocate with the record before changing any links |
| 33 | <code>    node-&gt;next = current;</code> | Set `node->next` to `current`. This rewires a link or advances an ownership/queue boundary pointer. |
| 34 | <code>    if (previous == nullptr) {</code> | Test `previous == nullptr`. Run the following guarded block only when true. |
| 35 | <code>        head = node;</code> | Set `head` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 36 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 37 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 38 | <code>        previous-&gt;next = node;</code> | Set `previous->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 39 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 40 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 41 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 42 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 43 | <code>ServiceRequest* RequestQueue::find(const string&amp; id) {</code> | Define `RequestQueue::find`. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 44 | <code>    for (Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 45 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 46 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 47 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 48 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 49 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 50 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 51 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 52 | <code>const ServiceRequest* RequestQueue::find(const string&amp; id) const {</code> | Define `RequestQueue::find`. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 53 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 54 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 55 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 56 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 57 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 58 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 59 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 60 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 61 | <code>const ServiceRequest* RequestQueue::nextPending() const {</code> | Define `RequestQueue::nextPending`. Find the first Pending node in priority order, skipping assigned, in-progress and terminal records. |
| 62 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 63 | <code>        if (current-&gt;value.status == RequestStatus::Pending) {</code> | Test `current->value.status == RequestStatus::Pending`. Run the following guarded block only when true. |
| 64 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 65 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 66 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 67 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 68 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 69 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 70 | <code>bool RequestQueue::remove(const string&amp; id) {</code> | Define `RequestQueue::remove`. Bypass and delete a specified request node, with a separate head case. |
| 71 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 72 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 73 | <code>    while (current != nullptr &amp;&amp; current-&gt;value.id != id) {</code> | Repeat while `(current != nullptr && current->value.id != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 74 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 75 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 76 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 77 | <code>    if (current == nullptr) {</code> | Test `current == nullptr`. Run the following guarded block only when true. |
| 78 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 79 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 80 | <code>    if (previous == nullptr) {</code> | Test `previous == nullptr`. Run the following guarded block only when true. |
| 81 | <code>        head = current-&gt;next;</code> | Set `head` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 82 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 83 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 84 | <code>        previous-&gt;next = current-&gt;next;</code> | Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 85 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 87 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 88 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 89 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 90 | <code>bool RequestQueue::hasActiveForParcel(const string&amp; id) const {</code> | Define `RequestQueue::hasActiveForParcel`. Detect whether a parcel already has Pending, Assigned or InProgress work. |
| 91 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 92 | <code>        if (current-&gt;value.parcelId == id &amp;&amp; isActive(current-&gt;value.status)) {</code> | Test `current->value.parcelId == id && isActive(current->value.status)`. Run the following guarded block only when true. |
| 93 | <code>            return true;</code> | Return success or a true predicate to the caller. |
| 94 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 95 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 96 | <code>    return false;</code> | Return failure or a false predicate without claiming success. |
| 97 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 98 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 99 | <code>void RequestQueue::displayActive() const {</code> | Define `RequestQueue::displayActive`. Print only active requests while tracking whether an empty-result message is needed. |
| 100 | <code>    bool found = false;</code> | Create local `found` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 101 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 102 | <code>        if (isActive(current-&gt;value.status)) {</code> | Test `isActive(current->value.status)`. Run the following guarded block only when true. |
| 103 | <code>            printRequest(current-&gt;value);</code> | Call `printRequest` with the shown arguments. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 104 | <code>            found = true;</code> | Set `found` to `true`. |
| 105 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 106 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 107 | <code>    if (!found) {</code> | Test `!found`. Run the following guarded block only when true. |
| 108 | <code>        cout &lt;&lt; &quot;No active service requests.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 109 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 110 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 111 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 112 | <code>bool ServiceModule::createRequest(ServiceRequest request) {</code> | Define `ServiceModule::createRequest`. Validate recipient/service/priority/parcel eligibility, insert a generated request, then synchronize parcel status and remove intake membership. Terminal and missing parcels are ineligible. |
| 113 | <code>    request.parcelId = trim(request.parcelId);</code> | Set `request.parcelId` to `trim(request.parcelId)`. |
| 114 | <code>    request.recipientId = trim(request.recipientId);</code> | Set `request.recipientId` to `trim(request.recipientId)`. |
| 115 | <code>    request.serviceDetails = trim(request.serviceDetails);</code> | Set `request.serviceDetails` to `trim(request.serviceDetails)`. |
| 116 | <code>    Parcel* parcel = parcels.records.find(request.parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 117 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 118 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 119 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 120 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 121 | <code>    if (request.recipientId.empty() &#124;&#124; request.recipientId != parcel-&gt;recipientId) {</code> | Test `request.recipientId.empty() &#124;&#124; request.recipientId != parcel->recipientId`. Run the following guarded block only when true. |
| 122 | <code>        cout &lt;&lt; &quot;Recipient ID does not match the parcel.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 123 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 124 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 125 | <code>    if (request.serviceDetails.empty()) {</code> | Test `request.serviceDetails.empty()`. Run the following guarded block only when true. |
| 126 | <code>        cout &lt;&lt; &quot;Service details are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 127 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 128 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 129 | <code>    if (!validService(request.type)) {</code> | Test `!validService(request.type)`. Run the following guarded block only when true. |
| 130 | <code>        cout &lt;&lt; &quot;Invalid service type.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 131 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 132 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 133 | <code>    if (request.priority != RequestPriority::Urgent &amp;&amp; request.priority != RequestPriority::Normal) {</code> | Test `request.priority != RequestPriority::Urgent && request.priority != RequestPriority::Normal`. Run the following guarded block only when true. |
| 134 | <code>        cout &lt;&lt; &quot;Invalid request priority.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 135 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 136 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 137 | <code>    if (requests.hasActiveForParcel(request.parcelId)) {</code> | Test `requests.hasActiveForParcel(request.parcelId)`. Run the following guarded block only when true. |
| 138 | <code>        cout &lt;&lt; &quot;Parcel already has an active request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 139 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 140 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 141 | <code>    if (isTerminal(parcel-&gt;status)) {</code> | Test `isTerminal(parcel->status)`. Run the following guarded block only when true. |
| 142 | <code>        cout &lt;&lt; &quot;Completed parcels cannot receive another service.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 143 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 144 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 145 | <code>    if (parcel-&gt;status == ParcelStatus::Missing) {</code> | Test `parcel->status == ParcelStatus::Missing`. Run the following guarded block only when true. |
| 146 | <code>        cout &lt;&lt; &quot;Recover the missing parcel before creating a service.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 147 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 148 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 149 | <code>    bool allowedStatus = parcel-&gt;status == ParcelStatus::Received</code> | Create local `allowedStatus` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 150 | <code>        &#124;&#124; parcel-&gt;status == ParcelStatus::OnHold</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 151 | <code>        &#124;&#124; parcel-&gt;status == serviceStatus(request.type);</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 152 | <code>    if (!allowedStatus) {</code> | Test `!allowedStatus`. Run the following guarded block only when true. |
| 153 | <code>        cout &lt;&lt; &quot;Parcel status does not allow this service.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 154 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 155 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 156 | <code>    request.id = &quot;R&quot; + to_string(nextRequestNumber);</code> | Set `request.id` to `"R" + to_string(nextRequestNumber)`. |
| 157 | <code>    request.createdAt = currentTimestamp();</code> | Set `request.createdAt` to `currentTimestamp()`. |
| 158 | <code>    request.sequence = nextSequence;</code> | Set `request.sequence` to `nextSequence`. |
| 159 | <code>    request.status = RequestStatus::Pending;</code> | Set `request.status` to `RequestStatus::Pending`. This is a lifecycle/availability change performed after the required guards. |
| 160 | <code>    request.resourceId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 161 | <code>    request.outcomeDetails.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 162 | <code>    if (!requests.insert(request)) {</code> | Test `!requests.insert(request)`. Run the following guarded block only when true. |
| 163 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 164 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 165 | <code>    // insertion is the last allocating operation; commit the parcel after it succeeds</code> | Comment explaining intent: insertion is the last allocating operation; commit the parcel after it succeeds |
| 166 | <code>    parcel-&gt;status = serviceStatus(request.type);</code> | Set `parcel->status` to `serviceStatus(request.type)`. This is a lifecycle/availability change performed after the required guards. |
| 167 | <code>    parcels.waiting.remove(request.parcelId);</code> | Call `parcels.waiting.remove` with the shown arguments. The call performs its named operation within ServiceModule::createRequest. |
| 168 | <code>    nextRequestNumber++;</code> | Increment `nextRequestNumber` only at this point in the successful operation/test count. |
| 169 | <code>    nextSequence++;</code> | Increment `nextSequence` only at this point in the successful operation/test count. |
| 170 | <code>    cout &lt;&lt; &quot;Created request &quot; &lt;&lt; request.id &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 171 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 172 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 173 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 174 | <code>void ServiceModule::displayActiveRequests() const {</code> | Define `ServiceModule::displayActiveRequests`. Delegate active-request display to the sorted list. |
| 175 | <code>    requests.displayActive();</code> | Call `requests.displayActive` with the shown arguments. The call performs its named operation within ServiceModule::displayActiveRequests. |
| 176 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 177 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 178 | <code>const ServiceRequest* ServiceModule::findRequest(const string&amp; id) const {</code> | Define `ServiceModule::findRequest`. Find retained work for read-only inspection and report an unknown ID. |
| 179 | <code>    const ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 180 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 181 | <code>        cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 182 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 183 | <code>    return request;</code> | Return the value of `request` to the caller. This ends the function once its full return expression is evaluated. |
| 184 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 185 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 186 | <code>const ServiceRequest* ServiceModule::nextRequest() const {</code> | Define `ServiceModule::nextRequest`. Expose the first Pending recommendation, or explain that none exists. Staff may explicitly select another ID. |
| 187 | <code>    const ServiceRequest* request = requests.nextPending();</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 188 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 189 | <code>        cout &lt;&lt; &quot;No pending request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 190 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 191 | <code>    return request;</code> | Return the value of `request` to the caller. This ends the function once its full return expression is evaluated. |
| 192 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 193 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 194 | <code>bool ServiceModule::parcelMatches(const ServiceRequest&amp; request) const {</code> | Define `ServiceModule::parcelMatches`. Check the core active-request invariant: its parcel exists, service is valid, recipient matches and parcel status fits the service. |
| 195 | <code>    const Parcel* parcel = parcels.records.find(request.parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 196 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 197 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 198 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 199 | <code>    if (!validService(request.type)) {</code> | Test `!validService(request.type)`. Run the following guarded block only when true. |
| 200 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 201 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 202 | <code>    if (parcel-&gt;recipientId != request.recipientId) {</code> | Test `parcel->recipientId != request.recipientId`. Run the following guarded block only when true. |
| 203 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 204 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 205 | <code>    if (parcel-&gt;status != serviceStatus(request.type)) {</code> | Test `parcel->status != serviceStatus(request.type)`. Run the following guarded block only when true. |
| 206 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 207 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 208 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 209 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 210 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 211 | <code>bool ServiceModule::processRequest(const string&amp; id) {</code> | Define `ServiceModule::processRequest`. Move only an assigned request with matching parcel/resource metadata to InProgress. |
| 212 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 213 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 214 | <code>        cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 215 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 216 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 217 | <code>    if (request-&gt;status != RequestStatus::Assigned &#124;&#124; request-&gt;resourceId.empty()) {</code> | Test `request->status != RequestStatus::Assigned &#124;&#124; request->resourceId.empty()`. Run the following guarded block only when true. |
| 218 | <code>        cout &lt;&lt; &quot;Assign a resource before processing the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 219 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 220 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 221 | <code>    if (!parcelMatches(*request)) {</code> | Test `!parcelMatches(*request)`. Run the following guarded block only when true. |
| 222 | <code>        cout &lt;&lt; &quot;Parcel details or status do not match the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 223 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 224 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 225 | <code>    request-&gt;status = RequestStatus::InProgress;</code> | Set `request->status` to `RequestStatus::InProgress`. This is a lifecycle/availability change performed after the required guards. |
| 226 | <code>    cout &lt;&lt; &quot;Request is now in progress.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 227 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 228 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 229 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 230 | <code>bool ServiceModule::completeRequest(const string&amp; id, RequestStatus outcome, const string&amp; details,</code> | Begin the multiline signature of `ServiceModule::completeRequest`. Validate processing state, outcome, details, recipient, parcel and assignment before any release. Calculate the result, release the resource, commit final statuses and swap prepared outcome text. |
| 231 | <code>                                    const string&amp; recipientId, ResourceModule&amp; resources) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 232 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 233 | <code>    string savedDetails = trim(details);</code> | Create local `savedDetails` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 234 | <code>    // validate one requirement at a time before releasing the resource</code> | Comment explaining intent: validate one requirement at a time before releasing the resource |
| 235 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 236 | <code>        cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 237 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 238 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 239 | <code>    if (request-&gt;status != RequestStatus::InProgress) {</code> | Test `request->status != RequestStatus::InProgress`. Run the following guarded block only when true. |
| 240 | <code>        cout &lt;&lt; &quot;Only an in-progress request can be completed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 241 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 242 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 243 | <code>    if (outcome != RequestStatus::Completed &amp;&amp; outcome != RequestStatus::Returned) {</code> | Test `outcome != RequestStatus::Completed && outcome != RequestStatus::Returned`. Run the following guarded block only when true. |
| 244 | <code>        cout &lt;&lt; &quot;Choose Completed or Returned as the outcome.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 245 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 246 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 247 | <code>    if (savedDetails.empty()) {</code> | Test `savedDetails.empty()`. Run the following guarded block only when true. |
| 248 | <code>        cout &lt;&lt; &quot;Completion details are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 249 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 250 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 251 | <code>    if (trim(recipientId) != request-&gt;recipientId) {</code> | Test `trim(recipientId) != request->recipientId`. Run the following guarded block only when true. |
| 252 | <code>        cout &lt;&lt; &quot;Recipient verification failed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 253 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 254 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 255 | <code>    if (!parcelMatches(*request)) {</code> | Test `!parcelMatches(*request)`. Run the following guarded block only when true. |
| 256 | <code>        cout &lt;&lt; &quot;Parcel details or status do not match the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 257 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 258 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 259 | <code>    if (!resources.canReleaseRequest(id)) {</code> | Test `!resources.canReleaseRequest(id)`. Run the following guarded block only when true. |
| 260 | <code>        cout &lt;&lt; &quot;Resource assignment is inconsistent.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 261 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 262 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 263 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 264 | <code>    ParcelStatus target = ParcelStatus::OnHold;</code> | Create local `target` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 265 | <code>    // finishing a return service always means Returned, even if staff chose Completed</code> | Comment explaining intent: finishing a return service always means Returned, even if staff chose Completed |
| 266 | <code>    if (outcome == RequestStatus::Returned &#124;&#124; request-&gt;type == ServiceType::ReturnToSender) {</code> | Test `outcome == RequestStatus::Returned &#124;&#124; request->type == ServiceType::ReturnToSender`. Run the following guarded block only when true. |
| 267 | <code>        target = ParcelStatus::Returned;</code> | Set `target` to `ParcelStatus::Returned`. |
| 268 | <code>        outcome = RequestStatus::Returned;</code> | Set `outcome` to `RequestStatus::Returned`. |
| 269 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 270 | <code>    else if (request-&gt;type == ServiceType::Collection) {</code> | Otherwise, test `request->type == ServiceType::Collection`. Run the following guarded block only when true. |
| 271 | <code>        target = ParcelStatus::Collected;</code> | Set `target` to `ParcelStatus::Collected`. |
| 272 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 273 | <code>    else if (request-&gt;type == ServiceType::CampusDelivery &#124;&#124; request-&gt;type == ServiceType::Redelivery) {</code> | Otherwise, test `request->type == ServiceType::CampusDelivery &#124;&#124; request->type == ServiceType::Redelivery`. Run the following guarded block only when true. |
| 274 | <code>        target = ParcelStatus::Delivered;</code> | Set `target` to `ParcelStatus::Delivered`. |
| 275 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 276 | <code>    // every validation and string allocation happens before changing the three records</code> | Comment explaining intent: every validation and string allocation happens before changing the three records |
| 277 | <code>    if (!resources.releaseForRequest(id)) {</code> | Test `!resources.releaseForRequest(id)`. Run the following guarded block only when true. |
| 278 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 279 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 280 | <code>    parcel-&gt;status = target;</code> | Set `parcel->status` to `target`. This is a lifecycle/availability change performed after the required guards. |
| 281 | <code>    request-&gt;status = outcome;</code> | Set `request->status` to `outcome`. This is a lifecycle/availability change performed after the required guards. |
| 282 | <code>    request-&gt;outcomeDetails.swap(savedDetails);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 283 | <code>    cout &lt;&lt; &quot;Request finished. Parcel status: &quot; &lt;&lt; toString(target) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 284 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 285 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 286 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 287 | <code>bool ServiceModule::cancelRequest(const string&amp; id, ResourceModule&amp; resources) {</code> | Define `ServiceModule::cancelRequest`. Validate active work and links, release any assignment, and end both request and parcel as Cancelled. |
| 288 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 289 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 290 | <code>        cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 291 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 292 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 293 | <code>    if (!isActive(request-&gt;status)) {</code> | Test `!isActive(request->status)`. Run the following guarded block only when true. |
| 294 | <code>        cout &lt;&lt; &quot;Only active requests can be cancelled.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 295 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 296 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 297 | <code>    if (!parcelMatches(*request)) {</code> | Test `!parcelMatches(*request)`. Run the following guarded block only when true. |
| 298 | <code>        cout &lt;&lt; &quot;Parcel details or status do not match the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 299 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 300 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 301 | <code>    if (!resources.canReleaseRequest(id)) {</code> | Test `!resources.canReleaseRequest(id)`. Run the following guarded block only when true. |
| 302 | <code>        cout &lt;&lt; &quot;Resource assignment is inconsistent.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 303 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 304 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 305 | <code>    string details = &quot;Cancelled by staff&quot;;</code> | Create local `details` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 306 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 307 | <code>    if (!resources.releaseForRequest(id)) {</code> | Test `!resources.releaseForRequest(id)`. Run the following guarded block only when true. |
| 308 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 309 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 310 | <code>    parcel-&gt;status = ParcelStatus::Cancelled;</code> | Set `parcel->status` to `ParcelStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 311 | <code>    request-&gt;status = RequestStatus::Cancelled;</code> | Set `request->status` to `RequestStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 312 | <code>    request-&gt;outcomeDetails.swap(details);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 313 | <code>    cout &lt;&lt; &quot;Request and parcel cancelled.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 314 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 315 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 316 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 317 | <code>bool ServiceModule::interruptRequest(const string&amp; id, ParcelStatus status, ResourceModule&amp; resources) {</code> | Define `ServiceModule::interruptRequest`. Stop active work for Missing/OnHold, release its resource, close the request as Cancelled and preserve the parcel recovery path. |
| 318 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 319 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 320 | <code>        cout &lt;&lt; &quot;Request not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 321 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 322 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 323 | <code>    if (!isActive(request-&gt;status)) {</code> | Test `!isActive(request->status)`. Run the following guarded block only when true. |
| 324 | <code>        cout &lt;&lt; &quot;Only active requests can be interrupted.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 325 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 326 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 327 | <code>    if (!parcelMatches(*request)) {</code> | Test `!parcelMatches(*request)`. Run the following guarded block only when true. |
| 328 | <code>        cout &lt;&lt; &quot;Parcel details or status do not match the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 329 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 330 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 331 | <code>    if (status != ParcelStatus::Missing &amp;&amp; status != ParcelStatus::OnHold) {</code> | Test `status != ParcelStatus::Missing && status != ParcelStatus::OnHold`. Run the following guarded block only when true. |
| 332 | <code>        cout &lt;&lt; &quot;An interruption must mark the parcel Missing or On hold.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 333 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 334 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 335 | <code>    if (!resources.canReleaseRequest(id)) {</code> | Test `!resources.canReleaseRequest(id)`. Run the following guarded block only when true. |
| 336 | <code>        cout &lt;&lt; &quot;Resource assignment is inconsistent.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 337 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 338 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 339 | <code>    string details;</code> | Create local `details` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 340 | <code>    if (status == ParcelStatus::Missing) {</code> | Test `status == ParcelStatus::Missing`. Run the following guarded block only when true. |
| 341 | <code>        details = &quot;Stopped: parcel missing&quot;;</code> | Set `details` to `"Stopped: parcel missing"`. |
| 342 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 343 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 344 | <code>        details = &quot;Stopped: investigation hold&quot;;</code> | Set `details` to `"Stopped: investigation hold"`. |
| 345 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 346 | <code>    Parcel* parcel = parcels.records.find(request-&gt;parcelId);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 347 | <code>    if (!resources.releaseForRequest(id)) {</code> | Test `!resources.releaseForRequest(id)`. Run the following guarded block only when true. |
| 348 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 349 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 350 | <code>    parcel-&gt;status = status;</code> | Set `parcel->status` to `status`. This is a lifecycle/availability change performed after the required guards. |
| 351 | <code>    request-&gt;status = RequestStatus::Cancelled;</code> | Set `request->status` to `RequestStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 352 | <code>    request-&gt;outcomeDetails.swap(details);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 353 | <code>    cout &lt;&lt; &quot;Request stopped. Parcel status: &quot; &lt;&lt; toString(status) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 354 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 355 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 356 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 357 | <code>bool ServiceModule::removeTerminalRequest(const string&amp; id) {</code> | Define `ServiceModule::removeTerminalRequest`. Reject active or still-assigned work; explicitly delete only a terminal retained request. |
| 358 | <code>    const ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 359 | <code>    if (request == nullptr &#124;&#124; isActive(request-&gt;status) &#124;&#124; !request-&gt;resourceId.empty()) {</code> | Test `request == nullptr &#124;&#124; isActive(request->status) &#124;&#124; !request->resourceId.empty()`. Run the following guarded block only when true. |
| 360 | <code>        cout &lt;&lt; &quot;Only terminal, unassigned requests can be removed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 361 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 362 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 363 | <code>    return requests.remove(id);</code> | Return the value of `requests.remove(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 364 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 365 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 366 | <code>bool ServiceModule::hasActiveRequestForParcel(const string&amp; id) const {</code> | Define `ServiceModule::hasActiveRequestForParcel`. Expose an active-work predicate for Task 1 deletion/edit/status guards. |
| 367 | <code>    return requests.hasActiveForParcel(id);</code> | Return the value of `requests.hasActiveForParcel(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 368 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 369 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 370 | <code>bool ServiceModule::attachResource(const string&amp; id, const string&amp; resourceId) {</code> | Define `ServiceModule::attachResource`. Private allocation hook: attach only Pending, unassigned, parcel-consistent work, then mark it Assigned. |
| 371 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 372 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 373 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 374 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 375 | <code>    if (request-&gt;status != RequestStatus::Pending) {</code> | Test `request->status != RequestStatus::Pending`. Run the following guarded block only when true. |
| 376 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 377 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 378 | <code>    if (!request-&gt;resourceId.empty() &#124;&#124; resourceId.empty()) {</code> | Test `!request->resourceId.empty() &#124;&#124; resourceId.empty()`. Run the following guarded block only when true. |
| 379 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 380 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 381 | <code>    if (!parcelMatches(*request)) {</code> | Test `!parcelMatches(*request)`. Run the following guarded block only when true. |
| 382 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 383 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 384 | <code>    request-&gt;resourceId = resourceId;</code> | Set `request->resourceId` to `resourceId`. |
| 385 | <code>    request-&gt;status = RequestStatus::Assigned;</code> | Set `request->status` to `RequestStatus::Assigned`. This is a lifecycle/availability change performed after the required guards. |
| 386 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 387 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 388 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 389 | <code>bool ServiceModule::detachResource(const string&amp; id) {</code> | Define `ServiceModule::detachResource`. Private release hook: clear the resource and return Assigned/InProgress work to Pending. Completion commits its terminal state immediately afterwards. |
| 390 | <code>    ServiceRequest* request = requests.find(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 391 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 392 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 393 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 394 | <code>    if (request-&gt;status != RequestStatus::Assigned &amp;&amp; request-&gt;status != RequestStatus::InProgress) {</code> | Test `request->status != RequestStatus::Assigned && request->status != RequestStatus::InProgress`. Run the following guarded block only when true. |
| 395 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 396 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 397 | <code>    request-&gt;resourceId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 398 | <code>    request-&gt;status = RequestStatus::Pending;</code> | Set `request->status` to `RequestStatus::Pending`. This is a lifecycle/availability change performed after the required guards. |
| 399 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 400 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 401 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 402 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
