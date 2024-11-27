cmake_minimum_required(VERSION 3.7.2)
project(oop)

set(CMAKE_CXX_STANDARD 17 REQUIRED)

add_executable(operators 0.operators.cpp)
add_executable(spaceflight 1.spaceflight.cpp)
add_executable(const 2.const.cpp)
add_executable(mutable 3.mutable.cpp)
add_executable(friend 4.friend.cpp)
add_executable(lifetime 5.lifetime.cpp)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(lifetime PRIVATE -fno-elide-constructors)
endif()

add_executable(inheritance.mem 6.inheritance.mem.cpp)