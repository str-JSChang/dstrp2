# src/main.cpp - every line explained

Source: [src/main.cpp](../../src/main.cpp)

Physical lines: 268; SHA-256 (LF text): `d702d6b8478f8f96ba6f63567aeec872741e19b964fb93d82f65c6dc9ae57332`.

The explanations accompany the exact lines below. Pointer algorithms and cross-module state rules are expanded in the [technical guide](../TECHNICAL_GUIDE.md).

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>#include &quot;task1.hpp&quot;</code> | Include `"task1.hpp"` for Task 1 declarations. |
| 2 | <code>#include &quot;task2.hpp&quot;</code> | Include `"task2.hpp"` for Task 2 declarations. |
| 3 | <code>#include &quot;task3.hpp&quot;</code> | Include `"task3.hpp"` for Task 3 declarations. |
| 4 | <code>#include &lt;iostream&gt;</code> | Include `<iostream>` for console streams. |
| 5 | <code>#include &lt;sstream&gt;</code> | Include `<sstream>` for string-backed input/output streams. |
| 6 | <code>#include &lt;string&gt;</code> | Include `<string>` for string storage and operations. |
| 7 | <code>#include &lt;exception&gt;</code> | Include `<exception>` for standard exception reporting. |
| 8 | <code>using namespace std;</code> | Make names from `std` available without repeating that namespace prefix. |
| 9 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 10 | <code>namespace {</code> | Open an unnamed, translation-unit-local helper namespace. |
| 11 | <code>using namespace campus;</code> | Make names from `campus` available without repeating that namespace prefix. |
| 12 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 13 | <code>string readText(const char* prompt) {</code> | Define `readText`. Read one whole line, trim outside whitespace and suppress further prompts once the input stream has ended. |
| 14 | <code>    if (!cin) return &quot;&quot;;</code> | Test `!cin`. Return the value of `""` to the caller. This ends the function once its full return expression is evaluated. |
| 15 | <code>    cout &lt;&lt; prompt;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 16 | <code>    string text;</code> | Create local `text` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 17 | <code>    getline(cin, text);</code> | Call `getline` with the shown arguments. The call performs its named operation within readText. |
| 18 | <code>    return trim(text);</code> | Return the value of `trim(text)` to the caller. This ends the function once its full return expression is evaluated. |
| 19 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 20 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 21 | <code>// EOF exits menus cleanly; malformed or out-of-range input is retried.</code> | Comment explaining intent: EOF exits menus cleanly; malformed or out-of-range input is retried. |
| 22 | <code>int choice(const char* prompt, int low, int high) {</code> | Define `choice`. Read an integer from a complete line; reject extra characters, overflow and out-of-range values; return zero on EOF. |
| 23 | <code>    for (;;) {</code> | Repeat menu input indefinitely until a valid value returns or EOF exits. |
| 24 | <code>        const string line = readText(prompt);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 25 | <code>        if (!cin) return 0;</code> | Test `!cin`. Return normal exit/back/EOF value for this function. |
| 26 | <code>        istringstream input(line);</code> | Call `input` with the shown arguments. The call performs its named operation within choice. |
| 27 | <code>        int value = 0;</code> | Create local `value` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 28 | <code>        char extra = &#x27;\0&#x27;;</code> | Create local `extra` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 29 | <code>        if ((input &gt;&gt; value) &amp;&amp; !(input &gt;&gt; extra) &amp;&amp; value &gt;= low &amp;&amp; value &lt;= high)</code> | Begin a multiline guard with `(input >> value) && !(input >> extra) && value >= low && value <= high)`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 30 | <code>            return value;</code> | Return the value of `value` to the caller. This ends the function once its full return expression is evaluated. |
| 31 | <code>        cout &lt;&lt; &quot;Enter a number from &quot; &lt;&lt; low &lt;&lt; &quot; to &quot; &lt;&lt; high &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 32 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 33 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 34 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 35 | <code>Parcel readParcelDetails() {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 36 | <code>    Parcel parcel;</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 37 | <code>    parcel.recipientName = readText(&quot;Recipient name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 38 | <code>    parcel.recipientId = readText(&quot;Recipient student/staff ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 39 | <code>    parcel.recipientContact = readText(&quot;Recipient contact: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 40 | <code>    parcel.deliveryCompany = readText(&quot;Delivery company: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 41 | <code>    parcel.trackingNumber = readText(&quot;Tracking number: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 42 | <code>    parcel.destination = readText(&quot;Campus destination: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 43 | <code>    parcel.parcelType = readText(&quot;Parcel type: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 44 | <code>    return parcel;</code> | Return the value of `parcel` to the caller. This ends the function once its full return expression is evaluated. |
| 45 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 46 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 47 | <code>void showResult(bool success) {</code> | Define `showResult`. Display success only when the called operation returned true; otherwise point to its failure message. |
| 48 | <code>    if (success) cout &lt;&lt; &quot;Operation successful.\n&quot;;</code> | Test `success`. Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 49 | <code>    else cout &lt;&lt; &quot;Operation failed; see the reason above.\n&quot;;</code> | When the preceding condition is false, Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 50 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 51 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 52 | <code>void parcelMenu(ParcelModule&amp; parcels, ServiceModule&amp; services) {</code> | Define `parcelMenu`. Repeat Task 1 choices and collect inputs for registration, routing, editing, status, removal and recovery. |
| 53 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 54 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 55 | <code>            &quot;\nTASK 1 - PARCEL INTAKE\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 56 | <code>            &quot;1. Register parcel\n2. Display parcels\n3. Search parcel\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 57 | <code>            &quot;4. Process next waiting parcel\n5. Update parcel details\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 58 | <code>            &quot;6. Remove cancelled parcel\n7. Display waiting queue\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 59 | <code>            &quot;8. Report missing / place on hold\n9. Resume held/recovered parcel\n0. Back\nChoice: &quot;, 0, 9);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 60 | <code>        if (action == 0) return;</code> | Test `action == 0`. Return immediately from this void function; no further statements in it execute. |
| 61 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 62 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 63 | <code>            const Parcel parcel = readParcelDetails();</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 64 | <code>            if (cin) showResult(parcels.registerParcel(parcel));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 65 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 66 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 67 | <code>        case 2: parcels.displayParcels(); break;</code> | Handle this switch case `2`. Call `parcels.displayParcels` with the shown arguments. The call performs its named operation within parcelMenu. Then leave the switch to prevent fall-through. |
| 68 | <code>        case 3: {</code> | Handle this switch case `3`. Begin its branch. |
| 69 | <code>            const auto id = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 70 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 71 | <code>                if (const Parcel* parcel = parcels.findParcel(id))</code> | Begin a multiline guard with `const Parcel* parcel = parcels.findParcel(id))`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 72 | <code>                    printParcel(*parcel);</code> | Call `printParcel` with the shown arguments. Print all parcel details and current status on a pipe-separated console row. |
| 73 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 74 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 75 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 76 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 77 | <code>            const int route = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n&quot;</code> | Create local `route` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 78 | <code>                                     &quot;4. Return to sender\n5. Investigation hold\n0. Cancel\nRoute: &quot;, 0, 5);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 79 | <code>            if (route) {</code> | Test `route`. Run the following guarded block only when true. |
| 80 | <code>                int priority = route == 5 ? 2 : choice(&quot;1. Urgent\n2. Normal\n0. Cancel\nPriority: &quot;, 0, 2);</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 81 | <code>                if (priority) showResult(parcels.processNext(static_cast&lt;Route&gt;(route - 1), services,</code> | Begin a multiline guard with `priority) showResult(parcels.processNext(static_cast<Route>(route - 1), services,`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 82 | <code>                    priority == 1 ? RequestPriority::Urgent : RequestPriority::Normal));</code> | Call `the indicated helper` with the shown arguments. The call performs its named operation within parcelMenu. |
| 83 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 84 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 85 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 86 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 87 | <code>            const auto id = readText(&quot;Parcel ID to update: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 88 | <code>            Parcel replacement = readParcelDetails();</code> | Create local `replacement` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 89 | <code>            replacement.id = id;</code> | Set `replacement.id` to `id`. |
| 90 | <code>            if (cin) showResult(parcels.updateParcel(id, replacement, services));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 91 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 92 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 93 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 94 | <code>            const auto id = readText(&quot;Cancelled parcel ID to remove: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 95 | <code>            if (cin) showResult(parcels.removeParcel(id, services));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 96 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 97 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 98 | <code>        case 7: parcels.displayWaiting(); break;</code> | Handle this switch case `7`. Call `parcels.displayWaiting` with the shown arguments. The call performs its named operation within parcelMenu. Then leave the switch to prevent fall-through. |
| 99 | <code>        case 8: {</code> | Handle this switch case `8`. Begin its branch. |
| 100 | <code>            const auto id = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 101 | <code>            const int state = choice(&quot;1. Missing\n2. On hold / recovered\n3. Cancel parcel\n0. Back\nStatus: &quot;, 0, 3);</code> | Create local `state` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 102 | <code>            if (state) {</code> | Test `state`. Run the following guarded block only when true. |
| 103 | <code>                ParcelStatus status = state == 1 ? ParcelStatus::Missing</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 104 | <code>                    : state == 2 ? ParcelStatus::OnHold : ParcelStatus::Cancelled;</code> | Continue the conditional expression: choose this value when its corresponding condition is true/false. |
| 105 | <code>                showResult(parcels.updateStatus(id, status, services));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 106 | <code>                cout &lt;&lt; &quot;For an active request, use Task 2 interruption/cancellation first.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 107 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 108 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 109 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 110 | <code>        case 9: {</code> | Handle this switch case `9`. Begin its branch. |
| 111 | <code>            const string id = readText(&quot;Parcel ID to resume: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 112 | <code>            int route = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n4. Return to sender\n0. Cancel\nRoute: &quot;, 0, 4);</code> | Create local `route` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 113 | <code>            int priority = route ? choice(&quot;1. Urgent\n2. Normal\n0. Cancel\nPriority: &quot;, 0, 2) : 0;</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 114 | <code>            if (route &amp;&amp; priority) showResult(parcels.resumeParcel(id, static_cast&lt;Route&gt;(route - 1), services,</code> | Begin a multiline guard with `route && priority) showResult(parcels.resumeParcel(id, static_cast<Route>(route - 1), services,`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 115 | <code>                priority == 1 ? RequestPriority::Urgent : RequestPriority::Normal));</code> | Call `the indicated helper` with the shown arguments. The call performs its named operation within parcelMenu. |
| 116 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 117 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 118 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 119 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 120 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 121 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 122 | <code>void serviceMenu(ServiceModule&amp; services, ResourceModule&amp; resources) {</code> | Define `serviceMenu`. Repeat Task 2 choices for request creation, recommendation, processing, verified completion, cancellation and interruption. |
| 123 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 124 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 125 | <code>            &quot;\nTASK 2 - SERVICE REQUESTS\n1. Create request\n2. Display active requests\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 126 | <code>            &quot;3. View next request\n4. Process request\n5. Complete / return request\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 127 | <code>            &quot;6. Cancel request\n7. Remove terminal request\n8. Search request\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 128 | <code>            &quot;9. Interrupt request: missing / hold\n0. Back\nChoice: &quot;, 0, 9);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 129 | <code>        if (action == 0) return;</code> | Test `action == 0`. Return immediately from this void function; no further statements in it execute. |
| 130 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 131 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 132 | <code>            ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 133 | <code>            request.parcelId = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 134 | <code>            request.recipientId = readText(&quot;Recipient ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 135 | <code>            request.serviceDetails = readText(&quot;Service details: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 136 | <code>            const int type = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n&quot;</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 137 | <code>                                    &quot;4. Redelivery\n5. Return to sender\n0. Cancel\nService: &quot;, 0, 5);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 138 | <code>            if (!type) break;</code> | Test `!type`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 139 | <code>            request.type = static_cast&lt;ServiceType&gt;(type - 1);</code> | Set `request.type` to `static_cast<ServiceType>(type - 1)`. |
| 140 | <code>            const int priority = choice(&quot;1. Urgent\n2. Normal\n0. Cancel\nPriority: &quot;, 0, 2);</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 141 | <code>            if (!priority) break;</code> | Test `!priority`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 142 | <code>            request.priority = priority == 1 ? RequestPriority::Urgent : RequestPriority::Normal;</code> | Set `request.priority` to `priority == 1 ? RequestPriority::Urgent : RequestPriority::Normal`. |
| 143 | <code>            showResult(services.createRequest(request));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 144 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 145 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 146 | <code>        case 2: services.displayActiveRequests(); break;</code> | Handle this switch case `2`. Call `services.displayActiveRequests` with the shown arguments. The call performs its named operation within serviceMenu. Then leave the switch to prevent fall-through. |
| 147 | <code>        case 3:</code> | Handle this switch case `3`. Begin its branch. |
| 148 | <code>            if (const auto* request = services.nextRequest())</code> | Begin a multiline guard with `const auto* request = services.nextRequest())`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 149 | <code>                cout &lt;&lt; &quot;Next request: &quot; &lt;&lt; request-&gt;id &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 150 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 151 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 152 | <code>            const auto id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 153 | <code>            if (cin) showResult(services.processRequest(id));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 154 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 155 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 156 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 157 | <code>            const auto id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 158 | <code>            const int outcome = choice(&quot;1. Completed\n2. Returned\n0. Cancel\nOutcome: &quot;, 0, 2);</code> | Create local `outcome` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 159 | <code>            if (!outcome) break;</code> | Test `!outcome`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 160 | <code>            const auto details = readText(&quot;Completion / return details: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 161 | <code>            const string recipientId = readText(&quot;Verify recipient ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 162 | <code>            if (cin) showResult(services.completeRequest(id, outcome == 1 ? RequestStatus::Completed : RequestStatus::Returned,</code> | Begin a multiline guard with `cin) showResult(services.completeRequest(id, outcome == 1 ? RequestStatus::Completed : RequestStatus::Returned,`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 163 | <code>                                                        details, recipientId, resources));</code> | Call `the indicated helper` with the shown arguments. The call performs its named operation within serviceMenu. |
| 164 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 165 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 166 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 167 | <code>            const auto id = readText(&quot;Request ID to cancel: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 168 | <code>            if (cin) showResult(services.cancelRequest(id, resources));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 169 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 170 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 171 | <code>        case 7: {</code> | Handle this switch case `7`. Begin its branch. |
| 172 | <code>            const auto id = readText(&quot;Terminal request ID to remove: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 173 | <code>            if (cin) showResult(services.removeTerminalRequest(id));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 174 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 175 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 176 | <code>        case 8: {</code> | Handle this switch case `8`. Begin its branch. |
| 177 | <code>            const auto id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 178 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 179 | <code>                if (const auto* request = services.findRequest(id))</code> | Begin a multiline guard with `const auto* request = services.findRequest(id))`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 180 | <code>                    printRequest(*request);</code> | Call `printRequest` with the shown arguments. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 181 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 182 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 183 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 184 | <code>        case 9: {</code> | Handle this switch case `9`. Begin its branch. |
| 185 | <code>            const string id = readText(&quot;Request ID to interrupt: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 186 | <code>            int status = choice(&quot;1. Missing\n2. Investigation hold\n0. Back\nParcel status: &quot;, 0, 2);</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 187 | <code>            if (status) showResult(services.interruptRequest(id,</code> | Begin a multiline guard with `status) showResult(services.interruptRequest(id,`. The following boolean lines finish the same condition; no mutation happens until its validation succeeds. |
| 188 | <code>                status == 1 ? ParcelStatus::Missing : ParcelStatus::OnHold, resources));</code> | Call `the indicated helper` with the shown arguments. The call performs its named operation within serviceMenu. |
| 189 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 190 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 191 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 192 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 193 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 194 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 195 | <code>void resourceMenu(ResourceModule&amp; resources) {</code> | Define `resourceMenu`. Repeat Task 3 choices for registration, availability, compatible allocation, release and updates. |
| 196 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 197 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 198 | <code>            &quot;\nTASK 3 - RESOURCES\n1. Register resource\n2. Display availability\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 199 | <code>            &quot;3. Assign request\n4. Release resource\n5. Update resource status\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 200 | <code>            &quot;6. Update resource name\n0. Back\nChoice: &quot;, 0, 6);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 201 | <code>        if (action == 0) return;</code> | Test `action == 0`. Return immediately from this void function; no further statements in it execute. |
| 202 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 203 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 204 | <code>            Resource resource;</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 205 | <code>            resource.id = readText(&quot;Unique resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 206 | <code>            resource.name = readText(&quot;Counter / personnel name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 207 | <code>            const int type = choice(&quot;1. Collection counter\n2. Delivery personnel\n0. Cancel\nType: &quot;, 0, 2);</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 208 | <code>            if (!type) break;</code> | Test `!type`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 209 | <code>            resource.type = static_cast&lt;ResourceType&gt;(type - 1);</code> | Set `resource.type` to `static_cast<ResourceType>(type - 1)`. |
| 210 | <code>            showResult(resources.registerResource(resource));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 211 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 212 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 213 | <code>        case 2: resources.displayAvailability(); break;</code> | Handle this switch case `2`. Call `resources.displayAvailability` with the shown arguments. The call performs its named operation within resourceMenu. Then leave the switch to prevent fall-through. |
| 214 | <code>        case 3: {</code> | Handle this switch case `3`. Begin its branch. |
| 215 | <code>            const auto id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 216 | <code>            const int type = choice(&quot;1. Collection counter\n2. Delivery personnel\n0. Cancel\nRequired type: &quot;, 0, 2);</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 217 | <code>            if (type) showResult(resources.assignRequest(id, static_cast&lt;ResourceType&gt;(type - 1)));</code> | Test `type`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 218 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 219 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 220 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 221 | <code>            const auto id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 222 | <code>            if (cin) showResult(resources.releaseResource(id));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 223 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 224 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 225 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 226 | <code>            const auto id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 227 | <code>            const int status = choice(&quot;1. Available\n2. Occupied\n3. Unavailable\n0. Cancel\nStatus: &quot;, 0, 3);</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 228 | <code>            if (status) showResult(resources.updateStatus(id, static_cast&lt;ResourceStatus&gt;(status - 1)));</code> | Test `status`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 229 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 230 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 231 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 232 | <code>            const auto id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 233 | <code>            const auto name = readText(&quot;New name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 234 | <code>            if (cin) showResult(resources.updateResourceDetails(id, name));</code> | Test `cin`. Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 235 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 236 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 237 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 238 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 239 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 240 | <code>} // namespace</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 241 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 242 | <code>int runSystem() {</code> | Define `runSystem`. Construct the single shared set of modules in dependency order, dispatch the main menu, and destroy them in reverse order on exit. |
| 243 | <code>    campus::ParcelModule parcels;</code> | Create local `parcels` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 244 | <code>    campus::ServiceModule services(parcels);</code> | Construct the one service module with a reference to the already-created parcel module. |
| 245 | <code>    campus::ResourceModule resources(services);</code> | Construct the one resource module with a reference to the already-created service module. |
| 246 | <code>    cout &lt;&lt; &quot;SMART CAMPUS PARCEL COLLECTION AND DELIVERY SYSTEM\n&quot;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 247 | <code>                 &quot;Three-task integrated prototype (in-memory data).\n&quot;;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 248 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 249 | <code>        const int action = choice(&quot;\n1. Task 1 - Parcel intake\n2. Task 2 - Services\n&quot;</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 250 | <code>                                  &quot;3. Task 3 - Resources\n0. Exit\nChoice: &quot;, 0, 3);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 251 | <code>        if (action == 0) break;</code> | Test `action == 0`. Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 252 | <code>        if (action == 1) parcelMenu(parcels, services);</code> | Test `action == 1`. Call `parcelMenu` with the shown arguments. Repeat Task 1 choices and collect inputs for registration, routing, editing, status, removal and recovery. |
| 253 | <code>        if (action == 2) serviceMenu(services, resources);</code> | Test `action == 2`. Call `serviceMenu` with the shown arguments. Repeat Task 2 choices for request creation, recommendation, processing, verified completion, cancellation and interruption. |
| 254 | <code>        if (action == 3) resourceMenu(resources);</code> | Test `action == 3`. Call `resourceMenu` with the shown arguments. Repeat Task 3 choices for registration, availability, compatible allocation, release and updates. |
| 255 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 256 | <code>    cout &lt;&lt; &quot;Goodbye.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 257 | <code>    return 0;</code> | Return normal exit/back/EOF value for this function. |
| 258 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 259 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 260 | <code>int main() {</code> | Define `main`. Program entry point; execute the system/test suite and translate exceptions into an error message and nonzero exit code. |
| 261 | <code>    try {</code> | Begin an exception-protected operation whose failures are handled by the following catch. |
| 262 | <code>        return runSystem();</code> | Return the value of `runSystem()` to the caller. This ends the function once its full return expression is evaluated. |
| 263 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 264 | <code>    catch (const exception&amp; error) {</code> | Handle the selected exception; perform rollback or restore captured output before reporting the failure. |
| 265 | <code>        cerr &lt;&lt; &quot;System stopped: &quot; &lt;&lt; error.what() &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue the error message to standard error. |
| 266 | <code>        return 1;</code> | Return a nonzero failure exit code. |
| 267 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 268 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
