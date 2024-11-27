cmake_minimum_required(VERSION 3.5)

project(lecture_11_templates)

add_executable(lec_11_01_func_max                 lec_11_01_func_max.cpp)
add_executable(lec_11_02_func_max_float           lec_11_02_func_max_float.cpp)
add_executable(lec_11_03_func_max_template        lec_11_03_func_max_template.cpp)
add_executable(lec_11_04_func_max_specialization  lec_11_04_func_max_specialization.cpp)
add_executable(lec_11_05_func_type_greater        lec_11_05_func_max_type_greater.cpp)
add_executable(lec_11_06_func_factorial           lec_11_06_func_factorial.cpp)
add_executable(lec_11_07_func_several_args        lec_11_07_func_several_args.cpp)
add_executable(lec_11_08_func_generate            lec_11_08_func_generate.cpp)
add_executable(lec_11_09_func_cpp_impl            lec_11_09_func_cpp_impl.cpp lec_11_09_12_func_cpp_source.cpp)
add_executable(lec_11_10_class_template           lec_11_10_class_template.cpp)
add_executable(lec_11_11_class_template_inherit   lec_11_11_class_template_inherit.cpp)
add_executable(lec_11_12_class_template_specialization       lec_11_12_class_template_specialization.cpp)
add_executable(lec_11_13_class_full_template_specialization  lec_11_13_class_full_template_specialization.cpp)
add_executable(lec_11_14_class_template_method               lec_11_14_class_template_method.cpp)
add_executable(lec_11_15_class_non_template_template lec_11_15_class_non_type_template.cpp)
add_executable(lec_11_16_partial_specialization lec_11_16_partial_specialization.cpp)


set_target_properties(
        lec_11_01_func_max 
        lec_11_02_func_max_float
        lec_11_03_func_max_template
        lec_11_04_func_max_specialization
        lec_11_05_func_type_greater
        lec_11_06_func_factorial
        lec_11_07_func_several_args
        lec_11_08_func_generate
        lec_11_09_func_cpp_impl
        lec_11_10_class_template
        lec_11_11_class_template_inherit
        lec_11_12_class_template_specialization
        lec_11_13_class_full_template_specialization
        lec_11_14_class_template_method
        lec_11_15_class_non_template_template
        lec_11_16_partial_specialization
    PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED ON
)
