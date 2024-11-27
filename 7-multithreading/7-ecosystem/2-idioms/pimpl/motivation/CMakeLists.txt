cmake_minimum_required(VERSION 3.5)

project(motivation)

find_package(Threads)
add_executable(motivation 
    main.cpp
    my_class.cpp
    my_class.h
)
set_target_properties(motivation PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        motivation
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
