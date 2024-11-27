cmake_minimum_required(VERSION 3.5)

project(details)

find_package(Threads)
add_executable(details 
    main.cpp
    my_class.cpp
    my_class.h
)
set_target_properties(details PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        details
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)
