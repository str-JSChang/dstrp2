# include/task3.hpp - every line explained

Source: [include/task3.hpp](../../include/task3.hpp)

Physical lines: 50; SHA-256 (LF text): `e0f5f8c9b1906bccfdcd7a384bdcf7f91ab0edc362d616e09726b1eb093b5b11`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#ifndef TASK3_HPP</code> | Begin the include guard: include this header body only if `TASK3_HPP` is not already defined. |
| 2 | <code>#define TASK3_HPP</code> | Define the header guard macro so repeated inclusion skips this body. |
| 3 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 4 | <code>#include &quot;models.hpp&quot;</code> | Include `"models.hpp"` for shared records, enums and utility helpers. |
| 5 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 6 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 7 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 8 | <code>class ServiceModule;</code> | Forward-declare the named class so references/friend declarations can use it without a circular header include. |
| 9 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 10 | <code>// Task 3 - repeat allocation from the node after the last selection</code> | Comment explaining intent: Task 3 - repeat allocation from the node after the last selection |
| 11 | <code>class ResourceRing {</code> | Begin the class `ResourceRing` definition, grouping its fields and operations. |
| 12 | <code>public:</code> | The following class members form its publicly callable interface. |
| 13 | <code>    ResourceRing() = default;</code> | Use the compiler-generated constructor; in-class pointer initializers establish an empty structure. |
| 14 | <code>    ~ResourceRing();</code> | Declare this operation for callers. Break the circle into a null-terminated chain, delete every node once, and clear both selection cursors. |
| 15 | <code>    ResourceRing(const ResourceRing&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 16 | <code>    ResourceRing&amp; operator=(const ResourceRing&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 17 | <code>    bool insert(const Resource&amp; resource);</code> | Declare this operation for callers. Reject duplicate IDs, self-link the first resource, otherwise append between tail and first; initialize both per-type cursors only for the empty ring. |
| 18 | <code>    Resource* find(const string&amp; id);</code> | Declare this operation for callers. Search at most one complete ring cycle for an ID; support both mutable internal and const inspection access. |
| 19 | <code>    const Resource* find(const string&amp; id) const;</code> | Declare this operation for callers. Search at most one complete ring cycle for an ID; support both mutable internal and const inspection access. |
| 20 | <code>    Resource* nextAvailable(ResourceType type);</code> | Declare this operation for callers. Scan one cycle from the selected type cursor for an Available compatible resource. Advance only that type cursor on success. |
| 21 | <code>    void display() const;</code> | Declare this operation for callers. Print each resource exactly once, including availability and assigned Request ID. |
| 22 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 23 | <code>    struct Node {</code> | Begin the struct `Node` definition, grouping its fields and operations. |
| 24 | <code>        Resource value;</code> | Declare member `value` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 25 | <code>        Node* next = nullptr;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 26 | <code>    };</code> | End the current type definition; the semicolon completes its declaration. |
| 27 | <code>    Node* tail = nullptr;</code> | Declare/initialize `tail`: last ring node; tail->next is first. The initializer on this line supplies its safe starting value where present. |
| 28 | <code>    Node* allocationCursor[2] = {nullptr, nullptr};</code> | Declare/initialize `allocationCursor`: two next-search pointers, one for counters and one for delivery personnel. The initializer on this line supplies its safe starting value where present. |
| 29 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 30 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 31 | <code>class ResourceModule {</code> | Begin the class `ResourceModule` definition, grouping its fields and operations. |
| 32 | <code>public:</code> | The following class members form its publicly callable interface. |
| 33 | <code>    explicit ResourceModule(ServiceModule&amp; services) : services(services) {}</code> | Construct the module with a reference to the existing collaborator; explicit prevents implicit conversion into a module. |
| 34 | <code>    bool registerResource(Resource resource);</code> | Declare this operation for callers. Validate/trim ID and name, reject duplicates/invalid types, and insert an Available unassigned resource. |
| 35 | <code>    bool updateResourceDetails(const string&amp; id, const string&amp; name);</code> | Declare this operation for callers. Rename an existing resource after nonblank validation without altering identity, availability or assignment. |
| 36 | <code>    void displayAvailability() const;</code> | Declare this operation for callers. Delegate current allocation display to the resource ring. |
| 37 | <code>    const Resource* findResource(const string&amp; id) const;</code> | Declare this operation for callers. Expose read-only resource inspection and report an unknown ID. |
| 38 | <code>    bool assignRequest(const string&amp; id, ResourceType type);</code> | Declare this operation for callers. Check Pending work, parcel consistency and resource compatibility; select by round robin, attach the request and mark the resource Occupied. |
| 39 | <code>    bool releaseResource(const string&amp; id);</code> | Declare this operation for callers. Reject invalid/unassigned resources; copy their Request ID before release clears the stored string. |
| 40 | <code>    bool updateStatus(const string&amp; id, ResourceStatus status);</code> | Declare this operation for callers. Validate availability changes, prohibit Occupied without an assignment, and detach work safely before making occupied resources unavailable. |
| 41 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 42 | <code>    friend class ServiceModule;</code> | Grant the named collaborating class access for coordinated lifecycle operations; it does not duplicate storage. |
| 43 | <code>    bool canReleaseRequest(const string&amp; id) const;</code> | Declare this operation for callers. Validate both assignment directions, compatible type and active state before release. Pending unassigned work needs no physical release. |
| 44 | <code>    bool releaseForRequest(const string&amp; id);</code> | Declare this operation for callers. After link validation, detach request and clear/free resource. Pending unassigned cancellation succeeds without resource mutation. |
| 45 | <code>    ServiceModule&amp; services;</code> | Declare member `services` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 46 | <code>    ResourceRing resources;</code> | Declare member `resources` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 47 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 48 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 49 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 50 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
