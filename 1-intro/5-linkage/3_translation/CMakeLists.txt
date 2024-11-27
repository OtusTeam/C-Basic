cmake_minimum_required(VERSION 3.12)

project(translation_units)

add_executable(
	translation_units
	translation_unit1.cpp     # 2 TU
	translation_unit2.cpp     # 3 TU
	translation_unit_main.cpp # 1 TU
)
set_target_properties(translation_units PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
