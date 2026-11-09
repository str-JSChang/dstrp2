# CMakeLists.txt - every line explained

Source: [CMakeLists.txt](../../CMakeLists.txt)

Physical lines: 32; SHA-256 (LF text): `cd327e999cd17f4b0400e668239bb68b665375ef550890617dae073ffe852afc`.

| Line | Source | What it does |
| ---: | --- | --- |
| 1 | <code>cmake_minimum_required(VERSION 3.16)</code> | Require CMake 3.16 or later before interpreting the project configuration. |
| 2 | <code>project(CampusParcelSystem LANGUAGES CXX)</code> | Name the project and enable the C++ compiler toolchain. |
| 3 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 4 | <code>add_library(campus_modules src/task1.cpp src/task2.cpp src/task3.cpp)</code> | Compile the three task implementations once into the reusable campus_modules library. |
| 5 | <code>target_include_directories(campus_modules PUBLIC include)</code> | Expose include/ to the library and its consumers, so shared headers resolve. |
| 6 | <code>target_compile_features(campus_modules PUBLIC cxx_std_17)</code> | Require C++17 for the library and all targets that link it. |
| 7 | <code>set_target_properties(campus_modules PROPERTIES CXX_EXTENSIONS OFF)</code> | Disable compiler-specific language extensions for the task library. |
| 8 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 9 | <code>add_executable(parcel_system src/main.cpp)</code> | Create the interactive application using its main() entry point. |
| 10 | <code>target_link_libraries(parcel_system PRIVATE campus_modules)</code> | Link the application to the shared task implementations. |
| 11 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 12 | <code>include(CTest)</code> | Enable CTest integration and its BUILD_TESTING option. |
| 13 | <code>if(BUILD_TESTING)</code> | Configure test targets only when testing is enabled. |
| 14 | <code>    add_executable(system_tests tests/system_tests.cpp)</code> | Create the C++ regression executable using its own main(). |
| 15 | <code>    target_link_libraries(system_tests PRIVATE campus_modules)</code> | Link regressions to the same task implementations as the application. |
| 16 | <code>    add_test(NAME system_tests COMMAND system_tests)</code> | Register the C++ executable as a CTest test. |
| 17 | <code>    find_package(Python3 COMPONENTS Interpreter QUIET)</code> | Look for Python quietly; application compilation does not require Python. |
| 18 | <code>    if(Python3_FOUND)</code> | Register console subprocess tests only when a Python interpreter is available. |
| 19 | <code>        add_test(NAME console_tests COMMAND ${Python3_EXECUTABLE}</code> | Start the CTest command using the discovered Python executable. |
| 20 | <code>            ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_console.py $&lt;TARGET_FILE:parcel_system&gt;)</code> | Pass the Python test path and configuration-specific application executable path. |
| 21 | <code>    endif()</code> | Close the current CMake conditional block. |
| 22 | <code>endif()</code> | Close the current CMake conditional block. |
| 23 | <code>(blank)</code> | Blank line separating logical sections; no execution. |
| 24 | <code>foreach(target campus_modules parcel_system system_tests)</code> | Apply compiler-warning settings to each declared build target. |
| 25 | <code>    if(TARGET ${target})</code> | Skip a target that does not exist, such as disabled system_tests. |
| 26 | <code>        if(MSVC)</code> | Select Visual C++ warning options for the Microsoft compiler. |
| 27 | <code>            target_compile_options(${target} PRIVATE /W4 /WX)</code> | Enable high warning level and treat warnings as errors on MSVC. |
| 28 | <code>        else()</code> | Use the corresponding warning options for GCC/Clang-style compilers. |
| 29 | <code>            target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Werror)</code> | Enable common/extra/pedantic warnings and make all warnings build failures. |
| 30 | <code>        endif()</code> | Close the current CMake conditional block. |
| 31 | <code>    endif()</code> | Close the current CMake conditional block. |
| 32 | <code>endforeach()</code> | Finish applying warning settings to all targets. |
