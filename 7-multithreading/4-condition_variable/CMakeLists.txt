
cmake_minimum_required(VERSION 3.10)

project(condition_variable)

find_package(Threads REQUIRED)

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(src_file ${SRC_FILES})
    get_filename_component(target ${src_file} NAME_WLE)
    add_executable(${target} ${src_file})
    list(APPEND TARGETS ${target})
    message("target added: ${target}")
endforeach(src_file ${SRC_FILES})

foreach(target ${TARGETS})
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(${target} PRIVATE
                -g -Wall -Wextra -Werror -Wno-unused-parameter -pedantic
                )
        target_link_libraries(${target} PUBLIC Threads::Threads)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(${target} PRIVATE
                /EHsc /W4 /WX
                )
    endif()
    target_compile_features(${target} PUBLIC cxx_std_17)
endforeach(target)
