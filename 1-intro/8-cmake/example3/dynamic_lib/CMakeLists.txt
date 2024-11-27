cmake_minimum_required(VERSION 3.12)

project(DynamicLibrary VERSION 0.0.2)

add_library(dynamic_lib SHARED dynamic_lib.cpp)

target_include_directories(dynamic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(dynamic_lib PUBLIC cxx_std_17)
set_target_properties(dynamic_lib PROPERTIES CXX_STANDARD_REQUIRED ON)

if(MSVC)
        target_compile_options(dynamic_lib PUBLIC /W4 /WX)
else()
        target_compile_options(dynamic_lib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
