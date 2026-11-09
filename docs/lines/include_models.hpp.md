# include/models.hpp - every line explained

Source: [include/models.hpp](../../include/models.hpp)

Physical lines: 180; SHA-256 (LF text): `14ddba7cf8f34eca6ed65a9d6e74145208d904bb86ad2eb135856540190ded8d`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#ifndef MODELS_HPP</code> | Begin the include guard: include this header body only if `MODELS_HPP` is not already defined. |
| 2 | <code>#define MODELS_HPP</code> | Define the header guard macro so repeated inclusion skips this body. |
| 3 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 4 | <code>#include &lt;string&gt;</code> | Include `<string>` for string storage and operations. |
| 5 | <code>#include &lt;utility&gt;</code> | Include `<utility>` for swap and move utilities. |
| 6 | <code>#include &lt;iostream&gt;</code> | Include `<iostream>` for console streams. |
| 7 | <code>#include &lt;chrono&gt;</code> | Include `<chrono>` for system clock access. |
| 8 | <code>#include &lt;ctime&gt;</code> | Include `<ctime>` for local calendar time conversion. |
| 9 | <code>#include &lt;iomanip&gt;</code> | Include `<iomanip>` for timestamp formatting. |
| 10 | <code>#include &lt;sstream&gt;</code> | Include `<sstream>` for string-backed input/output streams. |
| 11 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 12 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 13 | <code>namespace campus {</code> | Open the campus namespace for project types and functions. |
| 14 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 15 | <code>enum class ParcelStatus {</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 16 | <code>    Received, AwaitingCollection, AwaitingDelivery, SpecialHandling,</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 17 | <code>    ReturnPending, OnHold, Missing, Collected, Delivered, Returned, Cancelled</code> | Continue the named enum values used for parcel lifecycle states. |
| 18 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 19 | <code>enum class Route { Collection, CampusDelivery, SpecialHandling, ReturnToSender, InvestigationHold };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 20 | <code>enum class ServiceType { Collection, CampusDelivery, SpecialHandling, Redelivery, ReturnToSender };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 21 | <code>enum class RequestPriority { Urgent, Normal };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 22 | <code>enum class RequestStatus { Pending, Assigned, InProgress, Completed, Cancelled, Returned };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 23 | <code>enum class ResourceType { CollectionCounter, DeliveryPersonnel };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 24 | <code>enum class ResourceStatus { Available, Occupied, Unavailable };</code> | Define a scoped enum of permitted states/types. Enum ordering is also used for priority/range checks where documented. |
| 25 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 26 | <code>struct Parcel {</code> | Begin the struct `Parcel` definition, grouping its fields and operations. |
| 27 | <code>    string id;</code> | Declare/initialize `id`: unique identity of this record. The initializer on this line supplies its safe starting value where present. |
| 28 | <code>    string recipientName;</code> | Declare/initialize `recipientName`: recipient display name. The initializer on this line supplies its safe starting value where present. |
| 29 | <code>    string recipientId;</code> | Declare/initialize `recipientId`: student/staff identifier used for matching and completion checks. The initializer on this line supplies its safe starting value where present. |
| 30 | <code>    string recipientContact;</code> | Declare/initialize `recipientContact`: recipient contact text. The initializer on this line supplies its safe starting value where present. |
| 31 | <code>    string deliveryCompany;</code> | Declare/initialize `deliveryCompany`: carrier name. The initializer on this line supplies its safe starting value where present. |
| 32 | <code>    string trackingNumber;</code> | Declare/initialize `trackingNumber`: carrier tracking value, unique among stored parcels. The initializer on this line supplies its safe starting value where present. |
| 33 | <code>    string destination;</code> | Declare/initialize `destination`: campus collection/delivery location. The initializer on this line supplies its safe starting value where present. |
| 34 | <code>    string parcelType;</code> | Declare/initialize `parcelType`: descriptive handling/type information. The initializer on this line supplies its safe starting value where present. |
| 35 | <code>    string arrivalTime;</code> | Declare/initialize `arrivalTime`: generated local parcel arrival timestamp. The initializer on this line supplies its safe starting value where present. |
| 36 | <code>    ParcelStatus status = ParcelStatus::Received;</code> | Declare/initialize `status`: current lifecycle or availability state. The initializer on this line supplies its safe starting value where present. |
| 37 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 38 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 39 | <code>struct ServiceRequest {</code> | Begin the struct `ServiceRequest` definition, grouping its fields and operations. |
| 40 | <code>    string id;</code> | Declare/initialize `id`: unique identity of this record. The initializer on this line supplies its safe starting value where present. |
| 41 | <code>    string parcelId;</code> | Declare/initialize `parcelId`: ID of the authoritative parcel, avoiding duplicated parcel storage. The initializer on this line supplies its safe starting value where present. |
| 42 | <code>    ServiceType type = ServiceType::Collection;</code> | Declare member `type` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 43 | <code>    RequestPriority priority = RequestPriority::Normal;</code> | Declare/initialize `priority`: Urgent/Normal processing rank. The initializer on this line supplies its safe starting value where present. |
| 44 | <code>    RequestStatus status = RequestStatus::Pending;</code> | Declare/initialize `status`: current lifecycle or availability state. The initializer on this line supplies its safe starting value where present. |
| 45 | <code>    string recipientId;</code> | Declare/initialize `recipientId`: student/staff identifier used for matching and completion checks. The initializer on this line supplies its safe starting value where present. |
| 46 | <code>    string serviceDetails;</code> | Declare/initialize `serviceDetails`: staff service instructions. The initializer on this line supplies its safe starting value where present. |
| 47 | <code>    string createdAt;</code> | Declare/initialize `createdAt`: generated request creation timestamp. The initializer on this line supplies its safe starting value where present. |
| 48 | <code>    unsigned long long sequence = 0;</code> | Declare/initialize `sequence`: monotonic FIFO tie-break value. The initializer on this line supplies its safe starting value where present. |
| 49 | <code>    string resourceId;</code> | Declare/initialize `resourceId`: assigned resource ID, empty when unassigned. The initializer on this line supplies its safe starting value where present. |
| 50 | <code>    string outcomeDetails;</code> | Declare/initialize `outcomeDetails`: completion/cancellation/interruption explanation. The initializer on this line supplies its safe starting value where present. |
| 51 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 52 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 53 | <code>struct Resource {</code> | Begin the struct `Resource` definition, grouping its fields and operations. |
| 54 | <code>    string id;</code> | Declare/initialize `id`: unique identity of this record. The initializer on this line supplies its safe starting value where present. |
| 55 | <code>    string name;</code> | Declare/initialize `name`: resource display name. The initializer on this line supplies its safe starting value where present. |
| 56 | <code>    ResourceType type = ResourceType::CollectionCounter;</code> | Declare member `type` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 57 | <code>    ResourceStatus status = ResourceStatus::Available;</code> | Declare/initialize `status`: current lifecycle or availability state. The initializer on this line supplies its safe starting value where present. |
| 58 | <code>    string assignedRequestId;</code> | Declare/initialize `assignedRequestId`: reverse link to active work, empty when free. The initializer on this line supplies its safe starting value where present. |
| 59 | <code>};</code> | End the current type definition; the semicolon completes its declaration. |
| 60 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 61 | <code>// remove outside whitespace, while leaving spaces inside names alone</code> | Comment explaining intent: remove outside whitespace, while leaving spaces inside names alone |
| 62 | <code>inline string trim(const string&amp; text) {</code> | Define `trim`. Return the non-whitespace interior of a string, or an empty string if it contains only outside whitespace. |
| 63 | <code>    size_t first = text.find_first_not_of(&quot; \t\r\n&quot;);</code> | Declare member `first` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 64 | <code>    if (first == string::npos) return &quot;&quot;;</code> | Test `first == string::npos`. Return the value of `""` to the caller. This ends the function once its full return expression is evaluated. |
| 65 | <code>    size_t last = text.find_last_not_of(&quot; \t\r\n&quot;);</code> | Declare member `last` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 66 | <code>    return text.substr(first, last - first + 1);</code> | Return the value of `text.substr(first, last - first + 1)` to the caller. This ends the function once its full return expression is evaluated. |
| 67 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 68 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 69 | <code>inline string currentTimestamp() {</code> | Define `currentTimestamp`. Produce the local YYYY-MM-DD HH:MM:SS arrival/request timestamp using the correct Windows/POSIX localtime function. |
| 70 | <code>    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());</code> | Declare member `now` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 71 | <code>    tm local = {};</code> | Declare member `local` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 72 | <code>#ifdef _WIN32</code> | Select Windows-specific local-time conversion when compiled for Windows. |
| 73 | <code>    localtime_s(&amp;local, &amp;now);</code> | Call `localtime_s` with the shown arguments. The call performs its named operation within currentTimestamp. |
| 74 | <code>#else</code> | Use the POSIX local-time conversion on non-Windows platforms. |
| 75 | <code>    localtime_r(&amp;now, &amp;local);</code> | Call `localtime_r` with the shown arguments. The call performs its named operation within currentTimestamp. |
| 76 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
| 77 | <code>    ostringstream stamp;</code> | Declare member `stamp` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 78 | <code>    stamp &lt;&lt; put_time(&amp;local, &quot;%Y-%m-%d %H:%M:%S&quot;);</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 79 | <code>    return stamp.str();</code> | Return the value of `stamp.str()` to the caller. This ends the function once its full return expression is evaluated. |
| 80 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 81 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 82 | <code>inline bool isTerminal(ParcelStatus status) {</code> | Define `isTerminal`. Recognize the four parcel states that must never reopen. |
| 83 | <code>    return status == ParcelStatus::Collected &#124;&#124; status == ParcelStatus::Delivered</code> | Return the value of `status == ParcelStatus::Collected &#124;&#124; status == ParcelStatus::Delivered` to the caller. This ends the function once its full return expression is evaluated. |
| 84 | <code>        &#124;&#124; status == ParcelStatus::Returned &#124;&#124; status == ParcelStatus::Cancelled;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 85 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 87 | <code>inline bool isActive(RequestStatus status) {</code> | Define `isActive`. Recognize the three request states that still count as active work. |
| 88 | <code>    return status == RequestStatus::Pending &#124;&#124; status == RequestStatus::Assigned</code> | Return the value of `status == RequestStatus::Pending &#124;&#124; status == RequestStatus::Assigned` to the caller. This ends the function once its full return expression is evaluated. |
| 89 | <code>        &#124;&#124; status == RequestStatus::InProgress;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 90 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 91 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 92 | <code>inline bool validService(ServiceType type) {</code> | Define `validService`. Reject service enum values outside the five defined services. |
| 93 | <code>    return type &gt;= ServiceType::Collection &amp;&amp; type &lt;= ServiceType::ReturnToSender;</code> | Return the value of `type >= ServiceType::Collection && type <= ServiceType::ReturnToSender` to the caller. This ends the function once its full return expression is evaluated. |
| 94 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 95 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 96 | <code>// the request type determines which parcel status it must have</code> | Comment explaining intent: the request type determines which parcel status it must have |
| 97 | <code>inline ParcelStatus serviceStatus(ServiceType type) {</code> | Define `serviceStatus`. Map a valid service to its required active parcel status; creation and later validation share this mapping. |
| 98 | <code>    switch (type) {</code> | Select a branch according to the enum/menu expression `(type)`. |
| 99 | <code>    case ServiceType::Collection: return ParcelStatus::AwaitingCollection;</code> | Handle this switch case `ServiceType::Collection`. Return the value of `ParcelStatus::AwaitingCollection` to the caller. This ends the function once its full return expression is evaluated. |
| 100 | <code>    case ServiceType::CampusDelivery:</code> | Handle this switch case `ServiceType::CampusDelivery`. Begin its branch. |
| 101 | <code>    case ServiceType::Redelivery: return ParcelStatus::AwaitingDelivery;</code> | Handle this switch case `ServiceType::Redelivery`. Return the value of `ParcelStatus::AwaitingDelivery` to the caller. This ends the function once its full return expression is evaluated. |
| 102 | <code>    case ServiceType::SpecialHandling: return ParcelStatus::SpecialHandling;</code> | Handle this switch case `ServiceType::SpecialHandling`. Return the value of `ParcelStatus::SpecialHandling` to the caller. This ends the function once its full return expression is evaluated. |
| 103 | <code>    case ServiceType::ReturnToSender: return ParcelStatus::ReturnPending;</code> | Handle this switch case `ServiceType::ReturnToSender`. Return the value of `ParcelStatus::ReturnPending` to the caller. This ends the function once its full return expression is evaluated. |
| 104 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 105 | <code>    return ParcelStatus::OnHold;</code> | Return the value of `ParcelStatus::OnHold` to the caller. This ends the function once its full return expression is evaluated. |
| 106 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 107 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 108 | <code>inline ResourceType serviceResource(ServiceType type) {</code> | Define `serviceResource`. Require a counter for collection and delivery personnel for the other four team-defined services. |
| 109 | <code>    if (type == ServiceType::Collection) return ResourceType::CollectionCounter;</code> | Test `type == ServiceType::Collection`. Return the value of `ResourceType::CollectionCounter` to the caller. This ends the function once its full return expression is evaluated. |
| 110 | <code>    return ResourceType::DeliveryPersonnel;</code> | Return the value of `ResourceType::DeliveryPersonnel` to the caller. This ends the function once its full return expression is evaluated. |
| 111 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 112 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 113 | <code>inline const char* toString(ParcelStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 114 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 115 | <code>    case ParcelStatus::Received: return &quot;Received&quot;;</code> | Handle this switch case `ParcelStatus::Received`. Return the value of `"Received"` to the caller. This ends the function once its full return expression is evaluated. |
| 116 | <code>    case ParcelStatus::AwaitingCollection: return &quot;Awaiting collection&quot;;</code> | Handle this switch case `ParcelStatus::AwaitingCollection`. Return the value of `"Awaiting collection"` to the caller. This ends the function once its full return expression is evaluated. |
| 117 | <code>    case ParcelStatus::AwaitingDelivery: return &quot;Awaiting delivery&quot;;</code> | Handle this switch case `ParcelStatus::AwaitingDelivery`. Return the value of `"Awaiting delivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 118 | <code>    case ParcelStatus::SpecialHandling: return &quot;Special handling&quot;;</code> | Handle this switch case `ParcelStatus::SpecialHandling`. Return the value of `"Special handling"` to the caller. This ends the function once its full return expression is evaluated. |
| 119 | <code>    case ParcelStatus::ReturnPending: return &quot;Return pending&quot;;</code> | Handle this switch case `ParcelStatus::ReturnPending`. Return the value of `"Return pending"` to the caller. This ends the function once its full return expression is evaluated. |
| 120 | <code>    case ParcelStatus::OnHold: return &quot;On hold&quot;;</code> | Handle this switch case `ParcelStatus::OnHold`. Return the value of `"On hold"` to the caller. This ends the function once its full return expression is evaluated. |
| 121 | <code>    case ParcelStatus::Missing: return &quot;Missing&quot;;</code> | Handle this switch case `ParcelStatus::Missing`. Return the value of `"Missing"` to the caller. This ends the function once its full return expression is evaluated. |
| 122 | <code>    case ParcelStatus::Collected: return &quot;Collected&quot;;</code> | Handle this switch case `ParcelStatus::Collected`. Return the value of `"Collected"` to the caller. This ends the function once its full return expression is evaluated. |
| 123 | <code>    case ParcelStatus::Delivered: return &quot;Delivered&quot;;</code> | Handle this switch case `ParcelStatus::Delivered`. Return the value of `"Delivered"` to the caller. This ends the function once its full return expression is evaluated. |
| 124 | <code>    case ParcelStatus::Returned: return &quot;Returned&quot;;</code> | Handle this switch case `ParcelStatus::Returned`. Return the value of `"Returned"` to the caller. This ends the function once its full return expression is evaluated. |
| 125 | <code>    case ParcelStatus::Cancelled: return &quot;Cancelled&quot;;</code> | Handle this switch case `ParcelStatus::Cancelled`. Return the value of `"Cancelled"` to the caller. This ends the function once its full return expression is evaluated. |
| 126 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 127 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 128 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 129 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 130 | <code>inline const char* toString(RequestStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 131 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 132 | <code>    case RequestStatus::Pending: return &quot;Pending&quot;;</code> | Handle this switch case `RequestStatus::Pending`. Return the value of `"Pending"` to the caller. This ends the function once its full return expression is evaluated. |
| 133 | <code>    case RequestStatus::Assigned: return &quot;Assigned&quot;;</code> | Handle this switch case `RequestStatus::Assigned`. Return the value of `"Assigned"` to the caller. This ends the function once its full return expression is evaluated. |
| 134 | <code>    case RequestStatus::InProgress: return &quot;In progress&quot;;</code> | Handle this switch case `RequestStatus::InProgress`. Return the value of `"In progress"` to the caller. This ends the function once its full return expression is evaluated. |
| 135 | <code>    case RequestStatus::Completed: return &quot;Completed&quot;;</code> | Handle this switch case `RequestStatus::Completed`. Return the value of `"Completed"` to the caller. This ends the function once its full return expression is evaluated. |
| 136 | <code>    case RequestStatus::Cancelled: return &quot;Cancelled&quot;;</code> | Handle this switch case `RequestStatus::Cancelled`. Return the value of `"Cancelled"` to the caller. This ends the function once its full return expression is evaluated. |
| 137 | <code>    case RequestStatus::Returned: return &quot;Returned&quot;;</code> | Handle this switch case `RequestStatus::Returned`. Return the value of `"Returned"` to the caller. This ends the function once its full return expression is evaluated. |
| 138 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 139 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 140 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 141 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 142 | <code>inline const char* toString(ServiceType type) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 143 | <code>    switch (type) {</code> | Select a branch according to the enum/menu expression `(type)`. |
| 144 | <code>    case ServiceType::Collection: return &quot;Collection&quot;;</code> | Handle this switch case `ServiceType::Collection`. Return the value of `"Collection"` to the caller. This ends the function once its full return expression is evaluated. |
| 145 | <code>    case ServiceType::CampusDelivery: return &quot;Campus delivery&quot;;</code> | Handle this switch case `ServiceType::CampusDelivery`. Return the value of `"Campus delivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 146 | <code>    case ServiceType::SpecialHandling: return &quot;Special handling&quot;;</code> | Handle this switch case `ServiceType::SpecialHandling`. Return the value of `"Special handling"` to the caller. This ends the function once its full return expression is evaluated. |
| 147 | <code>    case ServiceType::Redelivery: return &quot;Redelivery&quot;;</code> | Handle this switch case `ServiceType::Redelivery`. Return the value of `"Redelivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 148 | <code>    case ServiceType::ReturnToSender: return &quot;Return to sender&quot;;</code> | Handle this switch case `ServiceType::ReturnToSender`. Return the value of `"Return to sender"` to the caller. This ends the function once its full return expression is evaluated. |
| 149 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 150 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 151 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 152 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 153 | <code>inline const char* toString(ResourceStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 154 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 155 | <code>    case ResourceStatus::Available: return &quot;Available&quot;;</code> | Handle this switch case `ResourceStatus::Available`. Return the value of `"Available"` to the caller. This ends the function once its full return expression is evaluated. |
| 156 | <code>    case ResourceStatus::Occupied: return &quot;Occupied&quot;;</code> | Handle this switch case `ResourceStatus::Occupied`. Return the value of `"Occupied"` to the caller. This ends the function once its full return expression is evaluated. |
| 157 | <code>    case ResourceStatus::Unavailable: return &quot;Unavailable&quot;;</code> | Handle this switch case `ResourceStatus::Unavailable`. Return the value of `"Unavailable"` to the caller. This ends the function once its full return expression is evaluated. |
| 158 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 159 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 160 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 161 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 162 | <code>inline void printParcel(const Parcel&amp; parcel) {</code> | Define `printParcel`. Print all parcel details and current status on a pipe-separated console row. |
| 163 | <code>    cout &lt;&lt; parcel.id &lt;&lt; &quot; &#124; &quot; &lt;&lt; parcel.recipientName &lt;&lt; &quot; &#124; recipient &quot; &lt;&lt; parcel.recipientId</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 164 | <code>         &lt;&lt; &quot; &#124; contact &quot; &lt;&lt; parcel.recipientContact &lt;&lt; &quot; &#124; carrier &quot; &lt;&lt; parcel.deliveryCompany</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 165 | <code>         &lt;&lt; &quot; &#124; tracking &quot; &lt;&lt; parcel.trackingNumber &lt;&lt; &quot; &#124; destination &quot; &lt;&lt; parcel.destination</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 166 | <code>         &lt;&lt; &quot; &#124; type &quot; &lt;&lt; parcel.parcelType &lt;&lt; &quot; &#124; status &quot; &lt;&lt; toString(parcel.status)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 167 | <code>         &lt;&lt; &quot; &#124; arrived &quot; &lt;&lt; parcel.arrivalTime &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 168 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 169 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 170 | <code>inline void printRequest(const ServiceRequest&amp; request) {</code> | Define `printRequest`. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 171 | <code>    cout &lt;&lt; request.id &lt;&lt; &quot; &#124; parcel &quot; &lt;&lt; request.parcelId &lt;&lt; &quot; &#124; &quot; &lt;&lt; toString(request.type)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 172 | <code>         &lt;&lt; &quot; &#124; &quot; &lt;&lt; (request.priority == RequestPriority::Urgent ? &quot;Urgent&quot; : &quot;Normal&quot;)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 173 | <code>         &lt;&lt; &quot; &#124; status &quot; &lt;&lt; toString(request.status) &lt;&lt; &quot; &#124; recipient &quot; &lt;&lt; request.recipientId</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 174 | <code>         &lt;&lt; &quot; &#124; details &quot; &lt;&lt; request.serviceDetails &lt;&lt; &quot; &#124; created &quot; &lt;&lt; request.createdAt</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 175 | <code>         &lt;&lt; &quot; &#124; resource &quot; &lt;&lt; (request.resourceId.empty() ? &quot;-&quot; : request.resourceId)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 176 | <code>         &lt;&lt; &quot; &#124; outcome &quot; &lt;&lt; (request.outcomeDetails.empty() ? &quot;-&quot; : request.outcomeDetails) &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 177 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 178 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 179 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 180 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
