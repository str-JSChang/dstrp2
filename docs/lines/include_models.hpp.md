# include/models.hpp - every line explained

Source: [include/models.hpp](../../include/models.hpp)

Physical lines: 228; SHA-256 (LF text): `d5fa672eaea3c051c5e938e9bfb73992b25aa17eff99ffc8e123025e4b633417`.

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
| 64 | <code>    if (first == string::npos) {</code> | Test `first == string::npos`. Run the following guarded block only when true. |
| 65 | <code>        return &quot;&quot;;</code> | Return the value of `""` to the caller. This ends the function once its full return expression is evaluated. |
| 66 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 67 | <code>    size_t last = text.find_last_not_of(&quot; \t\r\n&quot;);</code> | Declare member `last` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 68 | <code>    return text.substr(first, last - first + 1);</code> | Return the value of `text.substr(first, last - first + 1)` to the caller. This ends the function once its full return expression is evaluated. |
| 69 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 70 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 71 | <code>inline string currentTimestamp() {</code> | Define `currentTimestamp`. Produce the local YYYY-MM-DD HH:MM:SS arrival/request timestamp using the correct Windows/POSIX localtime function. |
| 72 | <code>    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());</code> | Declare member `now` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 73 | <code>    tm local = {};</code> | Declare member `local` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 74 | <code>#ifdef _WIN32</code> | Select Windows-specific local-time conversion when compiled for Windows. |
| 75 | <code>    localtime_s(&amp;local, &amp;now);</code> | Call `localtime_s` with the shown arguments. The call performs its named operation within currentTimestamp. |
| 76 | <code>#else</code> | Use the POSIX local-time conversion on non-Windows platforms. |
| 77 | <code>    localtime_r(&amp;now, &amp;local);</code> | Call `localtime_r` with the shown arguments. The call performs its named operation within currentTimestamp. |
| 78 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
| 79 | <code>    ostringstream stamp;</code> | Declare member `stamp` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 80 | <code>    stamp &lt;&lt; put_time(&amp;local, &quot;%Y-%m-%d %H:%M:%S&quot;);</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 81 | <code>    return stamp.str();</code> | Return the value of `stamp.str()` to the caller. This ends the function once its full return expression is evaluated. |
| 82 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 83 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 84 | <code>inline bool isTerminal(ParcelStatus status) {</code> | Define `isTerminal`. Recognize the four parcel states that must never reopen. |
| 85 | <code>    return status == ParcelStatus::Collected &#124;&#124; status == ParcelStatus::Delivered</code> | Return the value of `status == ParcelStatus::Collected &#124;&#124; status == ParcelStatus::Delivered` to the caller. This ends the function once its full return expression is evaluated. |
| 86 | <code>        &#124;&#124; status == ParcelStatus::Returned &#124;&#124; status == ParcelStatus::Cancelled;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 87 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 88 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 89 | <code>inline bool isActive(RequestStatus status) {</code> | Define `isActive`. Recognize the three request states that still count as active work. |
| 90 | <code>    return status == RequestStatus::Pending &#124;&#124; status == RequestStatus::Assigned</code> | Return the value of `status == RequestStatus::Pending &#124;&#124; status == RequestStatus::Assigned` to the caller. This ends the function once its full return expression is evaluated. |
| 91 | <code>        &#124;&#124; status == RequestStatus::InProgress;</code> | Continue the preceding short-circuit boolean expression with an alternative accepted/rejected condition (OR). |
| 92 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 93 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 94 | <code>inline bool validService(ServiceType type) {</code> | Define `validService`. Reject service enum values outside the five defined services. |
| 95 | <code>    return type &gt;= ServiceType::Collection &amp;&amp; type &lt;= ServiceType::ReturnToSender;</code> | Return the value of `type >= ServiceType::Collection && type <= ServiceType::ReturnToSender` to the caller. This ends the function once its full return expression is evaluated. |
| 96 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 97 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 98 | <code>// the request type determines which parcel status it must have</code> | Comment explaining intent: the request type determines which parcel status it must have |
| 99 | <code>inline ParcelStatus serviceStatus(ServiceType type) {</code> | Define `serviceStatus`. Map a valid service to its required active parcel status; creation and later validation share this mapping. |
| 100 | <code>    switch (type) {</code> | Select a branch according to the enum/menu expression `(type)`. |
| 101 | <code>    case ServiceType::Collection:</code> | Handle this switch case `ServiceType::Collection`. Begin its branch. |
| 102 | <code>        return ParcelStatus::AwaitingCollection;</code> | Return the value of `ParcelStatus::AwaitingCollection` to the caller. This ends the function once its full return expression is evaluated. |
| 103 | <code>    case ServiceType::CampusDelivery:</code> | Handle this switch case `ServiceType::CampusDelivery`. Begin its branch. |
| 104 | <code>    case ServiceType::Redelivery:</code> | Handle this switch case `ServiceType::Redelivery`. Begin its branch. |
| 105 | <code>        return ParcelStatus::AwaitingDelivery;</code> | Return the value of `ParcelStatus::AwaitingDelivery` to the caller. This ends the function once its full return expression is evaluated. |
| 106 | <code>    case ServiceType::SpecialHandling:</code> | Handle this switch case `ServiceType::SpecialHandling`. Begin its branch. |
| 107 | <code>        return ParcelStatus::SpecialHandling;</code> | Return the value of `ParcelStatus::SpecialHandling` to the caller. This ends the function once its full return expression is evaluated. |
| 108 | <code>    case ServiceType::ReturnToSender:</code> | Handle this switch case `ServiceType::ReturnToSender`. Begin its branch. |
| 109 | <code>        return ParcelStatus::ReturnPending;</code> | Return the value of `ParcelStatus::ReturnPending` to the caller. This ends the function once its full return expression is evaluated. |
| 110 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 111 | <code>    return ParcelStatus::OnHold;</code> | Return the value of `ParcelStatus::OnHold` to the caller. This ends the function once its full return expression is evaluated. |
| 112 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 113 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 114 | <code>inline ResourceType serviceResource(ServiceType type) {</code> | Define `serviceResource`. Require a counter for collection and delivery personnel for the other four team-defined services. |
| 115 | <code>    if (type == ServiceType::Collection) {</code> | Test `type == ServiceType::Collection`. Run the following guarded block only when true. |
| 116 | <code>        return ResourceType::CollectionCounter;</code> | Return the value of `ResourceType::CollectionCounter` to the caller. This ends the function once its full return expression is evaluated. |
| 117 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 118 | <code>    return ResourceType::DeliveryPersonnel;</code> | Return the value of `ResourceType::DeliveryPersonnel` to the caller. This ends the function once its full return expression is evaluated. |
| 119 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 120 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 121 | <code>inline const char* toString(ParcelStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 122 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 123 | <code>    case ParcelStatus::Received:</code> | Handle this switch case `ParcelStatus::Received`. Begin its branch. |
| 124 | <code>        return &quot;Received&quot;;</code> | Return the value of `"Received"` to the caller. This ends the function once its full return expression is evaluated. |
| 125 | <code>    case ParcelStatus::AwaitingCollection:</code> | Handle this switch case `ParcelStatus::AwaitingCollection`. Begin its branch. |
| 126 | <code>        return &quot;Awaiting collection&quot;;</code> | Return the value of `"Awaiting collection"` to the caller. This ends the function once its full return expression is evaluated. |
| 127 | <code>    case ParcelStatus::AwaitingDelivery:</code> | Handle this switch case `ParcelStatus::AwaitingDelivery`. Begin its branch. |
| 128 | <code>        return &quot;Awaiting delivery&quot;;</code> | Return the value of `"Awaiting delivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 129 | <code>    case ParcelStatus::SpecialHandling:</code> | Handle this switch case `ParcelStatus::SpecialHandling`. Begin its branch. |
| 130 | <code>        return &quot;Special handling&quot;;</code> | Return the value of `"Special handling"` to the caller. This ends the function once its full return expression is evaluated. |
| 131 | <code>    case ParcelStatus::ReturnPending:</code> | Handle this switch case `ParcelStatus::ReturnPending`. Begin its branch. |
| 132 | <code>        return &quot;Return pending&quot;;</code> | Return the value of `"Return pending"` to the caller. This ends the function once its full return expression is evaluated. |
| 133 | <code>    case ParcelStatus::OnHold:</code> | Handle this switch case `ParcelStatus::OnHold`. Begin its branch. |
| 134 | <code>        return &quot;On hold&quot;;</code> | Return the value of `"On hold"` to the caller. This ends the function once its full return expression is evaluated. |
| 135 | <code>    case ParcelStatus::Missing:</code> | Handle this switch case `ParcelStatus::Missing`. Begin its branch. |
| 136 | <code>        return &quot;Missing&quot;;</code> | Return the value of `"Missing"` to the caller. This ends the function once its full return expression is evaluated. |
| 137 | <code>    case ParcelStatus::Collected:</code> | Handle this switch case `ParcelStatus::Collected`. Begin its branch. |
| 138 | <code>        return &quot;Collected&quot;;</code> | Return the value of `"Collected"` to the caller. This ends the function once its full return expression is evaluated. |
| 139 | <code>    case ParcelStatus::Delivered:</code> | Handle this switch case `ParcelStatus::Delivered`. Begin its branch. |
| 140 | <code>        return &quot;Delivered&quot;;</code> | Return the value of `"Delivered"` to the caller. This ends the function once its full return expression is evaluated. |
| 141 | <code>    case ParcelStatus::Returned:</code> | Handle this switch case `ParcelStatus::Returned`. Begin its branch. |
| 142 | <code>        return &quot;Returned&quot;;</code> | Return the value of `"Returned"` to the caller. This ends the function once its full return expression is evaluated. |
| 143 | <code>    case ParcelStatus::Cancelled:</code> | Handle this switch case `ParcelStatus::Cancelled`. Begin its branch. |
| 144 | <code>        return &quot;Cancelled&quot;;</code> | Return the value of `"Cancelled"` to the caller. This ends the function once its full return expression is evaluated. |
| 145 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 146 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 147 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 148 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 149 | <code>inline const char* toString(RequestStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 150 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 151 | <code>    case RequestStatus::Pending:</code> | Handle this switch case `RequestStatus::Pending`. Begin its branch. |
| 152 | <code>        return &quot;Pending&quot;;</code> | Return the value of `"Pending"` to the caller. This ends the function once its full return expression is evaluated. |
| 153 | <code>    case RequestStatus::Assigned:</code> | Handle this switch case `RequestStatus::Assigned`. Begin its branch. |
| 154 | <code>        return &quot;Assigned&quot;;</code> | Return the value of `"Assigned"` to the caller. This ends the function once its full return expression is evaluated. |
| 155 | <code>    case RequestStatus::InProgress:</code> | Handle this switch case `RequestStatus::InProgress`. Begin its branch. |
| 156 | <code>        return &quot;In progress&quot;;</code> | Return the value of `"In progress"` to the caller. This ends the function once its full return expression is evaluated. |
| 157 | <code>    case RequestStatus::Completed:</code> | Handle this switch case `RequestStatus::Completed`. Begin its branch. |
| 158 | <code>        return &quot;Completed&quot;;</code> | Return the value of `"Completed"` to the caller. This ends the function once its full return expression is evaluated. |
| 159 | <code>    case RequestStatus::Cancelled:</code> | Handle this switch case `RequestStatus::Cancelled`. Begin its branch. |
| 160 | <code>        return &quot;Cancelled&quot;;</code> | Return the value of `"Cancelled"` to the caller. This ends the function once its full return expression is evaluated. |
| 161 | <code>    case RequestStatus::Returned:</code> | Handle this switch case `RequestStatus::Returned`. Begin its branch. |
| 162 | <code>        return &quot;Returned&quot;;</code> | Return the value of `"Returned"` to the caller. This ends the function once its full return expression is evaluated. |
| 163 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 164 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 165 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 166 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 167 | <code>inline const char* toString(ServiceType type) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 168 | <code>    switch (type) {</code> | Select a branch according to the enum/menu expression `(type)`. |
| 169 | <code>    case ServiceType::Collection:</code> | Handle this switch case `ServiceType::Collection`. Begin its branch. |
| 170 | <code>        return &quot;Collection&quot;;</code> | Return the value of `"Collection"` to the caller. This ends the function once its full return expression is evaluated. |
| 171 | <code>    case ServiceType::CampusDelivery:</code> | Handle this switch case `ServiceType::CampusDelivery`. Begin its branch. |
| 172 | <code>        return &quot;Campus delivery&quot;;</code> | Return the value of `"Campus delivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 173 | <code>    case ServiceType::SpecialHandling:</code> | Handle this switch case `ServiceType::SpecialHandling`. Begin its branch. |
| 174 | <code>        return &quot;Special handling&quot;;</code> | Return the value of `"Special handling"` to the caller. This ends the function once its full return expression is evaluated. |
| 175 | <code>    case ServiceType::Redelivery:</code> | Handle this switch case `ServiceType::Redelivery`. Begin its branch. |
| 176 | <code>        return &quot;Redelivery&quot;;</code> | Return the value of `"Redelivery"` to the caller. This ends the function once its full return expression is evaluated. |
| 177 | <code>    case ServiceType::ReturnToSender:</code> | Handle this switch case `ServiceType::ReturnToSender`. Begin its branch. |
| 178 | <code>        return &quot;Return to sender&quot;;</code> | Return the value of `"Return to sender"` to the caller. This ends the function once its full return expression is evaluated. |
| 179 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 180 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 181 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 182 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 183 | <code>inline const char* toString(ResourceStatus status) {</code> | Define `toString`. Convert the selected enum type to readable console text. Overloading chooses the appropriate mapping. |
| 184 | <code>    switch (status) {</code> | Select a branch according to the enum/menu expression `(status)`. |
| 185 | <code>    case ResourceStatus::Available:</code> | Handle this switch case `ResourceStatus::Available`. Begin its branch. |
| 186 | <code>        return &quot;Available&quot;;</code> | Return the value of `"Available"` to the caller. This ends the function once its full return expression is evaluated. |
| 187 | <code>    case ResourceStatus::Occupied:</code> | Handle this switch case `ResourceStatus::Occupied`. Begin its branch. |
| 188 | <code>        return &quot;Occupied&quot;;</code> | Return the value of `"Occupied"` to the caller. This ends the function once its full return expression is evaluated. |
| 189 | <code>    case ResourceStatus::Unavailable:</code> | Handle this switch case `ResourceStatus::Unavailable`. Begin its branch. |
| 190 | <code>        return &quot;Unavailable&quot;;</code> | Return the value of `"Unavailable"` to the caller. This ends the function once its full return expression is evaluated. |
| 191 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 192 | <code>    return &quot;Unknown&quot;;</code> | Return the value of `"Unknown"` to the caller. This ends the function once its full return expression is evaluated. |
| 193 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 194 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 195 | <code>inline void printParcel(const Parcel&amp; parcel) {</code> | Define `printParcel`. Print all parcel details and current status on a pipe-separated console row. |
| 196 | <code>    cout &lt;&lt; parcel.id &lt;&lt; &quot; &#124; &quot; &lt;&lt; parcel.recipientName &lt;&lt; &quot; &#124; recipient &quot; &lt;&lt; parcel.recipientId</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 197 | <code>         &lt;&lt; &quot; &#124; contact &quot; &lt;&lt; parcel.recipientContact &lt;&lt; &quot; &#124; carrier &quot; &lt;&lt; parcel.deliveryCompany</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 198 | <code>         &lt;&lt; &quot; &#124; tracking &quot; &lt;&lt; parcel.trackingNumber &lt;&lt; &quot; &#124; destination &quot; &lt;&lt; parcel.destination</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 199 | <code>         &lt;&lt; &quot; &#124; type &quot; &lt;&lt; parcel.parcelType &lt;&lt; &quot; &#124; status &quot; &lt;&lt; toString(parcel.status)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 200 | <code>         &lt;&lt; &quot; &#124; arrived &quot; &lt;&lt; parcel.arrivalTime &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 201 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 202 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 203 | <code>inline void printRequest(const ServiceRequest&amp; request) {</code> | Define `printRequest`. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 204 | <code>    string priorityName = &quot;Normal&quot;;</code> | Declare member `priorityName` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 205 | <code>    if (request.priority == RequestPriority::Urgent) {</code> | Test `request.priority == RequestPriority::Urgent`. Run the following guarded block only when true. |
| 206 | <code>        priorityName = &quot;Urgent&quot;;</code> | Set `priorityName` to `"Urgent"`. |
| 207 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 208 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 209 | <code>    string resourceName = &quot;-&quot;;</code> | Declare member `resourceName` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 210 | <code>    if (!request.resourceId.empty()) {</code> | Test `!request.resourceId.empty()`. Run the following guarded block only when true. |
| 211 | <code>        resourceName = request.resourceId;</code> | Set `resourceName` to `request.resourceId`. |
| 212 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 213 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 214 | <code>    string outcomeText = &quot;-&quot;;</code> | Declare member `outcomeText` using the type and initializer shown. It belongs to each instance of the enclosing type. |
| 215 | <code>    if (!request.outcomeDetails.empty()) {</code> | Test `!request.outcomeDetails.empty()`. Run the following guarded block only when true. |
| 216 | <code>        outcomeText = request.outcomeDetails;</code> | Set `outcomeText` to `request.outcomeDetails`. |
| 217 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 218 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 219 | <code>    cout &lt;&lt; request.id &lt;&lt; &quot; &#124; parcel &quot; &lt;&lt; request.parcelId &lt;&lt; &quot; &#124; &quot; &lt;&lt; toString(request.type)</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 220 | <code>         &lt;&lt; &quot; &#124; &quot; &lt;&lt; priorityName</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 221 | <code>         &lt;&lt; &quot; &#124; status &quot; &lt;&lt; toString(request.status) &lt;&lt; &quot; &#124; recipient &quot; &lt;&lt; request.recipientId</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 222 | <code>         &lt;&lt; &quot; &#124; details &quot; &lt;&lt; request.serviceDetails &lt;&lt; &quot; &#124; created &quot; &lt;&lt; request.createdAt</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 223 | <code>         &lt;&lt; &quot; &#124; resource &quot; &lt;&lt; resourceName</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 224 | <code>         &lt;&lt; &quot; &#124; outcome &quot; &lt;&lt; outcomeText &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 225 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 226 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 227 | <code>} // namespace campus</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 228 | <code>#endif</code> | End the conditional preprocessing block; preprocessing itself does not run at program runtime. |
