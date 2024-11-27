cmake_minimum_required(VERSION 3.5)

project(dynamic_library_usage)

add_subdirectory(lib)

add_executable(dynamic_library_usage
	main.cpp
)

target_link_libraries(dynamic_library_usage
	PRIVATE
	sumLib
)
target_include_directories(dynamic_library_usage
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/lib
)