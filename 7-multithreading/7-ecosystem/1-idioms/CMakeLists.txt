cmake_minimum_required(VERSION 3.5)

project(23.Idioms)

find_package(Threads)

add_executable(scope_guard scope_guard.cpp)
set_target_properties(scope_guard PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        scope_guard
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)


add_executable(copy_and_swap copy_and_swap.cpp)
set_target_properties(copy_and_swap PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(copy_on_write copy_on_write.cpp)
set_target_properties(copy_on_write PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
