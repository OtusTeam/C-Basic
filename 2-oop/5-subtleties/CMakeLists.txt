cmake_minimum_required(VERSION 3.5)

project(10.details)

add_executable(explicit explicit.cpp)
set_target_properties(explicit PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(convertion convertion.cpp)
set_target_properties(convertion PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(complex_value complex_value.cpp)
set_target_properties(complex_value PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(complex_value_copy complex_value_copy.cpp)
set_target_properties(complex_value_copy PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(destructors destructors.cpp)
set_target_properties(destructors PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(virtual_destructor virtual_destructor.cpp)
set_target_properties(virtual_destructor PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(move move.cpp)
set_target_properties(move PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
