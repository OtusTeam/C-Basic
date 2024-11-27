cmake_minimum_required(VERSION 3.12)

project(14.STL)

add_executable(01_string                    01_string.cpp)
add_executable(02_string_file_extension     02_string_file_extension.cpp)
add_executable(03_string_modify             03_string_modify.cpp)
add_executable(04_file_io                   04_file_io.cpp)
add_executable(05_filesystem                05_filesystem.cpp)
add_executable(06_chrono                    06_chrono.cpp)
add_executable(07_thread                    07_thread.cpp)

set_target_properties(
    01_string
    02_string_file_extension
    03_string_modify
    04_file_io
    05_filesystem
    06_chrono
    07_thread
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
