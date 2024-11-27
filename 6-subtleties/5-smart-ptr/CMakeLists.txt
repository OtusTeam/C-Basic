cmake_minimum_required(VERSION 3.5)

project(smart_pointers)

add_executable(01_lifetime lifetime.cpp)
set_target_properties(01_lifetime PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(02_raw_pointer raw_pointer.cpp)
set_target_properties(02_raw_pointer PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(03_smart_ptr smart_ptr.cpp)
set_target_properties(03_smart_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(04_unique_ptr unique_ptr.cpp)
set_target_properties(04_unique_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(05_shared_ptr shared_ptr.cpp)
set_target_properties(05_shared_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(06_cycle_ref cycle_ref.cpp)
set_target_properties(06_cycle_ref PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(07_weak_ptr weak_ptr.cpp)
set_target_properties(07_weak_ptr PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

