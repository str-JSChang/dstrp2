# src/main.cpp - every line explained

Source: [src/main.cpp](../../src/main.cpp)

Physical lines: 398; SHA-256 (LF text): `94c1d4bd730a77c63da296c84e054885b6a1e2f62beaf6566c9a5f3f7ca78e5c`.

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
| 14 | <code>    if (!cin) {</code> | Test `!cin`. Run the following guarded block only when true. |
| 15 | <code>        return &quot;&quot;;</code> | Return the value of `""` to the caller. This ends the function once its full return expression is evaluated. |
| 16 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 17 | <code>    cout &lt;&lt; prompt;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 18 | <code>    string text;</code> | Create local `text` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 19 | <code>    getline(cin, text);</code> | Call `getline` with the shown arguments. The call performs its named operation within readText. |
| 20 | <code>    return trim(text);</code> | Return the value of `trim(text)` to the caller. This ends the function once its full return expression is evaluated. |
| 21 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 22 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 23 | <code>// EOF exits menus cleanly; malformed or out-of-range input is retried.</code> | Comment explaining intent: EOF exits menus cleanly; malformed or out-of-range input is retried. |
| 24 | <code>int choice(const char* prompt, int low, int high) {</code> | Define `choice`. Read an integer from a complete line; reject extra characters, overflow and out-of-range values; return zero on EOF. |
| 25 | <code>    while (true) {</code> | Repeat input until a valid choice returns, EOF exits, or a guard continues to retry. |
| 26 | <code>        const string line = readText(prompt);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 27 | <code>        if (!cin) {</code> | Test `!cin`. Run the following guarded block only when true. |
| 28 | <code>            return 0;</code> | Return normal exit/back/EOF value for this function. |
| 29 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 30 | <code>        istringstream input(line);</code> | Call `input` with the shown arguments. The call performs its named operation within choice. |
| 31 | <code>        int value = 0;</code> | Create local `value` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 32 | <code>        char extra = &#x27;\0&#x27;;</code> | Create local `extra` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 33 | <code>        // check the number, extra characters and range separately</code> | Comment explaining intent: check the number, extra characters and range separately |
| 34 | <code>        if (!(input &gt;&gt; value)) {</code> | Test `!(input >> value)`. Run the following guarded block only when true. |
| 35 | <code>            cout &lt;&lt; &quot;Enter a number from &quot; &lt;&lt; low &lt;&lt; &quot; to &quot; &lt;&lt; high &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 36 | <code>            continue;</code> | Skip the rest of this iteration and continue with the next loop iteration. |
| 37 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 38 | <code>        if (input &gt;&gt; extra) {</code> | Test `input >> extra`. Run the following guarded block only when true. |
| 39 | <code>            cout &lt;&lt; &quot;Enter one number without extra characters.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 40 | <code>            continue;</code> | Skip the rest of this iteration and continue with the next loop iteration. |
| 41 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 42 | <code>        if (value &lt; low &#124;&#124; value &gt; high) {</code> | Test `value < low &#124;&#124; value > high`. Run the following guarded block only when true. |
| 43 | <code>            cout &lt;&lt; &quot;Enter a number from &quot; &lt;&lt; low &lt;&lt; &quot; to &quot; &lt;&lt; high &lt;&lt; &quot;.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 44 | <code>            continue;</code> | Skip the rest of this iteration and continue with the next loop iteration. |
| 45 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 46 | <code>        return value;</code> | Return the value of `value` to the caller. This ends the function once its full return expression is evaluated. |
| 47 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 48 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 49 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 50 | <code>// return false when staff cancel or input ends</code> | Comment explaining intent: return false when staff cancel or input ends |
| 51 | <code>bool readPriority(RequestPriority&amp; priority) {</code> | Define `readPriority`. Read the priority menu into a reference argument using explicit if/else. Return false on Cancel or EOF, and true only after assigning Urgent or Normal. |
| 52 | <code>    int selection = choice(&quot;1. Urgent\n2. Normal\n0. Cancel\nPriority: &quot;, 0, 2);</code> | Create local `selection` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 53 | <code>    if (selection == 0) {</code> | Test `selection == 0`. Run the following guarded block only when true. |
| 54 | <code>        return false;</code> | Return failure or a false predicate without claiming success. |
| 55 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 56 | <code>    if (selection == 1) {</code> | Test `selection == 1`. Run the following guarded block only when true. |
| 57 | <code>        priority = RequestPriority::Urgent;</code> | Set `priority` to `RequestPriority::Urgent`. |
| 58 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 59 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 60 | <code>        priority = RequestPriority::Normal;</code> | Set `priority` to `RequestPriority::Normal`. |
| 61 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 62 | <code>    return true;</code> | Return success or a true predicate to the caller. |
| 63 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 64 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 65 | <code>Parcel readParcelDetails() {</code> | Continue the preceding declaration, condition or call with these parameters/arguments; the surrounding lines establish the operation. |
| 66 | <code>    Parcel parcel;</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 67 | <code>    parcel.recipientName = readText(&quot;Recipient name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 68 | <code>    parcel.recipientId = readText(&quot;Recipient student/staff ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 69 | <code>    parcel.recipientContact = readText(&quot;Recipient contact: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 70 | <code>    parcel.deliveryCompany = readText(&quot;Delivery company: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 71 | <code>    parcel.trackingNumber = readText(&quot;Tracking number: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 72 | <code>    parcel.destination = readText(&quot;Campus destination: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 73 | <code>    parcel.parcelType = readText(&quot;Parcel type: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 74 | <code>    return parcel;</code> | Return the value of `parcel` to the caller. This ends the function once its full return expression is evaluated. |
| 75 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 76 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 77 | <code>void showResult(bool success) {</code> | Define `showResult`. Display success only when the called operation returned true; otherwise point to its failure message. |
| 78 | <code>    if (success) {</code> | Test `success`. Run the following guarded block only when true. |
| 79 | <code>        cout &lt;&lt; &quot;Operation successful.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 80 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 81 | <code>    else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 82 | <code>        cout &lt;&lt; &quot;Operation failed; see the reason above.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 83 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 84 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 85 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 86 | <code>void parcelMenu(ParcelModule&amp; parcels, ServiceModule&amp; services) {</code> | Define `parcelMenu`. Repeat Task 1 choices and collect inputs for registration, routing, editing, status, removal and recovery. |
| 87 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 88 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 89 | <code>            &quot;\nTASK 1 - PARCEL INTAKE\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 90 | <code>            &quot;1. Register parcel\n2. Display parcels\n3. Search parcel\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 91 | <code>            &quot;4. Process next waiting parcel\n5. Update parcel details\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 92 | <code>            &quot;6. Remove cancelled parcel\n7. Display waiting queue\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 93 | <code>            &quot;8. Report missing / place on hold\n9. Resume held/recovered parcel\n0. Back\nChoice: &quot;, 0, 9);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 94 | <code>        if (action == 0) {</code> | Test `action == 0`. Run the following guarded block only when true. |
| 95 | <code>            return;</code> | Return immediately from this void function; no further statements in it execute. |
| 96 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 97 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 98 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 99 | <code>            const Parcel parcel = readParcelDetails();</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 100 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 101 | <code>                showResult(parcels.registerParcel(parcel));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 102 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 103 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 104 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 105 | <code>        case 2:</code> | Handle this switch case `2`. Begin its branch. |
| 106 | <code>            parcels.displayParcels();</code> | Call `parcels.displayParcels` with the shown arguments. The call performs its named operation within parcelMenu. |
| 107 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 108 | <code>        case 3: {</code> | Handle this switch case `3`. Begin its branch. |
| 109 | <code>            const string id = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 110 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 111 | <code>                const Parcel* parcel = parcels.findParcel(id);</code> | Create local `parcel` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 112 | <code>                if (parcel != nullptr) {</code> | Test `parcel != nullptr`. Run the following guarded block only when true. |
| 113 | <code>                    printParcel(*parcel);</code> | Call `printParcel` with the shown arguments. Print all parcel details and current status on a pipe-separated console row. |
| 114 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 115 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 116 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 117 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 118 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 119 | <code>            const int route = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n&quot;</code> | Create local `route` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 120 | <code>                                     &quot;4. Return to sender\n5. Investigation hold\n0. Cancel\nRoute: &quot;, 0, 5);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 121 | <code>            if (route == 0) {</code> | Test `route == 0`. Run the following guarded block only when true. |
| 122 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 123 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 124 | <code>            RequestPriority priority = RequestPriority::Normal;</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 125 | <code>            if (route != 5) {</code> | Test `route != 5`. Run the following guarded block only when true. |
| 126 | <code>                if (!readPriority(priority)) {</code> | Test `!readPriority(priority)`. Run the following guarded block only when true. |
| 127 | <code>                    break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 128 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 129 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 130 | <code>            Route selectedRoute = static_cast&lt;Route&gt;(route - 1);</code> | Create local `selectedRoute` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 131 | <code>            bool success = parcels.processNext(selectedRoute, services, priority);</code> | Create local `success` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 132 | <code>            showResult(success);</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 133 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 134 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 135 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 136 | <code>            const string id = readText(&quot;Parcel ID to update: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 137 | <code>            Parcel replacement = readParcelDetails();</code> | Create local `replacement` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 138 | <code>            replacement.id = id;</code> | Set `replacement.id` to `id`. |
| 139 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 140 | <code>                showResult(parcels.updateParcel(id, replacement, services));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 141 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 142 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 143 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 144 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 145 | <code>            const string id = readText(&quot;Cancelled parcel ID to remove: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 146 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 147 | <code>                showResult(parcels.removeParcel(id, services));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 148 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 149 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 150 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 151 | <code>        case 7:</code> | Handle this switch case `7`. Begin its branch. |
| 152 | <code>            parcels.displayWaiting();</code> | Call `parcels.displayWaiting` with the shown arguments. The call performs its named operation within parcelMenu. |
| 153 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 154 | <code>        case 8: {</code> | Handle this switch case `8`. Begin its branch. |
| 155 | <code>            const string id = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 156 | <code>            const int state = choice(&quot;1. Missing\n2. On hold / recovered\n3. Cancel parcel\n0. Back\nStatus: &quot;, 0, 3);</code> | Create local `state` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 157 | <code>            if (state != 0) {</code> | Test `state != 0`. Run the following guarded block only when true. |
| 158 | <code>                ParcelStatus status;</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 159 | <code>                if (state == 1) {</code> | Test `state == 1`. Run the following guarded block only when true. |
| 160 | <code>                    status = ParcelStatus::Missing;</code> | Set `status` to `ParcelStatus::Missing`. This is a lifecycle/availability change performed after the required guards. |
| 161 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 162 | <code>                else if (state == 2) {</code> | Otherwise, test `state == 2`. Run the following guarded block only when true. |
| 163 | <code>                    status = ParcelStatus::OnHold;</code> | Set `status` to `ParcelStatus::OnHold`. This is a lifecycle/availability change performed after the required guards. |
| 164 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 165 | <code>                else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 166 | <code>                    status = ParcelStatus::Cancelled;</code> | Set `status` to `ParcelStatus::Cancelled`. This is a lifecycle/availability change performed after the required guards. |
| 167 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 168 | <code>                showResult(parcels.updateStatus(id, status, services));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 169 | <code>                cout &lt;&lt; &quot;For an active request, use Task 2 interruption/cancellation first.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 170 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 171 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 172 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 173 | <code>        case 9: {</code> | Handle this switch case `9`. Begin its branch. |
| 174 | <code>            const string id = readText(&quot;Parcel ID to resume: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 175 | <code>            int route = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n4. Return to sender\n0. Cancel\nRoute: &quot;, 0, 4);</code> | Create local `route` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 176 | <code>            if (route == 0) {</code> | Test `route == 0`. Run the following guarded block only when true. |
| 177 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 178 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 179 | <code>            RequestPriority priority;</code> | Create local `priority` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 180 | <code>            if (!readPriority(priority)) {</code> | Test `!readPriority(priority)`. Run the following guarded block only when true. |
| 181 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 182 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 183 | <code>            Route selectedRoute = static_cast&lt;Route&gt;(route - 1);</code> | Create local `selectedRoute` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 184 | <code>            bool success = parcels.resumeParcel(id, selectedRoute, services, priority);</code> | Create local `success` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 185 | <code>            showResult(success);</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 186 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 187 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 188 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 189 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 190 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 191 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 192 | <code>void serviceMenu(ServiceModule&amp; services, ResourceModule&amp; resources) {</code> | Define `serviceMenu`. Repeat Task 2 choices for request creation, recommendation, processing, verified completion, cancellation and interruption. |
| 193 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 194 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 195 | <code>            &quot;\nTASK 2 - SERVICE REQUESTS\n1. Create request\n2. Display active requests\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 196 | <code>            &quot;3. View next request\n4. Process request\n5. Complete / return request\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 197 | <code>            &quot;6. Cancel request\n7. Remove terminal request\n8. Search request\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 198 | <code>            &quot;9. Interrupt request: missing / hold\n0. Back\nChoice: &quot;, 0, 9);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 199 | <code>        if (action == 0) {</code> | Test `action == 0`. Run the following guarded block only when true. |
| 200 | <code>            return;</code> | Return immediately from this void function; no further statements in it execute. |
| 201 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 202 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 203 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 204 | <code>            ServiceRequest request;</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 205 | <code>            request.parcelId = readText(&quot;Parcel ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 206 | <code>            request.recipientId = readText(&quot;Recipient ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 207 | <code>            request.serviceDetails = readText(&quot;Service details: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 208 | <code>            const int type = choice(&quot;1. Collection\n2. Campus delivery\n3. Special handling\n&quot;</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 209 | <code>                                    &quot;4. Redelivery\n5. Return to sender\n0. Cancel\nService: &quot;, 0, 5);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 210 | <code>            if (type == 0) {</code> | Test `type == 0`. Run the following guarded block only when true. |
| 211 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 212 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 213 | <code>            request.type = static_cast&lt;ServiceType&gt;(type - 1);</code> | Set `request.type` to `static_cast<ServiceType>(type - 1)`. |
| 214 | <code>            if (!readPriority(request.priority)) {</code> | Test `!readPriority(request.priority)`. Run the following guarded block only when true. |
| 215 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 216 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 217 | <code>            showResult(services.createRequest(request));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 218 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 219 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 220 | <code>        case 2:</code> | Handle this switch case `2`. Begin its branch. |
| 221 | <code>            services.displayActiveRequests();</code> | Call `services.displayActiveRequests` with the shown arguments. The call performs its named operation within serviceMenu. |
| 222 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 223 | <code>        case 3: {</code> | Handle this switch case `3`. Begin its branch. |
| 224 | <code>            const ServiceRequest* request = services.nextRequest();</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 225 | <code>            if (request != nullptr) {</code> | Test `request != nullptr`. Run the following guarded block only when true. |
| 226 | <code>                cout &lt;&lt; &quot;Next request: &quot; &lt;&lt; request-&gt;id &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 227 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 228 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 229 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 230 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 231 | <code>            const string id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 232 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 233 | <code>                showResult(services.processRequest(id));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 234 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 235 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 236 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 237 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 238 | <code>            const string id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 239 | <code>            const int outcome = choice(&quot;1. Completed\n2. Returned\n0. Cancel\nOutcome: &quot;, 0, 2);</code> | Create local `outcome` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 240 | <code>            if (outcome == 0) {</code> | Test `outcome == 0`. Run the following guarded block only when true. |
| 241 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 242 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 243 | <code>            const string details = readText(&quot;Completion / return details: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 244 | <code>            const string recipientId = readText(&quot;Verify recipient ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 245 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 246 | <code>                RequestStatus finalStatus;</code> | Create local `finalStatus` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 247 | <code>                if (outcome == 1) {</code> | Test `outcome == 1`. Run the following guarded block only when true. |
| 248 | <code>                    finalStatus = RequestStatus::Completed;</code> | Set `finalStatus` to `RequestStatus::Completed`. |
| 249 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 250 | <code>                else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 251 | <code>                    finalStatus = RequestStatus::Returned;</code> | Set `finalStatus` to `RequestStatus::Returned`. |
| 252 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 253 | <code>                bool success = services.completeRequest(id, finalStatus, details, recipientId, resources);</code> | Create local `success` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 254 | <code>                showResult(success);</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 255 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 256 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 257 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 258 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 259 | <code>            const string id = readText(&quot;Request ID to cancel: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 260 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 261 | <code>                showResult(services.cancelRequest(id, resources));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 262 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 263 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 264 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 265 | <code>        case 7: {</code> | Handle this switch case `7`. Begin its branch. |
| 266 | <code>            const string id = readText(&quot;Terminal request ID to remove: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 267 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 268 | <code>                showResult(services.removeTerminalRequest(id));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 269 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 270 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 271 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 272 | <code>        case 8: {</code> | Handle this switch case `8`. Begin its branch. |
| 273 | <code>            const string id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 274 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 275 | <code>                const ServiceRequest* request = services.findRequest(id);</code> | Create local `request` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 276 | <code>                if (request != nullptr) {</code> | Test `request != nullptr`. Run the following guarded block only when true. |
| 277 | <code>                    printRequest(*request);</code> | Call `printRequest` with the shown arguments. Print request service, priority, lifecycle, recipient, details, creation time, assignment and outcome. |
| 278 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 279 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 280 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 281 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 282 | <code>        case 9: {</code> | Handle this switch case `9`. Begin its branch. |
| 283 | <code>            const string id = readText(&quot;Request ID to interrupt: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 284 | <code>            int status = choice(&quot;1. Missing\n2. Investigation hold\n0. Back\nParcel status: &quot;, 0, 2);</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 285 | <code>            if (status != 0) {</code> | Test `status != 0`. Run the following guarded block only when true. |
| 286 | <code>                ParcelStatus parcelStatus;</code> | Create local `parcelStatus` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 287 | <code>                if (status == 1) {</code> | Test `status == 1`. Run the following guarded block only when true. |
| 288 | <code>                    parcelStatus = ParcelStatus::Missing;</code> | Set `parcelStatus` to `ParcelStatus::Missing`. |
| 289 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 290 | <code>                else {</code> | When the preceding condition is false, Begin a nested scope; its local objects are automatically destroyed when this scope ends. |
| 291 | <code>                    parcelStatus = ParcelStatus::OnHold;</code> | Set `parcelStatus` to `ParcelStatus::OnHold`. |
| 292 | <code>                }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 293 | <code>                bool success = services.interruptRequest(id, parcelStatus, resources);</code> | Create local `success` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 294 | <code>                showResult(success);</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 295 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 296 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 297 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 298 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 299 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 300 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 301 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 302 | <code>void resourceMenu(ResourceModule&amp; resources) {</code> | Define `resourceMenu`. Repeat Task 3 choices for registration, availability, compatible allocation, release and updates. |
| 303 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 304 | <code>        const int action = choice(</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 305 | <code>            &quot;\nTASK 3 - RESOURCES\n1. Register resource\n2. Display availability\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 306 | <code>            &quot;3. Assign request\n4. Release resource\n5. Update resource status\n&quot;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 307 | <code>            &quot;6. Update resource name\n0. Back\nChoice: &quot;, 0, 6);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 308 | <code>        if (action == 0) {</code> | Test `action == 0`. Run the following guarded block only when true. |
| 309 | <code>            return;</code> | Return immediately from this void function; no further statements in it execute. |
| 310 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 311 | <code>        switch (action) {</code> | Select a branch according to the enum/menu expression `(action)`. |
| 312 | <code>        case 1: {</code> | Handle this switch case `1`. Begin its branch. |
| 313 | <code>            Resource resource;</code> | Create local `resource` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 314 | <code>            resource.id = readText(&quot;Unique resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 315 | <code>            resource.name = readText(&quot;Counter / personnel name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 316 | <code>            const int type = choice(&quot;1. Collection counter\n2. Delivery personnel\n0. Cancel\nType: &quot;, 0, 2);</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 317 | <code>            if (type == 0) {</code> | Test `type == 0`. Run the following guarded block only when true. |
| 318 | <code>                break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 319 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 320 | <code>            resource.type = static_cast&lt;ResourceType&gt;(type - 1);</code> | Set `resource.type` to `static_cast<ResourceType>(type - 1)`. |
| 321 | <code>            showResult(resources.registerResource(resource));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 322 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 323 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 324 | <code>        case 2:</code> | Handle this switch case `2`. Begin its branch. |
| 325 | <code>            resources.displayAvailability();</code> | Call `resources.displayAvailability` with the shown arguments. The call performs its named operation within resourceMenu. |
| 326 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 327 | <code>        case 3: {</code> | Handle this switch case `3`. Begin its branch. |
| 328 | <code>            const string id = readText(&quot;Request ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 329 | <code>            const int type = choice(&quot;1. Collection counter\n2. Delivery personnel\n0. Cancel\nRequired type: &quot;, 0, 2);</code> | Create local `type` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 330 | <code>            if (type != 0) {</code> | Test `type != 0`. Run the following guarded block only when true. |
| 331 | <code>                showResult(resources.assignRequest(id, static_cast&lt;ResourceType&gt;(type - 1)));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 332 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 333 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 334 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 335 | <code>        case 4: {</code> | Handle this switch case `4`. Begin its branch. |
| 336 | <code>            const string id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 337 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 338 | <code>                showResult(resources.releaseResource(id));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 339 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 340 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 341 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 342 | <code>        case 5: {</code> | Handle this switch case `5`. Begin its branch. |
| 343 | <code>            const string id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 344 | <code>            const int status = choice(&quot;1. Available\n2. Occupied\n3. Unavailable\n0. Cancel\nStatus: &quot;, 0, 3);</code> | Create local `status` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 345 | <code>            if (status != 0) {</code> | Test `status != 0`. Run the following guarded block only when true. |
| 346 | <code>                showResult(resources.updateStatus(id, static_cast&lt;ResourceStatus&gt;(status - 1)));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 347 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 348 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 349 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 350 | <code>        case 6: {</code> | Handle this switch case `6`. Begin its branch. |
| 351 | <code>            const string id = readText(&quot;Resource ID: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 352 | <code>            const string name = readText(&quot;New name: &quot;);</code> | Read a complete trimmed console response into the named local variable. The prompt specifies which ID/details the operation needs. |
| 353 | <code>            if (cin) {</code> | Test `cin`. Run the following guarded block only when true. |
| 354 | <code>                showResult(resources.updateResourceDetails(id, name));</code> | Call `showResult` with the shown arguments. Display success only when the called operation returned true; otherwise point to its failure message. |
| 355 | <code>            }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 356 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 357 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 358 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 359 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 360 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 361 | <code>} // namespace</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 362 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 363 | <code>int runSystem() {</code> | Define `runSystem`. Construct the single shared set of modules in dependency order, dispatch the main menu, and destroy them in reverse order on exit. |
| 364 | <code>    campus::ParcelModule parcels;</code> | Create local `parcels` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 365 | <code>    campus::ServiceModule services(parcels);</code> | Construct the one service module with a reference to the already-created parcel module. |
| 366 | <code>    campus::ResourceModule resources(services);</code> | Construct the one resource module with a reference to the already-created service module. |
| 367 | <code>    cout &lt;&lt; &quot;SMART CAMPUS PARCEL COLLECTION AND DELIVERY SYSTEM\n&quot;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 368 | <code>                 &quot;Three-task integrated prototype (in-memory data).\n&quot;;</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 369 | <code>    while (cin) {</code> | Repeat while `(cin)` is true; the body advances pointers, drains nodes or repeats the menu. |
| 370 | <code>        const int action = choice(&quot;\n1. Task 1 - Parcel intake\n2. Task 2 - Services\n&quot;</code> | Create local `action` using the type and initializer shown. It stores the intermediate value for this operation and is destroyed on leaving scope. |
| 371 | <code>                                  &quot;3. Task 3 - Resources\n0. Exit\nChoice: &quot;, 0, 3);</code> | Continue the adjacent string literal or expected message. C++ joins adjacent literals; escaped \n characters produce line breaks. |
| 372 | <code>        if (action == 0) {</code> | Test `action == 0`. Run the following guarded block only when true. |
| 373 | <code>            break;</code> | Leave the nearest switch or loop, preventing fall-through or ending the search. |
| 374 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 375 | <code>        if (action == 1) {</code> | Test `action == 1`. Run the following guarded block only when true. |
| 376 | <code>            parcelMenu(parcels, services);</code> | Call `parcelMenu` with the shown arguments. Repeat Task 1 choices and collect inputs for registration, routing, editing, status, removal and recovery. |
| 377 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 378 | <code>        if (action == 2) {</code> | Test `action == 2`. Run the following guarded block only when true. |
| 379 | <code>            serviceMenu(services, resources);</code> | Call `serviceMenu` with the shown arguments. Repeat Task 2 choices for request creation, recommendation, processing, verified completion, cancellation and interruption. |
| 380 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 381 | <code>        if (action == 3) {</code> | Test `action == 3`. Run the following guarded block only when true. |
| 382 | <code>            resourceMenu(resources);</code> | Call `resourceMenu` with the shown arguments. Repeat Task 3 choices for registration, availability, compatible allocation, release and updates. |
| 383 | <code>        }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 384 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 385 | <code>    cout &lt;&lt; &quot;Goodbye.\n&quot;;</code> | Write/continue formatted output. << appends text/field values; \n or '\n' inserts a newline. |
| 386 | <code>    return 0;</code> | Return normal exit/back/EOF value for this function. |
| 387 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 388 | <code>(blank)</code> | Blank line separating logical parts for readability; no runtime action. |
| 389 | <code>// Start the console system and report unexpected runtime errors.</code> | Comment explaining intent: Start the console system and report unexpected runtime errors. |
| 390 | <code>int main() {</code> | Define `main`. Program entry point; execute the system/test suite and translate exceptions into an error message and nonzero exit code. |
| 391 | <code>    try {</code> | Begin an exception-protected operation whose failures are handled by the following catch. |
| 392 | <code>        return runSystem();</code> | Return the value of `runSystem()` to the caller. This ends the function once its full return expression is evaluated. |
| 393 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 394 | <code>    catch (const exception&amp; error) {</code> | Handle the selected exception; perform rollback or restore captured output before reporting the failure. |
| 395 | <code>        cerr &lt;&lt; &quot;System stopped: &quot; &lt;&lt; error.what() &lt;&lt; &#x27;\n&#x27;;</code> | Write/continue the error message to standard error. |
| 396 | <code>        return 1;</code> | Return a nonzero failure exit code. |
| 397 | <code>    }</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
| 398 | <code>}</code> | End the current block/function/namespace; braces control scope and local object lifetime. |
