# src/task3.cpp - every line explained

Source: [src/task3.cpp](../../src/task3.cpp)

Physical lines: 275; SHA-256 (LF text): `2b708e7c2012795795f955f83b368a3910cb292a321825a6d1268d7ed01b1560`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#include &quot;task3.hpp&quot;</code> | Include `"task3.hpp"` for Task 3 declarations. |
| 2 | <code>#include &quot;task2.hpp&quot;</code> | Include `"task2.hpp"` for Task 2 declarations. |
| 3 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 4 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 5 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 6 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 7 | <code>ResourceRing::~ResourceRing() {</code> | Define `ResourceRing::~ResourceRing`. Break the circle into a null-terminated chain, delete every node once, and clear both selection cursors. |
| 8 | <code>    if (tail != nullptr) {</code> | Test `tail != nullptr`. Run the following guarded block only when true. |
| 9 | <code>        Node* current = tail-&gt;next;</code> | Save the successor address in `current` before changing or deleting the current node. |
| 10 | <code>        tail-&gt;next = nullptr; // break the circle so the normal delete loop can finish</code> | Set `tail->next` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. Comment: break the circle so the normal delete loop can finish |
| 11 | <code>        while (current != nullptr) {</code> | Repeat while `(current != nullptr)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 12 | <code>            Node* next = current-&gt;next;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 13 | <code>            delete current;</code> | Release the node at `current`. Its successor was saved before deletion. |
| 14 | <code>            current = next;</code> | Set `current` to `next`. |
| 15 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 16 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 17 | <code>    tail = nullptr;</code> | Set `tail` to `nullptr`. This rewires a link or advances an ownership/queue boundary pointer. |
| 18 | <code>    allocationCursor[0] = nullptr;</code> | Set `allocationCursor[0]` to `nullptr`. Only this resource type's next-search position changes. |
| 19 | <code>    allocationCursor[1] = nullptr;</code> | Set `allocationCursor[1]` to `nullptr`. Only this resource type's next-search position changes. |
| 20 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 21 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 22 | <code>bool ResourceRing::insert(const Resource&amp; resource) {</code> | Define `ResourceRing::insert`. Reject duplicate IDs, self-link the first resource, otherwise append between tail and first; initialize both per-type cursors only for the empty ring. |
| 23 | <code>    if (trim(resource.id).empty() &#124;&#124; find(resource.id) != nullptr) {</code> | Test `trim(resource.id).empty() &#124;&#124; find(resource.id) != nullptr`. Run the following guarded block only when true. |
| 24 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 25 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 26 | <code>    Node* node = new Node{resource}; // next is initialized to nullptr</code> | Allocate a node on the heap and initialize its stored record/ID and successor. Link changes happen after successful allocation. Comment: next is initialized to nullptr |
| 27 | <code>    if (tail == nullptr) {</code> | Test `tail == nullptr`. Run the following guarded block only when true. |
| 28 | <code>        node-&gt;next = node;</code> | Set `node->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 29 | <code>        allocationCursor[0] = node;</code> | Set `allocationCursor[0]` to `node`. Only this resource type's next-search position changes. |
| 30 | <code>        allocationCursor[1] = node;</code> | Set `allocationCursor[1]` to `node`. Only this resource type's next-search position changes. |
| 31 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 32 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 33 | <code>        node-&gt;next = tail-&gt;next;</code> | Set `node->next` to `tail->next`. This rewires a link or advances an ownership/queue boundary pointer. |
| 34 | <code>        tail-&gt;next = node;</code> | Set `tail->next` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 35 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 36 | <code>    tail = node;</code> | Set `tail` to `node`. This rewires a link or advances an ownership/queue boundary pointer. |
| 37 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 38 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 39 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 40 | <code>Resource* ResourceRing::find(const string&amp; id) {</code> | Define `ResourceRing::find`. Search at most one complete ring cycle for an ID; support both mutable internal and const inspection access. |
| 41 | <code>    if (tail == nullptr) {</code> | Test `tail == nullptr`. Run the following guarded block only when true. |
| 42 | <code>        return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 43 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 44 | <code>    Node* current = tail-&gt;next;</code> | Save the successor address in `current` before changing or deleting the current node. |
| 45 | <code>    do {</code> | Begin a loop that visits at least one node; the trailing while stops a full circular traversal. |
| 46 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 47 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 48 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 49 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 50 | <code>    } while (current != tail-&gt;next);</code> | Continue the circular scan only until it returns to its starting node, preventing an infinite loop. |
| 51 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 52 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 53 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 54 | <code>const Resource* ResourceRing::find(const string&amp; id) const {</code> | Define `ResourceRing::find`. Search at most one complete ring cycle for an ID; support both mutable internal and const inspection access. |
| 55 | <code>    if (tail == nullptr) {</code> | Test `tail == nullptr`. Run the following guarded block only when true. |
| 56 | <code>        return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 57 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 58 | <code>    const Node* current = tail-&gt;next;</code> | Save the successor address in `current` before changing or deleting the current node. |
| 59 | <code>    do {</code> | Begin a loop that visits at least one node; the trailing while stops a full circular traversal. |
| 60 | <code>        if (current-&gt;value.id == id) {</code> | Test `current->value.id == id`. Run the following guarded block only when true. |
| 61 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 62 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 63 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 64 | <code>    } while (current != tail-&gt;next);</code> | Continue the circular scan only until it returns to its starting node, preventing an infinite loop. |
| 65 | <code>    return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 66 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 67 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 68 | <code>Resource* ResourceRing::nextAvailable(ResourceType type) {</code> | Define `ResourceRing::nextAvailable`. Scan one cycle from the selected type cursor for an Available compatible resource. Advance only that type cursor on success. |
| 69 | <code>    if (tail == nullptr) {</code> | Test `tail == nullptr`. Run the following guarded block only when true. |
| 70 | <code>        return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 71 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 72 | <code>    if (type != ResourceType::CollectionCounter &amp;&amp; type != ResourceType::DeliveryPersonnel) {</code> | Test `type != ResourceType::CollectionCounter && type != ResourceType::DeliveryPersonnel`. Run the following guarded block only when true. |
| 73 | <code>        return nullptr;</code> | Return no matching/suitable node; callers must check before dereferencing. |
| 74 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 75 | <code>    int index;</code> | Create local `index` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 76 | <code>    if (type == ResourceType::CollectionCounter) {</code> | Test `type == ResourceType::CollectionCounter`. Run the following guarded block only when true. |
| 77 | <code>        index = 0;</code> | Set `index` to `0`. |
| 78 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 79 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 80 | <code>        index = 1;</code> | Set `index` to `1`. |
| 81 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 82 | <code>    Node* start = allocationCursor[index];</code> | Create local `start` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 83 | <code>    Node* current = start;</code> | Create local `current` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 84 | <code>    do {</code> | Begin a loop that visits at least one node; the trailing while stops a full circular traversal. |
| 85 | <code>        if (current-&gt;value.type == type &amp;&amp; current-&gt;value.status == ResourceStatus::Available) {</code> | Test `current->value.type == type && current->value.status == ResourceStatus::Available`. Run the following guarded block only when true. |
| 86 | <code>            allocationCursor[index] = current-&gt;next;</code> | Set `allocationCursor[index]` to `current->next`. Only this resource type's next-search position changes. |
| 87 | <code>            return &amp;current-&gt;value;</code> | Return the address of this existing stored value; it is borrowed and must not outlive node deletion. |
| 88 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 89 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 90 | <code>    } while (current != start);</code> | Continue the circular scan only until it returns to its starting node, preventing an infinite loop. |
| 91 | <code>    return nullptr; // one full cycle checked, so do not loop forever</code> | Return no matching/suitable node; callers must check before dereferencing. Comment: one full cycle checked, so do not loop forever |
| 92 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 93 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 94 | <code>void ResourceRing::display() const {</code> | Define `ResourceRing::display`. Print each resource exactly once, including availability and assigned Request ID. |
| 95 | <code>    if (tail == nullptr) {</code> | Test `tail == nullptr`. Run the following guarded block only when true. |
| 96 | <code>        cout &lt;&lt; &quot;No resources registered.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 97 | <code>        return;</code> | Return immediately from this void function; no further statements in it execute. |
| 98 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 99 | <code>    const Node* current = tail-&gt;next;</code> | Save the successor address in `current` before changing or deleting the current node. |
| 100 | <code>    do {</code> | Begin a loop that visits at least one node; the trailing while stops a full circular traversal. |
| 101 | <code>        const Resource&amp; resource = current-&gt;value;</code> | Bind `resource` to the existing record, avoiding a copy while inspecting its fields. |
| 102 | <code>        string typeName = &quot;Delivery personnel&quot;;</code> | Create local `typeName` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 103 | <code>        if (resource.type == ResourceType::CollectionCounter) {</code> | Test `resource.type == ResourceType::CollectionCounter`. Run the following guarded block only when true. |
| 104 | <code>            typeName = &quot;Counter&quot;;</code> | Set `typeName` to `"Counter"`. |
| 105 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 106 | <code>        string requestId = &quot;-&quot;;</code> | Create local `requestId` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 107 | <code>        if (!resource.assignedRequestId.empty()) {</code> | Test `!resource.assignedRequestId.empty()`. Run the following guarded block only when true. |
| 108 | <code>            requestId = resource.assignedRequestId;</code> | Set `requestId` to `resource.assignedRequestId`. |
| 109 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 110 | <code>        cout &lt;&lt; resource.id &lt;&lt; &quot; &#124; &quot; &lt;&lt; resource.name &lt;&lt; &quot; &#124; &quot; &lt;&lt; typeName</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 111 | <code>             &lt;&lt; &quot; &#124; &quot; &lt;&lt; toString(resource.status) &lt;&lt; &quot; &#124; request &quot; &lt;&lt; requestId &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 112 | <code>        current = current-&gt;next;</code> | Set `current` to `current->next`. |
| 113 | <code>    } while (current != tail-&gt;next);</code> | Continue the circular scan only until it returns to its starting node, preventing an infinite loop. |
| 114 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 115 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 116 | <code>bool ResourceModule::registerResource(Resource resource) {</code> | Define `ResourceModule::registerResource`. Validate/trim ID and name, reject duplicates/invalid types, and insert an Available unassigned resource. |
| 117 | <code>    resource.id = trim(resource.id);</code> | Set `resource.id` to `trim(resource.id)`. |
| 118 | <code>    resource.name = trim(resource.name);</code> | Set `resource.name` to `trim(resource.name)`. |
| 119 | <code>    if (resource.id.empty() &#124;&#124; resource.name.empty()) {</code> | Test `resource.id.empty() &#124;&#124; resource.name.empty()`. Run the following guarded block only when true. |
| 120 | <code>        cout &lt;&lt; &quot;Resource ID and name are required.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 121 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 122 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 123 | <code>    if (resources.find(resource.id) != nullptr) {</code> | Test `resources.find(resource.id) != nullptr`. Run the following guarded block only when true. |
| 124 | <code>        cout &lt;&lt; &quot;Duplicate resource ID.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 125 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 126 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 127 | <code>    if (resource.type != ResourceType::CollectionCounter &amp;&amp; resource.type != ResourceType::DeliveryPersonnel) {</code> | Test `resource.type != ResourceType::CollectionCounter && resource.type != ResourceType::DeliveryPersonnel`. Run the following guarded block only when true. |
| 128 | <code>        cout &lt;&lt; &quot;Invalid resource type.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 129 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 130 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 131 | <code>    resource.status = ResourceStatus::Available;</code> | Set `resource.status` to `ResourceStatus::Available`. This is a lifecycle/availability change performed after the required guards. |
| 132 | <code>    resource.assignedRequestId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 133 | <code>    return resources.insert(resource);</code> | Return the value of `resources.insert(resource)` to the caller. This ends the function once its full return expression is evaluated. |
| 134 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 135 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 136 | <code>bool ResourceModule::updateResourceDetails(const string&amp; id, const string&amp; name) {</code> | Define `ResourceModule::updateResourceDetails`. Rename an existing resource after nonblank validation without altering identity, availability or assignment. |
| 137 | <code>    Resource* resource = resources.find(id);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 138 | <code>    string cleanName = trim(name);</code> | Create local `cleanName` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 139 | <code>    if (resource == nullptr &#124;&#124; cleanName.empty()) {</code> | Test `resource == nullptr &#124;&#124; cleanName.empty()`. Run the following guarded block only when true. |
| 140 | <code>        cout &lt;&lt; &quot;Invalid resource or name.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 141 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 142 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 143 | <code>    resource-&gt;name.swap(cleanName);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 144 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 145 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 146 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 147 | <code>void ResourceModule::displayAvailability() const {</code> | Define `ResourceModule::displayAvailability`. Delegate current allocation display to the resource ring. |
| 148 | <code>    resources.display();</code> | Call `resources.display` with the shown arguments. The call performs its named operation within ResourceModule::displayAvailability. |
| 149 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 150 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 151 | <code>const Resource* ResourceModule::findResource(const string&amp; id) const {</code> | Define `ResourceModule::findResource`. Expose read-only resource inspection and report an unknown ID. |
| 152 | <code>    const Resource* resource = resources.find(id);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 153 | <code>    if (resource == nullptr) {</code> | Test `resource == nullptr`. Run the following guarded block only when true. |
| 154 | <code>        cout &lt;&lt; &quot;Resource not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 155 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 156 | <code>    return resource;</code> | Return the value of `resource` to the caller. This ends the function once its full return expression is evaluated. |
| 157 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 158 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 159 | <code>bool ResourceModule::assignRequest(const string&amp; id, ResourceType type) {</code> | Define `ResourceModule::assignRequest`. Check Pending work, parcel consistency and resource compatibility; select by round robin, attach the request and mark the resource Occupied. |
| 160 | <code>    const ServiceRequest* request = services.findRequest(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 161 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 162 | <code>        return false; // findRequest already explains the missing ID</code> | Return failure or a false predicate without claiming success. Comment: findRequest already explains the missing ID |
| 163 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 164 | <code>    if (request-&gt;status != RequestStatus::Pending &#124;&#124; !request-&gt;resourceId.empty()) {</code> | Test `request->status != RequestStatus::Pending &#124;&#124; !request->resourceId.empty()`. Run the following guarded block only when true. |
| 165 | <code>        cout &lt;&lt; &quot;Only pending, unassigned requests can receive a resource.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 166 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 167 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 168 | <code>    if (!services.parcelMatches(*request)) {</code> | Test `!services.parcelMatches(*request)`. Run the following guarded block only when true. |
| 169 | <code>        cout &lt;&lt; &quot;Parcel details or status do not match the request.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 170 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 171 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 172 | <code>    if (type != serviceResource(request-&gt;type)) {</code> | Test `type != serviceResource(request->type)`. Run the following guarded block only when true. |
| 173 | <code>        cout &lt;&lt; &quot;Resource type does not match the requested service.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 174 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 175 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 176 | <code>    string requestId = request-&gt;id;</code> | Create local `requestId` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 177 | <code>    Resource* resource = resources.nextAvailable(type);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 178 | <code>    if (resource == nullptr) {</code> | Test `resource == nullptr`. Run the following guarded block only when true. |
| 179 | <code>        cout &lt;&lt; &quot;No suitable resource is available.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 180 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 181 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 182 | <code>    if (!services.attachResource(id, resource-&gt;id)) {</code> | Test `!services.attachResource(id, resource->id)`. Run the following guarded block only when true. |
| 183 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 184 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 185 | <code>    resource-&gt;assignedRequestId.swap(requestId);</code> | Exchange with prepared data using string swap, avoiding a fresh string allocation during the commit. |
| 186 | <code>    resource-&gt;status = ResourceStatus::Occupied;</code> | Set `resource->status` to `ResourceStatus::Occupied`. This is a lifecycle/availability change performed after the required guards. |
| 187 | <code>    cout &lt;&lt; &quot;Assigned resource &quot; &lt;&lt; resource-&gt;id &lt;&lt; &quot; to request &quot; &lt;&lt; id &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 188 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 189 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 190 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 191 | <code>bool ResourceModule::canReleaseRequest(const string&amp; id) const {</code> | Define `ResourceModule::canReleaseRequest`. Validate both assignment directions, compatible type and active state before release. Pending unassigned work needs no physical release. |
| 192 | <code>    const ServiceRequest* request = services.findRequest(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 193 | <code>    if (request == nullptr) {</code> | Test `request == nullptr`. Run the following guarded block only when true. |
| 194 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 195 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 196 | <code>    if (request-&gt;resourceId.empty()) {</code> | Test `request->resourceId.empty()`. Run the following guarded block only when true. |
| 197 | <code>        return request-&gt;status == RequestStatus::Pending;</code> | Return the value of `request->status == RequestStatus::Pending` to the caller. This ends the function once its full return expression is evaluated. |
| 198 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 199 | <code>    const Resource* resource = resources.find(request-&gt;resourceId);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 200 | <code>    if (resource == nullptr) {</code> | Test `resource == nullptr`. Run the following guarded block only when true. |
| 201 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 202 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 203 | <code>    if (resource-&gt;status != ResourceStatus::Occupied) {</code> | Test `resource->status != ResourceStatus::Occupied`. Run the following guarded block only when true. |
| 204 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 205 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 206 | <code>    if (resource-&gt;assignedRequestId != id) {</code> | Test `resource->assignedRequestId != id`. Run the following guarded block only when true. |
| 207 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 208 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 209 | <code>    if (resource-&gt;type != serviceResource(request-&gt;type)) {</code> | Test `resource->type != serviceResource(request->type)`. Run the following guarded block only when true. |
| 210 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 211 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 212 | <code>    if (request-&gt;status != RequestStatus::Assigned &amp;&amp; request-&gt;status != RequestStatus::InProgress) {</code> | Test `request->status != RequestStatus::Assigned && request->status != RequestStatus::InProgress`. Run the following guarded block only when true. |
| 213 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 214 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 215 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 216 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 217 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 218 | <code>bool ResourceModule::releaseForRequest(const string&amp; id) {</code> | Define `ResourceModule::releaseForRequest`. After link validation, detach request and clear/free resource. Pending unassigned cancellation succeeds without resource mutation. |
| 219 | <code>    if (!canReleaseRequest(id)) {</code> | Test `!canReleaseRequest(id)`. Run the following guarded block only when true. |
| 220 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 221 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 222 | <code>    const ServiceRequest* request = services.findRequest(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 223 | <code>    if (request-&gt;resourceId.empty()) {</code> | Test `request->resourceId.empty()`. Run the following guarded block only when true. |
| 224 | <code>        return true; // cancelling a pending request needs no resource</code> | Return success or a true predicate to the caller. Comment: cancelling a pending request needs no resource |
| 225 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 226 | <code>    Resource* resource = resources.find(request-&gt;resourceId);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 227 | <code>    if (!services.detachResource(id)) {</code> | Test `!services.detachResource(id)`. Run the following guarded block only when true. |
| 228 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 229 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 230 | <code>    resource-&gt;assignedRequestId.clear();</code> | Clear the indicated string, removing stale assignment/outcome metadata as specified by this operation. |
| 231 | <code>    resource-&gt;status = ResourceStatus::Available;</code> | Set `resource->status` to `ResourceStatus::Available`. This is a lifecycle/availability change performed after the required guards. |
| 232 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 233 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 234 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 235 | <code>bool ResourceModule::releaseResource(const string&amp; id) {</code> | Define `ResourceModule::releaseResource`. Reject invalid/unassigned resources; copy their Request ID before release clears the stored string. |
| 236 | <code>    Resource* resource = resources.find(id);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 237 | <code>    if (resource == nullptr) {</code> | Test `resource == nullptr`. Run the following guarded block only when true. |
| 238 | <code>        cout &lt;&lt; &quot;Resource not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 239 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 240 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 241 | <code>    if (resource-&gt;status != ResourceStatus::Occupied &#124;&#124; resource-&gt;assignedRequestId.empty()) {</code> | Test `resource->status != ResourceStatus::Occupied &#124;&#124; resource->assignedRequestId.empty()`. Run the following guarded block only when true. |
| 242 | <code>        cout &lt;&lt; &quot;Resource has no active assignment.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 243 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 244 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 245 | <code>    string requestId = resource-&gt;assignedRequestId;</code> | Create local `requestId` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 246 | <code>    return releaseForRequest(requestId);</code> | Return the value of `releaseForRequest(requestId)` to the caller. This ends the function once its full return expression is evaluated. |
| 247 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 248 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 249 | <code>bool ResourceModule::updateStatus(const string&amp; id, ResourceStatus status) {</code> | Define `ResourceModule::updateStatus`. Validate availability changes, prohibit Occupied without an assignment, and detach work safely before making occupied resources unavailable. |
| 250 | <code>    Resource* resource = resources.find(id);</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 251 | <code>    if (resource == nullptr) {</code> | Test `resource == nullptr`. Run the following guarded block only when true. |
| 252 | <code>        cout &lt;&lt; &quot;Resource not found.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 253 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 254 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 255 | <code>    bool validStatus = status == ResourceStatus::Available &#124;&#124; status == ResourceStatus::Occupied</code> | Create local `validStatus` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 256 | <code>        &#124;&#124; status == ResourceStatus::Unavailable;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 257 | <code>    if (!validStatus) {</code> | Test `!validStatus`. Run the following guarded block only when true. |
| 258 | <code>        cout &lt;&lt; &quot;Invalid resource status.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 259 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 260 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 261 | <code>    if (status == ResourceStatus::Occupied) {</code> | Test `status == ResourceStatus::Occupied`. Run the following guarded block only when true. |
| 262 | <code>        if (resource-&gt;status == ResourceStatus::Occupied &amp;&amp; canReleaseRequest(resource-&gt;assignedRequestId)) {</code> | Test `resource->status == ResourceStatus::Occupied && canReleaseRequest(resource->assignedRequestId)`. Run the following guarded block only when true. |
| 263 | <code>            return true;</code> | Return success or a true predicate to the caller. |
| 264 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 265 | <code>        cout &lt;&lt; &quot;Assign a request before marking a resource occupied.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 266 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 267 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 268 | <code>    if (resource-&gt;status == ResourceStatus::Occupied &amp;&amp; !releaseResource(id)) {</code> | Test `resource->status == ResourceStatus::Occupied && !releaseResource(id)`. Run the following guarded block only when true. |
| 269 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 270 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 271 | <code>    resource-&gt;status = status;</code> | Set `resource->status` to `status`. This is a lifecycle/availability change performed after the required guards. |
| 272 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 273 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 274 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 275 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
