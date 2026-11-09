# tests/test_console.py - every line explained

Source: [tests/test_console.py](../../tests/test_console.py)

Physical lines: 61; SHA-256 (LF text): `c227d94ba76c164fab9dfb3c654f9e899cdf016041a17e19f827d26fe4a818d3`.

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>from pathlib import Path</code> | Import Path for resolving the executable path reliably. |
| 2 | <code>import subprocess</code> | Import subprocess for running the real console executable with supplied input. |
| 3 | <code>import sys</code> | Import sys to read the executable command-line argument. |
| 4 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 5 | <code>executable = str(Path(sys.argv[1]).resolve())</code> | Resolve the executable argument to an absolute path; subprocess receives it as one argument. |
| 6 | <code>checks = 0</code> | Initialize the number of completed test scenarios. |
| 7 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 8 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 9 | <code>def run_case(name, input_text, expected, rejected=()):</code> | Define a reusable scenario runner with required and forbidden output fragments. |
| 10 | <code>    global checks</code> | Allow the runner to increment the module-level scenario count. |
| 11 | <code>    result = subprocess.run([executable], input=input_text, text=True,</code> | Start the executable, feed the complete input script and request decoded text input/output. |
| 12 | <code>                            capture_output=True, timeout=5)</code> | Capture both streams and enforce a five-second timeout so a broken menu/ring cannot hang the test run. |
| 13 | <code>    if result.returncode != 0:</code> | Require a zero process exit code. |
| 14 | <code>        raise AssertionError(f&quot;{name}: exit {result.returncode}: {result.stderr}&quot;)</code> | Fail with scenario name, exit code and stderr if the application crashed or reported an exception. |
| 15 | <code>    for fragment in expected:</code> | Inspect each output fragment that this scenario expects. |
| 16 | <code>        if fragment not in result.stdout:</code> | Check that the expected fragment appears somewhere in stdout. |
| 17 | <code>            raise AssertionError(f&quot;{name}: missing {fragment!r}\n{result.stdout}&quot;)</code> | Raise a detailed failure containing the missing fragment and captured output. |
| 18 | <code>    for fragment in rejected:</code> | Inspect every forbidden output fragment. |
| 19 | <code>        if fragment in result.stdout:</code> | Check that forbidden text did not appear. |
| 20 | <code>            raise AssertionError(f&quot;{name}: unexpected {fragment!r}\n{result.stdout}&quot;)</code> | Fail when the application claims failure/stub behavior in a scenario expected to succeed. |
| 21 | <code>    checks += 1</code> | Count this scenario only after all exit and output checks pass. |
| 22 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 23 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 24 | <code>run_case(&quot;navigation&quot;, &quot;1\n0\n2\n0\n3\n0\n0\n&quot;,</code> | Exercise every top-level task menu, return from each, then exit. |
| 25 | <code>         [&quot;TASK 1&quot;, &quot;TASK 2&quot;, &quot;TASK 3&quot;, &quot;Goodbye.&quot;])</code> | Require all three headings and a normal goodbye in that navigation run. |
| 26 | <code>run_case(&quot;bad choices&quot;, &quot;\nabc\n999999999999999999999\n-1\n4\n1x\n0\n&quot;,</code> | Try blank/alphabetic/overflow/negative/out-of-range/trailing-junk menu input, then exit. |
| 27 | <code>         [&quot;Enter a number from 0 to 3.&quot;, &quot;Goodbye.&quot;])</code> | Require a useful range message and successful termination after bad input. |
| 28 | <code>run_case(&quot;EOF at main&quot;, &quot;&quot;, [&quot;Goodbye.&quot;])</code> | Send immediate end-of-input and require a clean main-menu exit. |
| 29 | <code>run_case(&quot;EOF while registering&quot;, &quot;1\n1\nAlice\n&quot;, [&quot;Goodbye.&quot;], [&quot;Registered parcel&quot;])</code> | End input halfway through registration; require exit and prohibit committing a partial parcel. |
| 30 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 31 | <code># Register and route a collection, allocate a counter, process, verify and complete.</code> | Explain the following complete collection workflow script. |
| 32 | <code>register = &quot;1\n1\nAlice\nTP001\n012345\nCourier\nTRACK1\nBlock A\nBox\n&quot;</code> | Prepare valid registration input for P1 / recipient TP001. |
| 33 | <code>route = &quot;4\n1\n2\n0\n&quot;</code> | Route the oldest parcel for normal-priority collection and return to the main menu. |
| 34 | <code>counter = &quot;3\n1\nC1\nCounter A\n1\n3\nR1\n1\n0\n&quot;</code> | Register counter C1, assign request R1 to a counter and return. |
| 35 | <code>complete = &quot;2\n4\nR1\n5\nR1\n1\nCollected by recipient\nTP001\n0\n&quot;</code> | Start R1 processing, then complete it using matching recipient TP001. |
| 36 | <code>inspect = &quot;1\n3\nP1\n0\n3\n2\n0\n0\n&quot;</code> | Search the completed parcel, display freed resources and exit. |
| 37 | <code>run_case(&quot;integrated collection&quot;, register + route + counter + complete + inspect,</code> | Run the combined real-console collection scenario. |
| 38 | <code>         [&quot;Registered parcel P1&quot;, &quot;Created request R1&quot;, &quot;Assigned resource C1&quot;,</code> | Require successful parcel registration, request creation and counter assignment messages. |
| 39 | <code>          &quot;Request is now in progress&quot;, &quot;Parcel status: Collected&quot;, &quot;C1 &#124; Counter A &#124; Counter &#124; Available&quot;],</code> | Require InProgress -> Collected and the counter returning to Available. |
| 40 | <code>         [&quot;Operation failed&quot;, &quot;Not implemented&quot;])</code> | Reject any operation-failed or unimplemented-stub output in the successful integrated scenario. |
| 41 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 42 | <code># Reach every remaining menu action, using unknown IDs for safe rejection paths.</code> | Explain that the remaining scenarios exercise menu branches with safe unknown-ID inputs. |
| 43 | <code>parcel_actions = {</code> | Begin Task 1 action-to-input scripts for remaining menu actions. |
| 44 | <code>    2: &quot;&quot;, 3: &quot;UNKNOWN\n&quot;, 4: &quot;1\n2\n&quot;,</code> | Provide inputs for display, search and empty-intake routing actions. |
| 45 | <code>    5: &quot;UNKNOWN\nAlice\nTP001\n012\nCourier\nT\nA\nBox\n&quot;,</code> | Provide all descriptive fields for an attempted update of a nonexistent parcel. |
| 46 | <code>    6: &quot;UNKNOWN\n&quot;, 7: &quot;&quot;, 8: &quot;UNKNOWN\n1\n&quot;, 9: &quot;UNKNOWN\n1\n2\n&quot;</code> | Provide removal, waiting-display, missing-status and resume inputs for Task 1. |
| 47 | <code>}</code> | Close the Task 1 input dictionary. |
| 48 | <code>service_actions = {</code> | Begin Task 2 action-to-input scripts. |
| 49 | <code>    1: &quot;UNKNOWN\nTP001\nCollect\n1\n2\n&quot;, 2: &quot;&quot;, 3: &quot;&quot;, 4: &quot;UNKNOWN\n&quot;,</code> | Provide request creation/display/recommendation/process inputs with an unknown Parcel/Request ID. |
| 50 | <code>    5: &quot;UNKNOWN\n1\nDone\nTP001\n&quot;, 6: &quot;UNKNOWN\n&quot;, 7: &quot;UNKNOWN\n&quot;,</code> | Provide completion/cancellation/removal inputs, including verification ID. |
| 51 | <code>    8: &quot;UNKNOWN\n&quot;, 9: &quot;UNKNOWN\n1\n&quot;</code> | Provide request lookup and missing-interruption inputs. |
| 52 | <code>}</code> | Close the Task 2 input dictionary. |
| 53 | <code>resource_actions = {</code> | Begin Task 3 action-to-input scripts. |
| 54 | <code>    1: &quot;C1\nCounter A\n1\n&quot;, 2: &quot;&quot;, 3: &quot;UNKNOWN\n1\n&quot;,</code> | Provide resource creation, display and unknown-request assignment inputs. |
| 55 | <code>    4: &quot;UNKNOWN\n&quot;, 5: &quot;UNKNOWN\n3\n&quot;, 6: &quot;UNKNOWN\nNew name\n&quot;</code> | Provide unknown-resource release/status/name-update inputs. |
| 56 | <code>}</code> | Close the Task 3 input dictionary. |
| 57 | <code>for menu, actions in enumerate((parcel_actions, service_actions, resource_actions), 1):</code> | Enumerate task dictionaries starting at main-menu choice 1. |
| 58 | <code>    for action, prompts in actions.items():</code> | Visit each remaining action and its expected prompt responses. |
| 59 | <code>        run_case(f&quot;menu {menu} action {action}&quot;, f&quot;{menu}\n{action}\n{prompts}0\n0\n&quot;,</code> | Build an input sequence selecting the task/action, feeding its inputs, backing out and exiting. |
| 60 | <code>                 [&quot;Goodbye.&quot;], [&quot;Not implemented&quot;])</code> | Require clean termination and reject any leftover stub output for every branch. |
| 61 | <code>print(f&quot;PASS: {checks} console scenarios.&quot;)</code> | Report the total completed console scenarios; unhandled exceptions would exit nonzero first. |
