cmake_minimum_required(VERSION 3.5)

project(08.Classes)

add_executable(01_class 01_class.cpp)
set_target_properties(01_class PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(02_methods 02_methods.cpp)
set_target_properties(02_methods PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(03_constructor 03_constructor.cpp)
set_target_properties(03_constructor PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(04_destructor 04_destructor.cpp)
set_target_properties(04_destructor PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(05_static 05_static.cpp)
set_target_properties(05_static PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
