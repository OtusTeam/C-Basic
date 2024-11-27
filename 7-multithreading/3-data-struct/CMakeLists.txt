cmake_minimum_required(VERSION 3.15)

project(thread_struct CXX)

find_package(Threads REQUIRED)

file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(src_file ${SRC_FILES})
        get_filename_component(target ${src_file} NAME_WLE)
        add_executable(${target} ${src_file})
        list(APPEND TARGETS ${target})
endforeach(src_file ${SRC_FILES})

foreach(target ${TARGETS})
        set_target_properties(${target} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)

        if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
           CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
           CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
                target_compile_options(${target}
                        PRIVATE -g -Wall -Wextra -Werror -pedantic
                )
                target_link_libraries(${target} Threads::Threads)
        elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
                target_compile_options(${target}
                        PRIVATE /EHsc /W4 /WX)
        endif()
endforeach()
