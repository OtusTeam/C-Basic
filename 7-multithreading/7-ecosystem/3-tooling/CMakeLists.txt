cmake_minimum_required(VERSION 3.5)

project(31.Tooling)

find_package(Threads)

add_executable(formatting formatting.cpp)
set_target_properties(formatting PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

# set(CMAKE_CXX_CLANG_TIDY clang-tidy -warnings-as-errors=*)
add_executable(tdy_example tdy_example.cpp)
set_target_properties(tdy_example PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

###############################################################################

add_executable(thread thread.cpp)
set_target_properties(thread PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(
        thread
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(thread PRIVATE
                -g
                -Wall
                -Wextra
                -Werror
                -pedantic
                # only race-condition detection:
                -fsanitize=thread # only for debug and test builds!
        )
        target_link_options(thread PRIVATE
                -fsanitize=thread
        )
endif()

###############################################################################

add_executable(deadlock deadlock.cpp)
set_target_properties(deadlock PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
target_link_libraries(
        deadlock
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(deadlock PRIVATE
                -g
                -Wall
                -Wextra
                -Werror
                -pedantic
                # only race-condition detection:
                -fsanitize=thread # only for debug and test builds!
        )
        target_link_options(deadlock PRIVATE
                -fsanitize=thread
        )
endif()

###############################################################################

add_executable(memory memory.cpp)
set_target_properties(memory PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(memory PRIVATE
                -Wall
                -Wextra
                -Werror
                -pedantic
                -fsanitize=address # only for debug and test builds!
        )
        target_link_options(memory PRIVATE
                -fsanitize=address
        )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(memory PRIVATE
                /W4
                /WX
                /fsanitize=address # only for debug and test builds!
        )
        target_link_options(memory PRIVATE
                /fsanitize=address # only for debug and test builds!
        )
endif()

###############################################################################

add_executable(ub ub.cpp)
set_target_properties(ub PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR
        CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_compile_options(ub PRIVATE
                -Wall
                -Wextra
                -Werror
                -pedantic
                -fsanitize=undefined # only for debug and test builds!
        )
        target_link_options(ub PRIVATE
                -fsanitize=undefined
        )
endif()
