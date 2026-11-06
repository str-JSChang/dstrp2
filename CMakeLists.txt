cmake_minimum_required(VERSION 3.16)
project(CampusParcelSystem LANGUAGES CXX)

add_executable(parcel_system
    src/main.cpp
    src/task1.cpp
    src/task2.cpp
    src/task3.cpp
)
target_include_directories(parcel_system PRIVATE include)
target_compile_features(parcel_system PRIVATE cxx_std_17)
set_target_properties(parcel_system PROPERTIES CXX_EXTENSIONS OFF)
if(MSVC)
    target_compile_options(parcel_system PRIVATE /W4)
else()
    target_compile_options(parcel_system PRIVATE -Wall -Wextra -Wpedantic)
endif()
