cmake_minimum_required(VERSION 3.5)

project(30.Idioms)

find_package(Threads)

add_subdirectory(pimpl)

add_executable(singleton singleton.cpp)
set_target_properties(singleton PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        singleton
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(virtual_ctor virtual_ctor.cpp)
set_target_properties(virtual_ctor PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )

add_executable(mixin mixin.cpp)
set_target_properties(mixin PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        mixin
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(shared_from_this shared_from_this.cpp)
set_target_properties(shared_from_this PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_link_libraries(
        shared_from_this
        PRIVATE
        ${CMAKE_THREAD_LIBS_INIT}
)