cmake_minimum_required(VERSION 3.5)

project(solution)

find_package(Threads)
add_executable(solution 
    main.cpp
    my_class.cpp
    my_class.h
)
set_target_properties(solution PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        solution
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
