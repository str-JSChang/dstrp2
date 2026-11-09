# src/task1.cpp - every line explained

Source: [src/task1.cpp](../../src/task1.cpp)

Physical lines: 273; SHA-256 (LF text): `4b481386058212899bd84df1305c4afb190821ded99eb0ede46ba3f069b2afdc`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#include &quot;task1.hpp&quot;</code> | Include `"task1.hpp"` for Task 1 declarations. |
| 2 | <code>#include &quot;task2.hpp&quot;</code> | Include `"task2.hpp"` for Task 2 declarations. |
| 3 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 4 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 5 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 6 | <code>namespace {</code> | Open an unnamed, translation-unit-local helper namespace. |
| 7 | <code>// check the same required fields for registration and editing</code> | Comment explaining intent: check the same required fields for registration and editing |
| 8 | <code>bool prepareParcel(Parcel&amp; parcel) {</code> | Define `prepareParcel`. Trim the seven descriptive parcel fields, then test that every required field remains nonblank. The argument is a local copy, so the caller is not changed. |
| 9 | <code>    parcel.recipientName = trim(parcel.recipientName);</code> | Set `parcel.recipientName` to `trim(parcel.recipientName)`. |
| 10 | <code>    parcel.recipientId = trim(parcel.recipientId);</code> | Set `parcel.recipientId` to `trim(parcel.recipientId)`. |
| 11 | <code>    parcel.recipientContact = trim(parcel.recipientContact);</code> | Set `parcel.recipientContact` to `trim(parcel.recipientContact)`. |
| 12 | <code>    parcel.deliveryCompany = trim(parcel.deliveryCompany);</code> | Set `parcel.deliveryCompany` to `trim(parcel.deliveryCompany)`. |
| 13 | <code>    parcel.trackingNumber = trim(parcel.trackingNumber);</code> | Set `parcel.trackingNumber` to `trim(parcel.trackingNumber)`. |
| 14 | <code>    parcel.destination = trim(parcel.destination);</code> | Set `parcel.destination` to `trim(parcel.destination)`. |
| 15 | <code>    parcel.parcelType = trim(parcel.parcelType);</code> | Set `parcel.parcelType` to `trim(parcel.parcelType)`. |
| 16 | <code>    return !parcel.recipientName.empty() &amp;&amp; !parcel.recipientId.empty()</code> | Return the value of `!parcel.recipientName.empty() && !parcel.recipientId.empty()` to the caller. This ends the function once its full return expression is evaluated. |
| 17 | <code>        &amp;&amp; !parcel.recipientContact.empty() &amp;&amp; !parcel.deliveryCompany.empty()</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 18 | <code>        &amp;&amp; !parcel.trackingNumber.empty() &amp;&amp; !parcel.destination.empty()</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 19 | <code>        &amp;&amp; !parcel.parcelType.empty();</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 20 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 21 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 22 | <code>ServiceType routeService(Route route) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 23 | <code>    if (route == Route::Collection) return ServiceType::Collection;</code> | Test `route == Route::Collection`. Return the value of `ServiceType::Collection` to the caller. This ends the function once its full return expression is evaluated. |
| 24 | <code>    if (route == Route::CampusDelivery) return ServiceType::CampusDelivery;</code> | Test `route == Route::CampusDelivery`. Return the value of `ServiceType::CampusDelivery` to the caller. This ends the function once its full return expression is evaluated. |
| 25 | <code>    if (route == Route::SpecialHandling) return ServiceType::SpecialHandling;</code> | Test `route == Route::SpecialHandling`. Return the value of `ServiceType::SpecialHandling` to the caller. This ends the function once its full return expression is evaluated. |
| 26 | <code>    return ServiceType::ReturnToSender;</code> | Return the value of `ServiceType::ReturnToSender` to the caller. This ends the function once its full return expression is evaluated. |
| 27 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 28 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 29 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 30 | <code>ParcelRecords::~ParcelRecords() {</code> | Define `ParcelRecords::~ParcelRecords`. Free the linear parcel chain, saving each successor before deleting its current node. |
| 31 | <code>    while (head != nullptr) {</code> | Repeat while `(head != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 32 | <code>        Node* next = head-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 33 | <code>        delete head;</code> | Release the node at `head`. Its successor was saved before deletion. |
| 34 | <code>        head = next;</code> | Set `head` to `next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 35 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 36 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 37 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 38 | <code>bool ParcelRecords::insert(const Parcel&amp; parcel) {</code> | Define `ParcelRecords::insert`. Reject blank/duplicate IDs, allocate a parcel node and link it at the head. The uniqueness traversal makes this O(P). |
| 39 | <code>    if (trim(parcel.id).empty() &#124;&#124; find(parcel.id) != nullptr) return false;</code> | Test `trim(parcel.id).empty() &#124;&#124; find(parcel.id) != nullptr`. Return failure or a false predicate without claiming success. |
| 40 | <code>    Node* node = new Node{parcel, head};</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. |
| 41 | <code>    head = node;</code> | Set `head` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 42 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 43 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 44 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 45 | <code>Parcel* ParcelRecords::find(const string&amp; id) {</code> | Define `ParcelRecords::find`. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 46 | <code>    for (Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 47 | <code>        if (current-&gt;value.id == id) return &amp;current-&gt;value;</code> | Test `current->value.id == id`. Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 48 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 49 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 50 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 51 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 52 | <code>const Parcel* ParcelRecords::find(const string&amp; id) const {</code> | Define `ParcelRecords::find`. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 53 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 54 | <code>        if (current-&gt;value.id == id) return &amp;current-&gt;value;</code> | Test `current->value.id == id`. Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 55 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 56 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 57 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 58 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 59 | <code>bool ParcelRecords::hasTrackingNumber(const string&amp; tracking, const string&amp; exceptId) const {</code> | Define `ParcelRecords::hasTrackingNumber`. Scan the parcel list once for duplicate tracking, excluding the edited record when exceptId is provided. |
| 60 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 61 | <code>        if (current-&gt;value.trackingNumber == tracking &amp;&amp; current-&gt;value.id != exceptId) return true;</code> | Test `current->value.trackingNumber == tracking && current->value.id != exceptId`. Return success or a true predicate to the caller. |
| 62 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 63 | <code>    return false;</code> | Return failure or a false predicate without claiming success. |
| 64 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 65 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 66 | <code>bool ParcelRecords::remove(const string&amp; id) {</code> | Define `ParcelRecords::remove`. Locate an ID with previous/current pointers, bypass its node and delete it. Handle head/only-node deletion separately. |
| 67 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 68 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 69 | <code>    while (current != nullptr &amp;&amp; current-&gt;value.id != id) {</code> | Repeat while `(current != nullptr && current->value.id != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 70 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 71 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 72 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 73 | <code>    if (current == nullptr) return false;</code> | Test `current == nullptr`. Return failure or a false predicate without claiming success. |
| 74 | <code>    if (previous == nullptr) head = current-&gt;next;</code> | Test `previous == nullptr`. Set `head` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 75 | <code>    else previous-&gt;next = current-&gt;next;</code> | When the preceding condition is false, Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 76 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 77 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 78 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 79 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 80 | <code>void ParcelRecords::display() const {</code> | Define `ParcelRecords::display`. Print every authoritative parcel record, or an empty-list message. |
| 81 | <code>    if (head == nullptr) cout &lt;&lt; &quot;No parcel records.\n&quot;;</code> | Test `head == nullptr`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 82 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 83 | <code>        printParcel(current-&gt;value);</code> | Call `printParcel` with the shown arguments. Print all parcel details and current status on a pipe-separated console row. |
| 84 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 85 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 87 | <code>IntakeQueue::~IntakeQueue() {</code> | Define `IntakeQueue::~IntakeQueue`. Delete every waiting-ID node and reset rear after the chain becomes empty. |
| 88 | <code>    while (front != nullptr) {</code> | Repeat while `(front != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 89 | <code>        Node* next = front-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 90 | <code>        delete front;</code> | Release the node at `front`. Its successor was saved before deletion. |
| 91 | <code>        front = next;</code> | Set `front` to `next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 92 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 93 | <code>    rear = nullptr;</code> | Set `rear` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. |
| 94 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 95 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 96 | <code>bool IntakeQueue::enqueue(const string&amp; id) {</code> | Define `IntakeQueue::enqueue`. Append a nonblank ID at rear; initialize front for an empty queue. No parcel record is copied into this queue. |
| 97 | <code>    if (trim(id).empty()) return false;</code> | Test `trim(id).empty()`. Return failure or a false predicate without claiming success. |
| 98 | <code>    Node* node = new Node{id, nullptr};</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. |
| 99 | <code>    if (rear == nullptr) front = node;</code> | Test `rear == nullptr`. Set `front` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 100 | <code>    else rear-&gt;next = node;</code> | When the preceding condition is false, Set `rear->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 101 | <code>    rear = node;</code> | Set `rear` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 102 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 103 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 104 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 105 | <code>bool IntakeQueue::dequeue(string&amp; id) {</code> | Define `IntakeQueue::dequeue`. Copy out the front ID, advance front and delete its old node. Reset rear when removing the last node. |
| 106 | <code>    if (front == nullptr) return false;</code> | Test `front == nullptr`. Return failure or a false predicate without claiming success. |
| 107 | <code>    id = front-&gt;parcelId;</code> | Set `id` to `front->parcelId`. |
| 108 | <code>    Node* old = front;</code> | Create local `old` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 109 | <code>    front = front-&gt;next;</code> | Set `front` to `front->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 110 | <code>    if (front == nullptr) rear = nullptr;</code> | Test `front == nullptr`. Set `rear` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. |
| 111 | <code>    delete old;</code> | Release the node at `old`. Its successor was saved before deletion. |
| 112 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 113 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 114 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 115 | <code>bool IntakeQueue::peek(string&amp; id) const {</code> | Define `IntakeQueue::peek`. Copy the current front ID without changing queue membership; return false for empty intake. |
| 116 | <code>    if (front == nullptr) return false;</code> | Test `front == nullptr`. Return failure or a false predicate without claiming success. |
| 117 | <code>    id = front-&gt;parcelId;</code> | Set `id` to `front->parcelId`. |
| 118 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 119 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 120 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 121 | <code>bool IntakeQueue::remove(const string&amp; id) {</code> | Define `IntakeQueue::remove`. Remove a specific waiting ID from any queue position, repairing front and rear as necessary. |
| 122 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 123 | <code>    Node* current = front;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 124 | <code>    while (current != nullptr &amp;&amp; current-&gt;parcelId != id) {</code> | Repeat while `(current != nullptr && current->parcelId != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 125 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 126 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 127 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 128 | <code>    if (current == nullptr) return false;</code> | Test `current == nullptr`. Return failure or a false predicate without claiming success. |
| 129 | <code>    if (previous == nullptr) front = current-&gt;next;</code> | Test `previous == nullptr`. Set `front` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 130 | <code>    else previous-&gt;next = current-&gt;next;</code> | When the preceding condition is false, Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 131 | <code>    if (current == rear) rear = previous;</code> | Test `current == rear`. Set `rear` to `previous`. This rewires a link or advances an ownership/queue boundary pointer. |
| 132 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 133 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 134 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 135 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 136 | <code>void IntakeQueue::display() const {</code> | Define `IntakeQueue::display`. Print waiting IDs from front to rear, which is the FIFO processing order. |
| 137 | <code>    if (front == nullptr) cout &lt;&lt; &quot;No parcels waiting.\n&quot;;</code> | Test `front == nullptr`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 138 | <code>    for (const Node* current = front; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 139 | <code>        cout &lt;&lt; current-&gt;parcelId &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 140 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 141 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 142 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 143 | <code>bool ParcelModule::registerParcel(Parcel parcel) {</code> | Define `ParcelModule::registerParcel`. Validate and normalize details, reject duplicate tracking, generate ID/time, insert a record and queue ID, then advance the counter. Roll back the record if enqueue allocation throws. |
| 144 | <code>    if (!prepareParcel(parcel)) {</code> | Test `!prepareParcel(parcel)`. Run the following guarded block only when true. |
| 145 | <code>        cout &lt;&lt; &quot;All parcel details are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 146 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 147 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 148 | <code>    if (records.hasTrackingNumber(parcel.trackingNumber)) {</code> | Test `records.hasTrackingNumber(parcel.trackingNumber)`. Run the following guarded block only when true. |
| 149 | <code>        cout &lt;&lt; &quot;Duplicate tracking number.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 150 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 151 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 152 | <code>    parcel.id = &quot;P&quot; + to_string(nextParcelNumber);</code> | Set `parcel.id` to `"P" + to_string(nextParcelNumber)`. |
| 153 | <code>    parcel.arrivalTime = currentTimestamp();</code> | Set `parcel.arrivalTime` to `currentTimestamp()`. |
| 154 | <code>    parcel.status = ParcelStatus::Received;</code> | Set `parcel.status` to `ParcelStatus::Received`. This is a lifecycle/availability change performed after the required guards. |
| 155 | <code>    if (!records.insert(parcel)) return false;</code> | Test `!records.insert(parcel)`. Return failure or a false predicate without claiming success. |
| 156 | <code>    try {</code> | Begin an exception-protected operation whose failures are handled by the following catch. |
| 157 | <code>        waiting.enqueue(parcel.id);</code> | Call `waiting.enqueue` with the shown arguments. The call performs its named operation within ParcelModule::registerParcel. |
| 158 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 159 | <code>    catch (...) {</code> | Handle the selected exception; perform rollback or restore captured output before reporting the failure. |
| 160 | <code>        records.remove(parcel.id); // undo registration if the queue could not allocate</code> | Call `records.remove` with the shown arguments. The call performs its named operation within ParcelModule::registerParcel. Comment: undo registration if the queue could not allocate |
| 161 | <code>        throw;</code> | Rethrow the original exception after rollback so the entry-point handler reports it. |
| 162 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 163 | <code>    nextParcelNumber++;</code> | Increment `nextParcelNumber` only at this point in the successful operation/test count. |
| 164 | <code>    cout &lt;&lt; &quot;Registered parcel &quot; &lt;&lt; parcel.id &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 165 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 166 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 167 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 168 | <code>void ParcelModule::displayParcels() const {</code> | Define `ParcelModule::displayParcels`. Delegate record display to the authoritative linked list. |
| 169 | <code>    records.display();</code> | Call `records.display` with the shown arguments. The call performs its named operation within ParcelModule::displayParcels. |
| 170 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 171 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 172 | <code>const Parcel* ParcelModule::findParcel(const string&amp; id) const {</code> | Define `ParcelModule::findParcel`. Look up a parcel for read-only inspection and report an unknown ID. |
| 173 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 174 | <code>    if (parcel == nullptr) cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Test `parcel == nullptr`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 175 | <code>    return parcel;</code> | Return the value of `parcel` to the caller. This ends the function once its full return expression is evaluated. |
| 176 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 177 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 178 | <code>bool ParcelModule::updateParcel(const string&amp; id, Parcel replacement, const ServiceModule&amp; services) {</code> | Define `ParcelModule::updateParcel`. Reject active/terminal edits, check replacement details, preserve saved ID/time/status and swap in the validated replacement. |
| 179 | <code>    Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 180 | <code>    if (parcel == nullptr &#124;&#124; isTerminal(parcel-&gt;status)) {</code> | Test `parcel == nullptr &#124;&#124; isTerminal(parcel->status)`. Run the following guarded block only when true. |
| 181 | <code>        cout &lt;&lt; &quot;Parcel is missing from records or already completed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 182 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 183 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 184 | <code>    if (!prepareParcel(replacement) &#124;&#124; records.hasTrackingNumber(replacement.trackingNumber, id)) {</code> | Test `!prepareParcel(replacement) &#124;&#124; records.hasTrackingNumber(replacement.trackingNumber, id)`. Run the following guarded block only when true. |
| 185 | <code>        cout &lt;&lt; &quot;Incomplete details or duplicate tracking number.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 186 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 187 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 188 | <code>    if (services.hasActiveRequestForParcel(id)) {</code> | Test `services.hasActiveRequestForParcel(id)`. Run the following guarded block only when true. |
| 189 | <code>        cout &lt;&lt; &quot;Finish or cancel the active request before editing parcel details.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 190 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 191 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 192 | <code>    replacement.id = parcel-&gt;id;</code> | Set `replacement.id` to `parcel->id`. |
| 193 | <code>    replacement.arrivalTime = parcel-&gt;arrivalTime;</code> | Set `replacement.arrivalTime` to `parcel->arrivalTime`. |
| 194 | <code>    replacement.status = parcel-&gt;status;</code> | Set `replacement.status` to `parcel->status`. This is a lifecycle/availability change performed after the required guards. |
| 195 | <code>    swap(*parcel, replacement);</code> | Call `swap` with the shown arguments. The call performs its named operation within ParcelModule::updateParcel. |
| 196 | <code>    cout &lt;&lt; &quot;Parcel details updated.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 197 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 198 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 199 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 200 | <code>bool ParcelModule::removeParcel(const string&amp; id, const ServiceModule&amp; services) {</code> | Define `ParcelModule::removeParcel`. Delete only a cancelled parcel without active requests, first clearing any remaining waiting entry. |
| 201 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 202 | <code>    if (parcel == nullptr &#124;&#124; parcel-&gt;status != ParcelStatus::Cancelled</code> | Begin a multiline guard with `parcel == nullptr &#124;&#124; parcel->status != ParcelStatus::Cancelled`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 203 | <code>        &#124;&#124; services.hasActiveRequestForParcel(id)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 204 | <code>        cout &lt;&lt; &quot;Only cancelled parcels without active requests can be removed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 205 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 206 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 207 | <code>    waiting.remove(id);</code> | Call `waiting.remove` with the shown arguments. The call performs its named operation within ParcelModule::removeParcel. |
| 208 | <code>    return records.remove(id);</code> | Return the value of `records.remove(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 209 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 210 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 211 | <code>bool ParcelModule::processNext(Route route, ServiceModule&amp; services, RequestPriority priority) {</code> | Define `ParcelModule::processNext`. Validate route/priority, skip stale queue entries and route the oldest Received parcel. Service creation owns the successful queue/status changes. |
| 212 | <code>    if (route &lt; Route::Collection &#124;&#124; route &gt; Route::InvestigationHold</code> | Begin a multiline guard with `route < Route::Collection &#124;&#124; route > Route::InvestigationHold`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 213 | <code>        &#124;&#124; (priority != RequestPriority::Urgent &amp;&amp; priority != RequestPriority::Normal)) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 214 | <code>        cout &lt;&lt; &quot;Invalid route or priority.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 215 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 216 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 217 | <code>    string id;</code> | Create local `id` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 218 | <code>    while (waiting.peek(id)) {</code> | Repeat while `(waiting.peek(id))` is true; the body advances pointers, drains nodes or repeats the menu. |
| 219 | <code>        Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 220 | <code>        if (parcel != nullptr &amp;&amp; parcel-&gt;status == ParcelStatus::Received) break;</code> | Test `parcel != nullptr && parcel->status == ParcelStatus::Received`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 221 | <code>        waiting.dequeue(id); // discard stale entries without touching parcel records</code> | Call `waiting.dequeue` with the shown arguments. The call performs its named operation within ParcelModule::processNext. Comment: discard stale entries without touching parcel records |
| 222 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 223 | <code>    if (waiting.empty()) {</code> | Test `waiting.empty()`. Run the following guarded block only when true. |
| 224 | <code>        cout &lt;&lt; &quot;Intake queue is empty.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 225 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 226 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 227 | <code>    if (route == Route::InvestigationHold) return updateStatus(id, ParcelStatus::OnHold, services);</code> | Test `route == Route::InvestigationHold`. Return the value of `updateStatus(id, ParcelStatus::OnHold, services)` to the caller. This ends the function once its full return expression is evaluated. |
| 228 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 229 | <code>    request.parcelId = id;</code> | Set `request.parcelId` to `id`. |
| 230 | <code>    request.recipientId = records.find(id)-&gt;recipientId;</code> | Set `request.recipientId` to `records.find(id)->recipientId`. |
| 231 | <code>    request.type = routeService(route);</code> | Set `request.type` to `routeService(route)`. |
| 232 | <code>    request.priority = priority;</code> | Set `request.priority` to `priority`. |
| 233 | <code>    request.serviceDetails = &quot;Routed from intake&quot;;</code> | Set `request.serviceDetails` to `"Routed from intake"`. |
| 234 | <code>    return services.createRequest(request); // also updates parcel status and removes its waiting ID</code> | Return the value of `services.createRequest(request)` to the caller. This ends the function once its full return expression is evaluated. Comment: also updates parcel status and removes its waiting ID |
| 235 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 236 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 237 | <code>bool ParcelModule::resumeParcel(const string&amp; id, Route route, ServiceModule&amp; services,</code> | Begin the multiline signature of `ParcelModule::resumeParcel`. Create a new service for a held parcel. Missing parcels need explicit recovery to OnHold first. |
| 238 | <code>                                RequestPriority priority) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 239 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 240 | <code>    if (parcel == nullptr &#124;&#124; parcel-&gt;status != ParcelStatus::OnHold</code> | Begin a multiline guard with `parcel == nullptr &#124;&#124; parcel->status != ParcelStatus::OnHold`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 241 | <code>        &#124;&#124; route &lt; Route::Collection &#124;&#124; route &gt; Route::ReturnToSender) {</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 242 | <code>        cout &lt;&lt; &quot;Resume an On hold parcel with a service route. Recover missing parcels to On hold first.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 243 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 244 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 245 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 246 | <code>    request.parcelId = id;</code> | Set `request.parcelId` to `id`. |
| 247 | <code>    request.recipientId = parcel-&gt;recipientId;</code> | Set `request.recipientId` to `parcel->recipientId`. |
| 248 | <code>    request.type = routeService(route);</code> | Set `request.type` to `routeService(route)`. |
| 249 | <code>    request.priority = priority;</code> | Set `request.priority` to `priority`. |
| 250 | <code>    request.serviceDetails = &quot;Resumed after staff review&quot;;</code> | Set `request.serviceDetails` to `"Resumed after staff review"`. |
| 251 | <code>    return services.createRequest(request);</code> | Return the value of `services.createRequest(request)` to the caller. This ends the function once its full return expression is evaluated. |
| 252 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 253 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 254 | <code>bool ParcelModule::updateStatus(const string&amp; id, ParcelStatus status, const ServiceModule&amp; services) {</code> | Define `ParcelModule::updateStatus`. Allow staff Missing/OnHold/Cancelled transitions only for nonterminal parcels without active requests, then clear waiting membership. |
| 255 | <code>    Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 256 | <code>    if (parcel == nullptr &#124;&#124; isTerminal(parcel-&gt;status)</code> | Begin a multiline guard with `parcel == nullptr &#124;&#124; isTerminal(parcel->status)`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 257 | <code>        &#124;&#124; services.hasActiveRequestForParcel(id)</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 258 | <code>        &#124;&#124; (status != ParcelStatus::Missing &amp;&amp; status != ParcelStatus::OnHold</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 259 | <code>            &amp;&amp; status != ParcelStatus::Cancelled)) {</code> | Continue the preceding short-circuit boolean expression with another required condition (AND). |
| 260 | <code>        cout &lt;&lt; &quot;Invalid status change. Active requests must be resolved first.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 261 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 262 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 263 | <code>    parcel-&gt;status = status;</code> | Set `parcel->status` to `status`. This is a lifecycle/availability change performed after the required guards. |
| 264 | <code>    waiting.remove(id);</code> | Call `waiting.remove` with the shown arguments. The call performs its named operation within ParcelModule::updateStatus. |
| 265 | <code>    cout &lt;&lt; &quot;Parcel status: &quot; &lt;&lt; toString(status) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 266 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 267 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 268 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 269 | <code>void ParcelModule::displayWaiting() const {</code> | Define `ParcelModule::displayWaiting`. Delegate display to the intake queue without changing its order. |
| 270 | <code>    waiting.display();</code> | Call `waiting.display` with the shown arguments. The call performs its named operation within ParcelModule::displayWaiting. |
| 271 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 272 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 273 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
