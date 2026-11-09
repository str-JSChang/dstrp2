param([switch]$Test)
$ErrorActionPreference = "Stop"
Push-Location $PSScriptRoot
try {
    New-Item -ItemType Directory -Force build | Out-Null
    $compileFlags = @("-std=c++17", "-Wall", "-Wextra", "-Wpedantic", "-Werror", "-I", "include")
    $moduleSources = @("src/task1.cpp", "src/task2.cpp", "src/task3.cpp")
    & g++ @compileFlags src/main.cpp @moduleSources -o build/parcel_system.exe
    if ($LASTEXITCODE -ne 0) { throw "Application build failed" }
    if ($Test) {
        & g++ @compileFlags tests/system_tests.cpp @moduleSources -o build/system_tests.exe
        if ($LASTEXITCODE -ne 0) { throw "Test build failed" }
        & ./build/system_tests.exe
        if ($LASTEXITCODE -ne 0) { throw "System tests failed" }
        & python tests/test_console.py build/parcel_system.exe
        if ($LASTEXITCODE -ne 0) { throw "Console tests failed" }
    }
}
finally {
    Pop-Location
}
