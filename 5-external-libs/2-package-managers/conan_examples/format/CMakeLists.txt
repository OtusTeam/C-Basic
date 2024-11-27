cmake_minimum_required(VERSION 3.12)

project(conan_example)

find_package(fmt CONFIG REQUIRED)

add_executable(format format.cpp)

set_target_properties(format
		PROPERTIES CXX_STANDARD 17
		CXX_STANDARD_REQUIRED ON
		)
target_link_libraries(format
		PRIVATE
		fmt::fmt
		#fmt::fmt-header-only
		)
