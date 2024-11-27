cmake_minimum_required(VERSION 3.12)

project(dynamic_library)

add_subdirectory(dynamic_library)

add_executable(
	dynamic_library_usage
	dynamic_library_usage.cpp
)
set_target_properties(dynamic_library_usage PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(
	dynamic_library_usage
	PRIVATE
	${CMAKE_SOURCE_DIR}/dynamic_library
)
target_link_libraries(
	dynamic_library_usage
	PUBLIC
	calculation
)
