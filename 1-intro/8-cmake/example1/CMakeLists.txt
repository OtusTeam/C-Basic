# Early mistakes notification.
# It's not the best practice to use the latest version without needing.
cmake_minimum_required(VERSION 3.12)

# Not very useful at first sight, but, at least,
# initiates many useful CMake variables:
# https://cmake.org/cmake/help/latest/command/project.html
project(Example1)

# Creates executable and specifies from what files it has to create it.
add_executable(helloWorld main.cpp)

# CMake checks - is your C++ compiler supports this standard?
target_compile_features(helloWorld PUBLIC cxx_std_17)
set_target_properties(helloWorld PROPERTIES CXX_STANDARD_REQUIRED ON)

# Another way to specify C++ standard version for compiler is
# (but after 3.12 it's already "legacy"):
#
# set_target_properties(
# helloWorld PROPERTIES
# CXX_STANDARD 17
# CXX_STANDARD_REQUIRED ON
# )

# It's an excellent habit to enable pedantic compiler modes to ask it
# to tell you about each, even minor, problem in code.
if(MSVC)
        target_compile_options(helloWorld PUBLIC /W4 /WX)
else()
        target_compile_options(helloWorld PUBLIC -Wall -Wextra -Werror -pedantic)
endif()

# To generate build files for a specific build system, use a predefined generator.
# For ex: cmake .. -G "Visual Studio 10 2010"
# The list of generators you could get from "cmake --help" output.

add_custom_target(copyConfig
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/config.json ${CMAKE_BINARY_DIR}/config.json
)

add_dependencies(helloWorld copyConfig)
