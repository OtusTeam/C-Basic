cmake_minimum_required(VERSION 3.12)

project(Library VERSION 0.0.2)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_library(lib STATIC lib.cpp lib.h)

target_compile_features(lib PUBLIC cxx_std_17)
set_target_properties(lib PROPERTIES CXX_STANDARD_REQUIRED ON)

target_include_directories(
        lib
        PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE
        private/
)

if(MSVC)
        target_compile_options(lib PUBLIC /W4 /WX)
else()
        target_compile_options(lib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
