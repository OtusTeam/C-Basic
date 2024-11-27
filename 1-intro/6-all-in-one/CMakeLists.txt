cmake_minimum_required(VERSION 3.12)

project(Game)

option(WITH_TESTS "Whether to build tests" ON)

add_subdirectory(menu)
add_subdirectory(src)