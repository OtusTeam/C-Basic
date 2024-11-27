cmake_minimum_required(VERSION 3.5)

project(Main VERSION 0.0.5)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_executable(mainLib main.cpp)

target_compile_features(mainLib PUBLIC cxx_std_17)
set_target_properties(mainLib PROPERTIES CXX_STANDARD_REQUIRED ON)

target_include_directories(
        mainLib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(mainLib lib dynamic_lib)

if(MSVC)
        target_compile_options(mainLib PUBLIC /W4 /WX)
else()
        target_compile_options(mainLib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
