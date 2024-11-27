cmake_minimum_required(VERSION 3.12)

project(Polymorphism)

add_executable(01_complex_naive 01_complex_naive.cpp)
set_target_properties(01_complex_naive PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(02_0_complex_struct 02_0_complex_struct.cpp)
set_target_properties(02_0_complex_struct PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(02_1_complex_class 02_1_complex_class.cpp)
set_target_properties(02_1_complex_class PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(complex_class_2 02_2_complex_class.cpp)
set_target_properties(complex_class_2 PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(02_3_complex_class 02_3_complex_class.cpp)
set_target_properties(02_3_complex_class PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(03_0_shapes 03_0_shapes.cpp)
set_target_properties(03_0_shapes PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(03_1_shapes_virtual 03_1_shapes_virtual.cpp)
set_target_properties(03_1_shapes_virtual PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(03_2_shapes_virtual 03_2_shapes_virtual.cpp)
set_target_properties(03_2_shapes_virtual PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(03_3_pure_virtual_call 03_3_pure_virtual_call.cpp)
set_target_properties(03_3_pure_virtual_call PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

add_executable(04_animal 04_animal.cpp)
set_target_properties(04_animal PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
