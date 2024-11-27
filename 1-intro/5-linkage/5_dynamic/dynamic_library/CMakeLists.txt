cmake_minimum_required(VERSION 3.12)

project(calculation)

add_library(
	calculation
	SHARED
	calculation.cpp
	calculation.h
)

set_target_properties(calculation PROPERTIES
	WINDOWS_EXPORT_ALL_SYMBOLS
	ON
)
