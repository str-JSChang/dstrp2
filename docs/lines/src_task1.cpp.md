# src/task1.cpp - every line explained

Source: [src/task1.cpp](../../src/task1.cpp)

Physical lines: 380; SHA-256 (LF text): `d1fd32d2f336085770b9110c04bf6938bddef545cc65520fb4a0c16d955dd885`.

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
| 16 | <code>    if (parcel.recipientName.empty()) {</code> | Test `parcel.recipientName.empty()`. Run the following guarded block only when true. |
| 17 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 18 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 19 | <code>    if (parcel.recipientId.empty()) {</code> | Test `parcel.recipientId.empty()`. Run the following guarded block only when true. |
| 20 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 21 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 22 | <code>    if (parcel.recipientContact.empty()) {</code> | Test `parcel.recipientContact.empty()`. Run the following guarded block only when true. |
| 23 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 24 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 25 | <code>    if (parcel.deliveryCompany.empty()) {</code> | Test `parcel.deliveryCompany.empty()`. Run the following guarded block only when true. |
| 26 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 27 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 28 | <code>    if (parcel.trackingNumber.empty()) {</code> | Test `parcel.trackingNumber.empty()`. Run the following guarded block only when true. |
| 29 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 30 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 31 | <code>    if (parcel.destination.empty()) {</code> | Test `parcel.destination.empty()`. Run the following guarded block only when true. |
| 32 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 33 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 34 | <code>    if (parcel.parcelType.empty()) {</code> | Test `parcel.parcelType.empty()`. Run the following guarded block only when true. |
| 35 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 36 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 37 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 38 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 39 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 40 | <code>ServiceType routeService(Route route) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 41 | <code>    if (route == Route::Collection) {</code> | Test `route == Route::Collection`. Run the following guarded block only when true. |
| 42 | <code>        return ServiceType::Collection;</code> | Return the value of `ServiceType::Collection` to the caller. This ends the function once its full return expression is evaluated. |
| 43 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 44 | <code>    if (route == Route::CampusDelivery) {</code> | Test `route == Route::CampusDelivery`. Run the following guarded block only when true. |
| 45 | <code>        return ServiceType::CampusDelivery;</code> | Return the value of `ServiceType::CampusDelivery` to the caller. This ends the function once its full return expression is evaluated. |
| 46 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 47 | <code>    if (route == Route::SpecialHandling) {</code> | Test `route == Route::SpecialHandling`. Run the following guarded block only when true. |
| 48 | <code>        return ServiceType::SpecialHandling;</code> | Return the value of `ServiceType::SpecialHandling` to the caller. This ends the function once its full return expression is evaluated. |
| 49 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 50 | <code>    return ServiceType::ReturnToSender;</code> | Return the value of `ServiceType::ReturnToSender` to the caller. This ends the function once its full return expression is evaluated. |
| 51 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 52 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 53 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 54 | <code>ParcelRecords::~ParcelRecords() {</code> | Define `ParcelRecords::~ParcelRecords`. Free the linear parcel chain, saving each successor before deleting its current node. |
| 55 | <code>    while (head != nullptr) {</code> | Repeat while `(head != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 56 | <code>        Node* next = head-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 57 | <code>        delete head;</code> | Release the node at `head`. Its successor was saved before deletion. |
| 58 | <code>        head = next;</code> | Set `head` to `next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 59 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 60 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 61 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 62 | <code>bool ParcelRecords::insert(const Parcel&amp; parcel) {</code> | Define `ParcelRecords::insert`. Reject blank/duplicate IDs, allocate a parcel node and link it at the head. The uniqueness traversal makes this O(P). |
| 63 | <code>    if (trim(parcel.id).empty() &#124;&#124; find(parcel.id) != nullptr) {</code> | Test `trim(parcel.id).empty() &#124;&#124; find(parcel.id) != nullptr`. Run the following guarded block only when true. |
| 64 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 65 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 66 | <code>    Node* node = new Node{parcel}; // copy data during allocation so a failed copy cannot leak a node</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. Comment: copy data during allocation so a failed copy cannot leak a node |
| 67 | <code>    node-&gt;next = head;</code> | Set `node->next` to `head`. This rewires a link or advances an ownership/queue boundary pointer. |
| 68 | <code>    head = node;</code> | Set `head` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 69 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 70 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 71 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 72 | <code>Parcel* ParcelRecords::find(const string&amp; id) {</code> | Define `ParcelRecords::find`. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 73 | <code>    for (Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 74 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 75 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 76 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 77 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 78 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 79 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 80 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 81 | <code>const Parcel* ParcelRecords::find(const string&amp; id) const {</code> | Define `ParcelRecords::find`. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 82 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 83 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 84 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 85 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 87 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 88 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 89 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 90 | <code>bool ParcelRecords::hasTrackingNumber(const string&amp; tracking, const string&amp; exceptId) const {</code> | Define `ParcelRecords::hasTrackingNumber`. Scan the parcel list once for duplicate tracking, excluding the edited record when exceptId is provided. |
| 91 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 92 | <code>        if (current-&gt;value.trackingNumber == tracking &amp;&amp; current-&gt;value.id != exceptId) {</code> | Test `current->value.trackingNumber == tracking && current->value.id != exceptId`. Run the following guarded block only when true. |
| 93 | <code>            return true;</code> | Return success or a true predicate to the caller. |
| 94 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 95 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 96 | <code>    return false;</code> | Return failure or a false predicate without claiming success. |
| 97 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 98 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 99 | <code>bool ParcelRecords::remove(const string&amp; id) {</code> | Define `ParcelRecords::remove`. Locate an ID with previous/current pointers, bypass its node and delete it. Handle head/only-node deletion separately. |
| 100 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 101 | <code>    Node* current = head;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 102 | <code>    while (current != nullptr &amp;&amp; current-&gt;value.id != id) {</code> | Repeat while `(current != nullptr && current->value.id != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 103 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 104 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 105 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 106 | <code>    if (current == nullptr) {</code> | Test `current == nullptr`. Run the following guarded block only when true. |
| 107 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 108 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 109 | <code>    if (previous == nullptr) {</code> | Test `previous == nullptr`. Run the following guarded block only when true. |
| 110 | <code>        head = current-&gt;next;</code> | Set `head` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 111 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 112 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 113 | <code>        previous-&gt;next = current-&gt;next;</code> | Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 114 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 115 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 116 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 117 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 118 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 119 | <code>void ParcelRecords::display() const {</code> | Define `ParcelRecords::display`. Print every authoritative parcel record, or an empty-list message. |
| 120 | <code>    if (head == nullptr) {</code> | Test `head == nullptr`. Run the following guarded block only when true. |
| 121 | <code>        cout &lt;&lt; &quot;No parcel records.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 122 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 123 | <code>    for (const Node* current = head; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 124 | <code>        printParcel(current-&gt;value);</code> | Call `printParcel` with the shown arguments. Print all parcel details and current status on a pipe-separated console row. |
| 125 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 126 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 127 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 128 | <code>IntakeQueue::~IntakeQueue() {</code> | Define `IntakeQueue::~IntakeQueue`. Delete every waiting-ID node and reset rear after the chain becomes empty. |
| 129 | <code>    while (front != nullptr) {</code> | Repeat while `(front != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 130 | <code>        Node* next = front-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 131 | <code>        delete front;</code> | Release the node at `front`. Its successor was saved before deletion. |
| 132 | <code>        front = next;</code> | Set `front` to `next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 133 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 134 | <code>    rear = nullptr;</code> | Set `rear` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. |
| 135 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 136 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 137 | <code>bool IntakeQueue::enqueue(const string&amp; id) {</code> | Define `IntakeQueue::enqueue`. Append a nonblank ID at rear; initialize front for an empty queue. No parcel record is copied into this queue. |
| 138 | <code>    if (trim(id).empty()) {</code> | Test `trim(id).empty()`. Run the following guarded block only when true. |
| 139 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 140 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 141 | <code>    Node* node = new Node{id}; // next starts as nullptr</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. Comment: next starts as nullptr |
| 142 | <code>    if (rear == nullptr) {</code> | Test `rear == nullptr`. Run the following guarded block only when true. |
| 143 | <code>        front = node;</code> | Set `front` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 144 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 145 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 146 | <code>        rear-&gt;next = node;</code> | Set `rear->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 147 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 148 | <code>    rear = node;</code> | Set `rear` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 149 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 150 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 151 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 152 | <code>bool IntakeQueue::dequeue(string&amp; id) {</code> | Define `IntakeQueue::dequeue`. Copy out the front ID, advance front and delete its old node. Reset rear when removing the last node. |
| 153 | <code>    if (front == nullptr) {</code> | Test `front == nullptr`. Run the following guarded block only when true. |
| 154 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 155 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 156 | <code>    id = front-&gt;parcelId;</code> | Set `id` to `front->parcelId`. |
| 157 | <code>    Node* old = front;</code> | Create local `old` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 158 | <code>    front = front-&gt;next;</code> | Set `front` to `front->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 159 | <code>    if (front == nullptr) {</code> | Test `front == nullptr`. Run the following guarded block only when true. |
| 160 | <code>        rear = nullptr;</code> | Set `rear` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. |
| 161 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 162 | <code>    delete old;</code> | Release the node at `old`. Its successor was saved before deletion. |
| 163 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 164 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 165 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 166 | <code>bool IntakeQueue::peek(string&amp; id) const {</code> | Define `IntakeQueue::peek`. Copy the current front ID without changing queue membership; return false for empty intake. |
| 167 | <code>    if (front == nullptr) {</code> | Test `front == nullptr`. Run the following guarded block only when true. |
| 168 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 169 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 170 | <code>    id = front-&gt;parcelId;</code> | Set `id` to `front->parcelId`. |
| 171 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 172 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 173 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 174 | <code>bool IntakeQueue::remove(const string&amp; id) {</code> | Define `IntakeQueue::remove`. Remove a specific waiting ID from any queue position, repairing front and rear as necessary. |
| 175 | <code>    Node* previous = nullptr;</code> | Initialize `previous` to no node/value so empty and not-yet-found cases are safe. |
| 176 | <code>    Node* current = front;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 177 | <code>    while (current != nullptr &amp;&amp; current-&gt;parcelId != id) {</code> | Repeat while `(current != nullptr && current->parcelId != id)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 178 | <code>        previous = current;</code> | Set `previous` to `current`. |
| 179 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 180 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 181 | <code>    if (current == nullptr) {</code> | Test `current == nullptr`. Run the following guarded block only when true. |
| 182 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 183 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 184 | <code>    if (previous == nullptr) {</code> | Test `previous == nullptr`. Run the following guarded block only when true. |
| 185 | <code>        front = current-&gt;next;</code> | Set `front` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 186 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 187 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 188 | <code>        previous-&gt;next = current-&gt;next;</code> | Set `previous->next` to `current->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 189 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 190 | <code>    if (current == rear) {</code> | Test `current == rear`. Run the following guarded block only when true. |
| 191 | <code>        rear = previous;</code> | Set `rear` to `previous`. This rewires a link or advances an ownership/queue boundary pointer. |
| 192 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 193 | <code>    delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 194 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 195 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 196 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 197 | <code>void IntakeQueue::display() const {</code> | Define `IntakeQueue::display`. Print waiting IDs from front to rear, which is the FIFO processing order. |
| 198 | <code>    if (front == nullptr) {</code> | Test `front == nullptr`. Run the following guarded block only when true. |
| 199 | <code>        cout &lt;&lt; &quot;No parcels waiting.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 200 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 201 | <code>    for (const Node* current = front; current != nullptr; current = current-&gt;next) {</code> | Start at the first node and follow each next pointer until nullptr; inspect each linear-list node once. |
| 202 | <code>        cout &lt;&lt; current-&gt;parcelId &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 203 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 204 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 205 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 206 | <code>bool ParcelModule::registerParcel(Parcel parcel) {</code> | Define `ParcelModule::registerParcel`. Validate and normalize details, reject duplicate tracking, generate ID/time, insert a record and queue ID, then advance the counter. Roll back the record if enqueue allocation throws. |
| 207 | <code>    if (!prepareParcel(parcel)) {</code> | Test `!prepareParcel(parcel)`. Run the following guarded block only when true. |
| 208 | <code>        cout &lt;&lt; &quot;All parcel details are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 209 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 210 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 211 | <code>    if (records.hasTrackingNumber(parcel.trackingNumber)) {</code> | Test `records.hasTrackingNumber(parcel.trackingNumber)`. Run the following guarded block only when true. |
| 212 | <code>        cout &lt;&lt; &quot;Duplicate tracking number.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 213 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 214 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 215 | <code>    parcel.id = &quot;P&quot; + to_string(nextParcelNumber);</code> | Set `parcel.id` to `"P" + to_string(nextParcelNumber)`. |
| 216 | <code>    parcel.arrivalTime = currentTimestamp();</code> | Set `parcel.arrivalTime` to `currentTimestamp()`. |
| 217 | <code>    parcel.status = ParcelStatus::Received;</code> | Set `parcel.status` to `ParcelStatus::Received`. This is a lifecycle/availability change performed after the required guards. |
| 218 | <code>    if (!records.insert(parcel)) {</code> | Test `!records.insert(parcel)`. Run the following guarded block only when true. |
| 219 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 220 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 221 | <code>    try {</code> | Begin an exception-protected operation whose failures are handled by the following catch. |
| 222 | <code>        waiting.enqueue(parcel.id);</code> | Call `waiting.enqueue` with the shown arguments. The call performs its named operation within ParcelModule::registerParcel. |
| 223 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 224 | <code>    catch (...) {</code> | Handle the selected exception; perform rollback or restore captured output before reporting the failure. |
| 225 | <code>        records.remove(parcel.id); // undo registration if the queue could not allocate</code> | Call `records.remove` with the shown arguments. The call performs its named operation within ParcelModule::registerParcel. Comment: undo registration if the queue could not allocate |
| 226 | <code>        throw;</code> | Rethrow the original exception after rollback so the entry-point handler reports it. |
| 227 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 228 | <code>    nextParcelNumber++;</code> | Increment `nextParcelNumber` only at this point in the successful operation/test count. |
| 229 | <code>    cout &lt;&lt; &quot;Registered parcel &quot; &lt;&lt; parcel.id &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 230 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 231 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 232 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 233 | <code>void ParcelModule::displayParcels() const {</code> | Define `ParcelModule::displayParcels`. Delegate record display to the authoritative linked list. |
| 234 | <code>    records.display();</code> | Call `records.display` with the shown arguments. The call performs its named operation within ParcelModule::displayParcels. |
| 235 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 236 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 237 | <code>const Parcel* ParcelModule::findParcel(const string&amp; id) const {</code> | Define `ParcelModule::findParcel`. Look up a parcel for read-only inspection and report an unknown ID. |
| 238 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 239 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 240 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 241 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 242 | <code>    return parcel;</code> | Return the value of `parcel` to the caller. This ends the function once its full return expression is evaluated. |
| 243 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 244 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 245 | <code>bool ParcelModule::updateParcel(const string&amp; id, Parcel replacement, const ServiceModule&amp; services) {</code> | Define `ParcelModule::updateParcel`. Reject active/terminal edits, check replacement details, preserve saved ID/time/status and swap in the validated replacement. |
| 246 | <code>    Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 247 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 248 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 249 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 250 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 251 | <code>    if (isTerminal(parcel-&gt;status)) {</code> | Test `isTerminal(parcel->status)`. Run the following guarded block only when true. |
| 252 | <code>        cout &lt;&lt; &quot;Completed parcel details cannot be edited.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 253 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 254 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 255 | <code>    if (!prepareParcel(replacement)) {</code> | Test `!prepareParcel(replacement)`. Run the following guarded block only when true. |
| 256 | <code>        cout &lt;&lt; &quot;All parcel details are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 257 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 258 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 259 | <code>    if (records.hasTrackingNumber(replacement.trackingNumber, id)) {</code> | Test `records.hasTrackingNumber(replacement.trackingNumber, id)`. Run the following guarded block only when true. |
| 260 | <code>        cout &lt;&lt; &quot;Duplicate tracking number.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 261 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 262 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 263 | <code>    if (services.hasActiveRequestForParcel(id)) {</code> | Test `services.hasActiveRequestForParcel(id)`. Run the following guarded block only when true. |
| 264 | <code>        cout &lt;&lt; &quot;Finish or cancel the active request before editing parcel details.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 265 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 266 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 267 | <code>    replacement.id = parcel-&gt;id;</code> | Set `replacement.id` to `parcel->id`. |
| 268 | <code>    replacement.arrivalTime = parcel-&gt;arrivalTime;</code> | Set `replacement.arrivalTime` to `parcel->arrivalTime`. |
| 269 | <code>    replacement.status = parcel-&gt;status;</code> | Set `replacement.status` to `parcel->status`. This is a lifecycle/availability change performed after the required guards. |
| 270 | <code>    swap(*parcel, replacement);</code> | Call `swap` with the shown arguments. The call performs its named operation within ParcelModule::updateParcel. |
| 271 | <code>    cout &lt;&lt; &quot;Parcel details updated.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 272 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 273 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 274 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 275 | <code>bool ParcelModule::removeParcel(const string&amp; id, const ServiceModule&amp; services) {</code> | Define `ParcelModule::removeParcel`. Delete only a cancelled parcel without active requests, first clearing any remaining waiting entry. |
| 276 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 277 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 278 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 279 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 280 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 281 | <code>    if (parcel-&gt;status != ParcelStatus::Cancelled) {</code> | Test `parcel->status != ParcelStatus::Cancelled`. Run the following guarded block only when true. |
| 282 | <code>        cout &lt;&lt; &quot;Only cancelled parcels can be removed.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 283 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 284 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 285 | <code>    if (services.hasActiveRequestForParcel(id)) {</code> | Test `services.hasActiveRequestForParcel(id)`. Run the following guarded block only when true. |
| 286 | <code>        cout &lt;&lt; &quot;Parcel still has an active request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 287 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 288 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 289 | <code>    waiting.remove(id);</code> | Call `waiting.remove` with the shown arguments. The call performs its named operation within ParcelModule::removeParcel. |
| 290 | <code>    return records.remove(id);</code> | Return the value of `records.remove(id)` to the caller. This ends the function once its full return expression is evaluated. |
| 291 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 292 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 293 | <code>bool ParcelModule::processNext(Route route, ServiceModule&amp; services, RequestPriority priority) {</code> | Define `ParcelModule::processNext`. Validate route/priority, skip stale queue entries and route the oldest Received parcel. Service creation owns the successful queue/status changes. |
| 294 | <code>    if (route &lt; Route::Collection &#124;&#124; route &gt; Route::InvestigationHold) {</code> | Test `route < Route::Collection &#124;&#124; route > Route::InvestigationHold`. Run the following guarded block only when true. |
| 295 | <code>        cout &lt;&lt; &quot;Invalid intake route.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 296 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 297 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 298 | <code>    if (priority != RequestPriority::Urgent &amp;&amp; priority != RequestPriority::Normal) {</code> | Test `priority != RequestPriority::Urgent && priority != RequestPriority::Normal`. Run the following guarded block only when true. |
| 299 | <code>        cout &lt;&lt; &quot;Invalid request priority.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 300 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 301 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 302 | <code>    string id;</code> | Create local `id` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 303 | <code>    while (waiting.peek(id)) {</code> | Repeat while `(waiting.peek(id))` is true; the body advances pointers, drains nodes or repeats the menu. |
| 304 | <code>        Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 305 | <code>        if (parcel != nullptr &amp;&amp; parcel-&gt;status == ParcelStatus::Received) {</code> | Test `parcel != nullptr && parcel->status == ParcelStatus::Received`. Run the following guarded block only when true. |
| 306 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 307 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 308 | <code>        waiting.dequeue(id); // discard stale entries without touching parcel records</code> | Call `waiting.dequeue` with the shown arguments. The call performs its named operation within ParcelModule::processNext. Comment: discard stale entries without touching parcel records |
| 309 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 310 | <code>    if (waiting.empty()) {</code> | Test `waiting.empty()`. Run the following guarded block only when true. |
| 311 | <code>        cout &lt;&lt; &quot;Intake queue is empty.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 312 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 313 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 314 | <code>    if (route == Route::InvestigationHold) {</code> | Test `route == Route::InvestigationHold`. Run the following guarded block only when true. |
| 315 | <code>        return updateStatus(id, ParcelStatus::OnHold, services);</code> | Return the value of `updateStatus(id, ParcelStatus::OnHold, services)` to the caller. This ends the function once its full return expression is evaluated. |
| 316 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 317 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 318 | <code>    request.parcelId = id;</code> | Set `request.parcelId` to `id`. |
| 319 | <code>    request.recipientId = records.find(id)-&gt;recipientId;</code> | Set `request.recipientId` to `records.find(id)->recipientId`. |
| 320 | <code>    request.type = routeService(route);</code> | Set `request.type` to `routeService(route)`. |
| 321 | <code>    request.priority = priority;</code> | Set `request.priority` to `priority`. |
| 322 | <code>    request.serviceDetails = &quot;Routed from intake&quot;;</code> | Set `request.serviceDetails` to `"Routed from intake"`. |
| 323 | <code>    return services.createRequest(request); // also updates parcel status and removes its waiting ID</code> | Return the value of `services.createRequest(request)` to the caller. This ends the function once its full return expression is evaluated. Comment: also updates parcel status and removes its waiting ID |
| 324 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 325 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 326 | <code>bool ParcelModule::resumeParcel(const string&amp; id, Route route, ServiceModule&amp; services,</code> | Begin the multiline signature of `ParcelModule::resumeParcel`. Create a new service for a held parcel. Missing parcels need explicit recovery to OnHold first. |
| 327 | <code>                                RequestPriority priority) {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 328 | <code>    const Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 329 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 330 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 331 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 332 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 333 | <code>    if (parcel-&gt;status != ParcelStatus::OnHold) {</code> | Test `parcel->status != ParcelStatus::OnHold`. Run the following guarded block only when true. |
| 334 | <code>        cout &lt;&lt; &quot;Resume only On hold parcels. Recover missing parcels to On hold first.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 335 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 336 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 337 | <code>    if (route &lt; Route::Collection &#124;&#124; route &gt; Route::ReturnToSender) {</code> | Test `route < Route::Collection &#124;&#124; route > Route::ReturnToSender`. Run the following guarded block only when true. |
| 338 | <code>        cout &lt;&lt; &quot;Choose a service route to resume the parcel.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 339 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 340 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 341 | <code>    ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 342 | <code>    request.parcelId = id;</code> | Set `request.parcelId` to `id`. |
| 343 | <code>    request.recipientId = parcel-&gt;recipientId;</code> | Set `request.recipientId` to `parcel->recipientId`. |
| 344 | <code>    request.type = routeService(route);</code> | Set `request.type` to `routeService(route)`. |
| 345 | <code>    request.priority = priority;</code> | Set `request.priority` to `priority`. |
| 346 | <code>    request.serviceDetails = &quot;Resumed after staff review&quot;;</code> | Set `request.serviceDetails` to `"Resumed after staff review"`. |
| 347 | <code>    return services.createRequest(request);</code> | Return the value of `services.createRequest(request)` to the caller. This ends the function once its full return expression is evaluated. |
| 348 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 349 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 350 | <code>bool ParcelModule::updateStatus(const string&amp; id, ParcelStatus status, const ServiceModule&amp; services) {</code> | Define `ParcelModule::updateStatus`. Allow staff Missing/OnHold/Cancelled transitions only for nonterminal parcels without active requests, then clear waiting membership. |
| 351 | <code>    Parcel* parcel = records.find(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 352 | <code>    if (parcel == nullptr) {</code> | Test `parcel == nullptr`. Run the following guarded block only when true. |
| 353 | <code>        cout &lt;&lt; &quot;Parcel not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 354 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 355 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 356 | <code>    if (isTerminal(parcel-&gt;status)) {</code> | Test `isTerminal(parcel->status)`. Run the following guarded block only when true. |
| 357 | <code>        cout &lt;&lt; &quot;Completed parcels cannot change status.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 358 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 359 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 360 | <code>    if (services.hasActiveRequestForParcel(id)) {</code> | Test `services.hasActiveRequestForParcel(id)`. Run the following guarded block only when true. |
| 361 | <code>        cout &lt;&lt; &quot;Resolve the active request before changing parcel status.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 362 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 363 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 364 | <code>    bool allowedStatus = status == ParcelStatus::Missing</code> | Create local `allowedStatus` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 365 | <code>        &#124;&#124; status == ParcelStatus::OnHold &#124;&#124; status == ParcelStatus::Cancelled;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 366 | <code>    if (!allowedStatus) {</code> | Test `!allowedStatus`. Run the following guarded block only when true. |
| 367 | <code>        cout &lt;&lt; &quot;Staff can only set Missing, On hold or Cancelled here.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 368 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 369 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 370 | <code>    parcel-&gt;status = status;</code> | Set `parcel->status` to `status`. This is a lifecycle/availability change performed after the required guards. |
| 371 | <code>    waiting.remove(id);</code> | Call `waiting.remove` with the shown arguments. The call performs its named operation within ParcelModule::updateStatus. |
| 372 | <code>    cout &lt;&lt; &quot;Parcel status: &quot; &lt;&lt; toString(status) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 373 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 374 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 375 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 376 | <code>void ParcelModule::displayWaiting() const {</code> | Define `ParcelModule::displayWaiting`. Delegate display to the intake queue without changing its order. |
| 377 | <code>    waiting.display();</code> | Call `waiting.display` with the shown arguments. The call performs its named operation within ParcelModule::displayWaiting. |
| 378 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 379 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 380 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
