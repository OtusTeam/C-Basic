cmake_minimum_required(VERSION 3.12)

project(static_library)

add_subdirectory(static_library)

add_executable(
	static_library_usage
	static_library_usage.cpp
)
set_target_properties(static_library_usage PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
target_include_directories(
	static_library_usage
	PRIVATE
	${CMAKE_SOURCE_DIR}/static_library
)
target_link_libraries(
	static_library_usage
	PRIVATE
	datetime
)
