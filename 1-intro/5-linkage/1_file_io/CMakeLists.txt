cmake_minimum_required(VERSION 3.12)

project(file_io LANGUAGES CXX)

add_executable(
	file_io
	file_io.cpp
)

set_target_properties(file_io PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
