# include/task2.hpp - every line explained

Source: [include/task2.hpp](../../include/task2.hpp)

Physical lines: 59; SHA-256 (LF text): `d71628bd3d28cdb3785e9146e1d077f4c4e5735089a73fcf75c3bf2f0716bd24`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#ifndef TASK2_HPP</code> | Begin the include guard: include this header body only if `TASK2_HPP` is not already defined. |
| 2 | <code>#define TASK2_HPP</code> | Define the header guard macro so repeated inclusion skips this body. |
| 3 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 4 | <code>#include &quot;models.hpp&quot;</code> | Include `"models.hpp"` for shared records, enums and utility helpers. |
| 5 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 6 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 7 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 8 | <code>class ParcelModule;</code> | Forward-declare the named class so references/friend declarations can use it without a circular header include. |
| 9 | <code>class ResourceModule;</code> | Forward-declare the named class so references/friend declarations can use it without a circular header include. |
| 10 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 11 | <code>// Task 2 - urgent first, then arrival sequence within the same priority</code> | Comment explaining intent: Task 2 - urgent first, then arrival sequence within the same priority |
| 12 | <code>class RequestQueue {</code> | Begin the class `RequestQueue` definition, grouping its fields and operations. |
| 13 | <code>public:</code> | The following class members form its publicly callable interface. |
| 14 | <code>    RequestQueue() = default;</code> | Use the compiler-generated constructor; in-class pointer initializers establish an empty structure. |
| 15 | <code>    ~RequestQueue();</code> | Declare this operation for callers. Delete all retained request nodes, including active and terminal records. |
| 16 | <code>    RequestQueue(const RequestQueue&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 17 | <code>    RequestQueue&amp; operator=(const RequestQueue&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 18 | <code>    bool insert(const ServiceRequest&amp; request);</code> | Declare this operation for callers. Reject duplicate IDs and insert by priority then sequence. Earlier/equal sequences remain ahead, preserving stable FIFO ties. |
| 19 | <code>    ServiceRequest* find(const string&amp; id);</code> | Declare this operation for callers. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 20 | <code>    const ServiceRequest* find(const string&amp; id) const;</code> | Declare this operation for callers. Linearly search retained requests by ID; return a borrowed pointer or nullptr. |
| 21 | <code>    const ServiceRequest* nextPending() const;</code> | Declare this operation for callers. Find the first Pending node in priority order, skipping assigned, in-progress and terminal records. |
| 22 | <code>    bool remove(const string&amp; id);</code> | Declare this operation for callers. Bypass and delete a specified request node, with a separate head case. |
| 23 | <code>    bool hasActiveForParcel(const string&amp; id) const;</code> | Declare this operation for callers. Detect whether a parcel already has Pending, Assigned or InProgress work. |
| 24 | <code>    void displayActive() const;</code> | Declare this operation for callers. Print only active requests while tracking whether an empty-result message is needed. |
| 25 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 26 | <code>    struct Node {</code> | Begin the struct `Node` definition, grouping its fields and operations. |
| 27 | <code>        ServiceRequest value;</code> | Declare member `value` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 28 | <code>        Node* next = nullptr;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 29 | <code>    };</code> | End the current type definition; the semicolon completes its declaration. |
| 30 | <code>    Node* head = nullptr;</code> | Declare/initialize `head`: first node of this owned linear list. The initializer on this line supplies its safe starting value where present. |
| 31 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 32 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 33 | <code>class ServiceModule {</code> | Begin the class `ServiceModule` definition, grouping its fields and operations. |
| 34 | <code>public:</code> | The following class members form its publicly callable interface. |
| 35 | <code>    explicit ServiceModule(ParcelModule&amp; parcels) : parcels(parcels) {}</code> | Construct the module with a reference to the existing collaborator; explicit prevents implicit conversion into a module. |
| 36 | <code>    bool createRequest(ServiceRequest request);</code> | Declare this operation for callers. Validate recipient/service/priority/parcel eligibility, insert a generated request, then synchronize parcel status and remove intake membership. Terminal and missing parcels are ineligible. |
| 37 | <code>    void displayActiveRequests() const;</code> | Declare this operation for callers. Delegate active-request display to the sorted list. |
| 38 | <code>    const ServiceRequest* findRequest(const string&amp; id) const;</code> | Declare this operation for callers. Find retained work for read-only inspection and report an unknown ID. |
| 39 | <code>    const ServiceRequest* nextRequest() const;</code> | Declare this operation for callers. Expose the first Pending recommendation, or explain that none exists. Staff may explicitly select another ID. |
| 40 | <code>    bool processRequest(const string&amp; id);</code> | Declare this operation for callers. Move only an assigned request with matching parcel/resource metadata to InProgress. |
| 41 | <code>    bool completeRequest(const string&amp; id, RequestStatus outcome, const string&amp; details,</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 42 | <code>                         const string&amp; recipientId, ResourceModule&amp; resources);</code> | Call `the indicated helper` with the shown arguments. The call performs its named operation within ServiceModule::completeRequest. |
| 43 | <code>    bool cancelRequest(const string&amp; id, ResourceModule&amp; resources);</code> | Declare this operation for callers. Validate active work and links, release any assignment, and end both request and parcel as Cancelled. |
| 44 | <code>    bool interruptRequest(const string&amp; id, ParcelStatus status, ResourceModule&amp; resources);</code> | Declare this operation for callers. Stop active work for Missing/OnHold, release its resource, close the request as Cancelled and preserve the parcel recovery path. |
| 45 | <code>    bool removeTerminalRequest(const string&amp; id);</code> | Declare this operation for callers. Reject active or still-assigned work; explicitly delete only a terminal retained request. |
| 46 | <code>    bool hasActiveRequestForParcel(const string&amp; id) const;</code> | Declare this operation for callers. Expose an active-work predicate for Task 1 deletion/edit/status guards. |
| 47 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 48 | <code>    friend class ResourceModule; // only resource allocation can attach a resource</code> | Grant the named collaborating class access for coordinated lifecycle operations; it does not duplicate storage. Comment: only resource allocation can attach a resource |
| 49 | <code>    bool attachResource(const string&amp; id, const string&amp; resourceId);</code> | Declare this operation for callers. Private allocation hook: attach only Pending, unassigned, parcel-consistent work, then mark it Assigned. |
| 50 | <code>    bool detachResource(const string&amp; id);</code> | Declare this operation for callers. Private release hook: clear the resource and return Assigned/InProgress work to Pending. Completion commits its terminal state immediately afterwards. |
| 51 | <code>    bool parcelMatches(const ServiceRequest&amp; request) const;</code> | Declare this operation for callers. Check the core active-request invariant: its parcel exists, service is valid, recipient matches and parcel status fits the service. |
| 52 | <code>    ParcelModule&amp; parcels;</code> | Declare member `parcels` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 53 | <code>    RequestQueue requests;</code> | Declare member `requests` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 54 | <code>    unsigned long long nextRequestNumber = 1;</code> | Declare/initialize `nextRequestNumber`: next generated request-number suffix. The initializer on this line supplies its safe starting value where present. |
| 55 | <code>    unsigned long long nextSequence = 1;</code> | Declare/initialize `nextSequence`: next successful request creation sequence. The initializer on this line supplies its safe starting value where present. |
| 56 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 57 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 58 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 59 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
