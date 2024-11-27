cmake_minimum_required(VERSION 3.12)

project(03.Syntax)

add_executable(01_cin_cout                 01_cin_cout.cpp)
add_executable(01_cin_cout_using           01_cin_cout_using.cpp)
add_executable(01_cin_cout_namespace       01_cin_cout_namespace.cpp)
add_executable(02_type_ranges_int          02_type_ranges_int.cpp)
add_executable(03_type_ranges_float        03_type_ranges_float.cpp)
add_executable(04_arithm_operations        04_arithm_operations.cpp)
add_executable(05_bool_logic               05_bool_logic.cpp)
add_executable(06_if                       06_if.cpp)
add_executable(07_switch                   07_switch.cpp)
add_executable(08_while_do_loop            08_while_do_loop.cpp)
add_executable(09_for_loop                 09_for_loop.cpp)
add_executable(10_file_io                  10_file_io.cpp)
add_executable(10_arrays_pointers          10_arrays_pointers.cpp)
add_executable(xx_cast_int_float           xx_cast_int_float.cpp)

set_target_properties(
        01_cin_cout
        01_cin_cout_using
        01_cin_cout_namespace
        02_type_ranges_int
        03_type_ranges_float
        04_arithm_operations
        05_bool_logic
        06_if 
        07_switch
        08_while_do_loop
        09_for_loop
        10_file_io
        xx_cast_int_float
PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
