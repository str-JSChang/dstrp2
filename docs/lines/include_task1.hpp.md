# include/task1.hpp - every line explained

Source: [include/task1.hpp](../../include/task1.hpp)

Physical lines: 76; SHA-256 (LF text): `200290f8ac7d31480f1fe5375e7c6f47a9e881ebf5df670e12178f9cfeabd3f8`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#ifndef TASK1_HPP</code> | Begin the include guard: include this header body only if `TASK1_HPP` is not already defined. |
| 2 | <code>#define TASK1_HPP</code> | Define the header guard macro so repeated inclusion skips this body. |
| 3 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 4 | <code>#include &quot;models.hpp&quot;</code> | Include `"models.hpp"` for shared records, enums and utility helpers. |
| 5 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 6 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 7 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 8 | <code>class ServiceModule;</code> | Forward-declare the named class so references/friend declarations can use it without a circular header include. |
| 9 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 10 | <code>// Task 1 - keep every parcel record, even after it leaves intake</code> | Comment explaining intent: Task 1 - keep every parcel record, even after it leaves intake |
| 11 | <code>class ParcelRecords {</code> | Begin the class `ParcelRecords` definition, grouping its fields and operations. |
| 12 | <code>public:</code> | The following class members form its publicly callable interface. |
| 13 | <code>    ParcelRecords() = default;</code> | Use the compiler-generated constructor; in-class pointer initializers establish an empty structure. |
| 14 | <code>    ~ParcelRecords();</code> | Declare this operation for callers. Free the linear parcel chain, saving each successor before deleting its current node. |
| 15 | <code>    ParcelRecords(const ParcelRecords&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 16 | <code>    ParcelRecords&amp; operator=(const ParcelRecords&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 17 | <code>    bool insert(const Parcel&amp; parcel);</code> | Declare this operation for callers. Reject blank/duplicate IDs, allocate a parcel node and link it at the head. The uniqueness traversal makes this O(P). |
| 18 | <code>    Parcel* find(const string&amp; id);</code> | Declare this operation for callers. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 19 | <code>    const Parcel* find(const string&amp; id) const;</code> | Declare this operation for callers. Traverse parcel nodes by ID. Return a borrowed pointer on a match, or nullptr at the end; the const overload prevents caller mutation. |
| 20 | <code>    bool hasTrackingNumber(const string&amp; tracking, const string&amp; exceptId = &quot;&quot;) const;</code> | Declare this operation for callers. Scan the parcel list once for duplicate tracking, excluding the edited record when exceptId is provided. |
| 21 | <code>    bool remove(const string&amp; id);</code> | Declare this operation for callers. Locate an ID with previous/current pointers, bypass its node and delete it. Handle head/only-node deletion separately. |
| 22 | <code>    void display() const;</code> | Declare this operation for callers. Print every authoritative parcel record, or an empty-list message. |
| 23 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 24 | <code>    struct Node {</code> | Begin the struct `Node` definition, grouping its fields and operations. |
| 25 | <code>        Parcel value;</code> | Declare member `value` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 26 | <code>        Node* next = nullptr;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 27 | <code>    };</code> | End the current type definition; the semicolon completes its declaration. |
| 28 | <code>    Node* head = nullptr;</code> | Declare/initialize `head`: first node of this owned linear list. The initializer on this line supplies its safe starting value where present. |
| 29 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 30 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 31 | <code>// only parcel IDs are needed in the waiting queue</code> | Comment explaining intent: only parcel IDs are needed in the waiting queue |
| 32 | <code>class IntakeQueue {</code> | Begin the class `IntakeQueue` definition, grouping its fields and operations. |
| 33 | <code>public:</code> | The following class members form its publicly callable interface. |
| 34 | <code>    IntakeQueue() = default;</code> | Use the compiler-generated constructor; in-class pointer initializers establish an empty structure. |
| 35 | <code>    ~IntakeQueue();</code> | Declare this operation for callers. Delete every waiting-ID node and reset rear after the chain becomes empty. |
| 36 | <code>    IntakeQueue(const IntakeQueue&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 37 | <code>    IntakeQueue&amp; operator=(const IntakeQueue&amp;) = delete;</code> | Disable this copying operation to prevent two owners from sharing/deleting the same node chain. |
| 38 | <code>    bool enqueue(const string&amp; id);</code> | Declare this operation for callers. Append a nonblank ID at rear; initialize front for an empty queue. No parcel record is copied into this queue. |
| 39 | <code>    bool dequeue(string&amp; id);</code> | Declare this operation for callers. Copy out the front ID, advance front and delete its old node. Reset rear when removing the last node. |
| 40 | <code>    bool peek(string&amp; id) const;</code> | Declare this operation for callers. Copy the current front ID without changing queue membership; return false for empty intake. |
| 41 | <code>    bool remove(const string&amp; id);</code> | Declare this operation for callers. Remove a specific waiting ID from any queue position, repairing front and rear as necessary. |
| 42 | <code>    bool empty() const {</code> | Return whether front is nullptr without traversing the queue; the const method does not change membership. |
| 43 | <code>        return front == nullptr;</code> | Return the value of `front == nullptr` to the caller. This ends the function once its full return expression is evaluated. |
| 44 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 45 | <code>    void display() const;</code> | Declare this operation for callers. Print waiting IDs from front to rear, which is the FIFO processing order. |
| 46 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 47 | <code>    struct Node {</code> | Begin the struct `Node` definition, grouping its fields and operations. |
| 48 | <code>        string parcelId;</code> | Declare/initialize `parcelId`: ID of the authoritative parcel, avoiding duplicated parcel storage. The initializer on this line supplies its safe starting value where present. |
| 49 | <code>        Node* next = nullptr;</code> | Declare/initialize `next`: successor pointer; nullptr ends linear chains while ring successors wrap. The initializer on this line supplies its safe starting value where present. |
| 50 | <code>    };</code> | End the current type definition; the semicolon completes its declaration. |
| 51 | <code>    Node* front = nullptr;</code> | Declare/initialize `front`: first waiting-ID node. The initializer on this line supplies its safe starting value where present. |
| 52 | <code>    Node* rear = nullptr;</code> | Declare/initialize `rear`: last waiting-ID node, permitting O(1) append. The initializer on this line supplies its safe starting value where present. |
| 53 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 54 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 55 | <code>class ParcelModule {</code> | Begin the class `ParcelModule` definition, grouping its fields and operations. |
| 56 | <code>public:</code> | The following class members form its publicly callable interface. |
| 57 | <code>    bool registerParcel(Parcel parcel);</code> | Declare this operation for callers. Validate and normalize details, reject duplicate tracking, generate ID/time, insert a record and queue ID, then advance the counter. Roll back the record if enqueue allocation throws. |
| 58 | <code>    void displayParcels() const;</code> | Declare this operation for callers. Delegate record display to the authoritative linked list. |
| 59 | <code>    const Parcel* findParcel(const string&amp; id) const;</code> | Declare this operation for callers. Look up a parcel for read-only inspection and report an unknown ID. |
| 60 | <code>    bool updateParcel(const string&amp; id, Parcel replacement, const ServiceModule&amp; services);</code> | Declare this operation for callers. Reject active/terminal edits, check replacement details, preserve saved ID/time/status and swap in the validated replacement. |
| 61 | <code>    bool removeParcel(const string&amp; id, const ServiceModule&amp; services);</code> | Declare this operation for callers. Delete only a cancelled parcel without active requests, first clearing any remaining waiting entry. |
| 62 | <code>    bool processNext(Route route, ServiceModule&amp; services,</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 63 | <code>                     RequestPriority priority = RequestPriority::Normal);</code> | Declare/initialize `priority`: Urgent/Normal processing rank. The initializer on this line supplies its safe starting value where present. |
| 64 | <code>    bool resumeParcel(const string&amp; id, Route route, ServiceModule&amp; services,</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 65 | <code>                      RequestPriority priority = RequestPriority::Normal);</code> | Declare/initialize `priority`: Urgent/Normal processing rank. The initializer on this line supplies its safe starting value where present. |
| 66 | <code>    bool updateStatus(const string&amp; id, ParcelStatus status, const ServiceModule&amp; services);</code> | Declare this operation for callers. Allow staff Missing/OnHold/Cancelled transitions only for nonterminal parcels without active requests, then clear waiting membership. |
| 67 | <code>    void displayWaiting() const;</code> | Declare this operation for callers. Delegate display to the intake queue without changing its order. |
| 68 | <code>private:</code> | The following storage/helpers are private; external menu code cannot access them directly. |
| 69 | <code>    friend class ServiceModule; // service lifecycle changes are coordinated here</code> | Grant the named collaborating class access for coordinated lifecycle operations; it does not duplicate storage. Comment: service lifecycle changes are coordinated here |
| 70 | <code>    ParcelRecords records;</code> | Declare member `records` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 71 | <code>    IntakeQueue waiting;</code> | Declare member `waiting` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 72 | <code>    unsigned long long nextParcelNumber = 1;</code> | Declare/initialize `nextParcelNumber`: next generated parcel-number suffix. The initializer on this line supplies its safe starting value where present. |
| 73 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 74 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 75 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 76 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
