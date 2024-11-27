cmake_minimum_required(VERSION 3.12)

project(example6 VERSION 0.0.6)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_executable(mainSumExtLib main.cpp)
target_compile_features(mainSumExtLib PUBLIC cxx_std_17)
set_target_properties(mainSumExtLib PROPERTIES CXX_STANDARD_REQUIRED ON)
target_include_directories(
        mainSumExtLib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

if(MSVC)
        target_compile_options(mainSumExtLib PUBLIC /W4 /WX)
else()
        target_compile_options(mainSumExtLib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()

# We're adding a new path (our path) to the path list where CMake searches
# modules for "find_package(... MODULE ...)":
set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

# find_package here to find library by module
# (prev. example was CONFIG - "by config")
find_package(sumLib MODULE REQUIRED)

target_include_directories(mainSumExtLib PRIVATE ${SUMLIB_INCLUDE_DIRS})
target_link_libraries(mainSumExtLib ${SUMLIB_LIB})
