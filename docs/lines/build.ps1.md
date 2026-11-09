# build.ps1 - every line explained

Source: [build.ps1](../../build.ps1)

Physical lines: 21; SHA-256 (LF text): `f13b7ec4da0a4319cf0f19f68b2bd468de09cb5744145e237d8fc7ae6a5e0d9f`.

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>param([switch]$Test)</code> | Accept the optional -Test switch; omit it to build only the application. |
| 2 | <code>$ErrorActionPreference = &quot;Stop&quot;</code> | Stop on PowerShell command errors rather than continuing with an incomplete build. |
| 3 | <code>Push-Location $PSScriptRoot</code> | Temporarily enter the script directory so paths work regardless of the caller directory. |
| 4 | <code>try {</code> | Protect the working-directory change with a finally block. |
| 5 | <code>    New-Item -ItemType Directory -Force build &#124; Out-Null</code> | Create the build directory if needed; suppress directory-object output. |
| 6 | <code>    $compileFlags = @(&quot;-std=c++17&quot;, &quot;-Wall&quot;, &quot;-Wextra&quot;, &quot;-Wpedantic&quot;, &quot;-Werror&quot;, &quot;-I&quot;, &quot;include&quot;)</code> | Store the shared C++17, warning-as-error and header-search compiler arguments. |
| 7 | <code>    $moduleSources = @(&quot;src/task1.cpp&quot;, &quot;src/task2.cpp&quot;, &quot;src/task3.cpp&quot;)</code> | Store the three shared implementation paths for both executable builds. |
| 8 | <code>    &amp; g++ @compileFlags src/main.cpp @moduleSources -o build/parcel_system.exe</code> | Invoke GCC for the application, splatting the argument arrays without constructing a shell command string. |
| 9 | <code>    if ($LASTEXITCODE -ne 0) { throw &quot;Application build failed&quot; }</code> | Reject nonzero application compiler exit codes immediately. |
| 10 | <code>    if ($Test) {</code> | Run the following builds/checks only when -Test was supplied. |
| 11 | <code>        &amp; g++ @compileFlags tests/system_tests.cpp @moduleSources -o build/system_tests.exe</code> | Build the C++ regression runner with the same modules and warning settings. |
| 12 | <code>        if ($LASTEXITCODE -ne 0) { throw &quot;Test build failed&quot; }</code> | Reject a failed test compile before attempting to run an old test executable. |
| 13 | <code>        &amp; ./build/system_tests.exe</code> | Execute all C++ state/structure regressions. |
| 14 | <code>        if ($LASTEXITCODE -ne 0) { throw &quot;System tests failed&quot; }</code> | Propagate any C++ test failure as a failed build/test script. |
| 15 | <code>        &amp; python tests/test_console.py build/parcel_system.exe</code> | Execute the subprocess console tests against the freshly built application. |
| 16 | <code>        if ($LASTEXITCODE -ne 0) { throw &quot;Console tests failed&quot; }</code> | Propagate any console-test failure. |
| 17 | <code>    }</code> | End the current conditional/try/finally block. |
| 18 | <code>}</code> | End the current conditional/try/finally block. |
| 19 | <code>finally {</code> | Run cleanup regardless of success, compiler failure or test failure. |
| 20 | <code>    Pop-Location</code> | Restore the original caller directory. |
| 21 | <code>}</code> | End the current conditional/try/finally block. |
