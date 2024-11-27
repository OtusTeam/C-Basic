cmake_minimum_required(VERSION 3.5)

project(12.unittests)

add_executable(bad_example bad_example.cpp)
set_target_properties(bad_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_executable(better_example better_example.cpp)
set_target_properties(better_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

add_subdirectory(much_better)