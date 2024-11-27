cmake_minimum_required(VERSION 3.5)

project(some_project)

add_executable(much_better include/utils.h src/main.cpp src/utils.cpp)
set_target_properties(bad_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Whether to build tests or not" ON)
if (BUILD_TESTS)
	add_executable(utils_test src/utils.cpp tests/utils_test.cpp)
	set_target_properties(utils_test PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
endif()