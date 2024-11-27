cmake_minimum_required(VERSION 3.25)

project(find_package LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS NO)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(
      -g
      -Wall
      -Wextra
      -Werror
      -pedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(
      /EHsc
      /W4
      /WX)
endif()

add_executable(${PROJECT_NAME} main.cpp)

set(nlohmann_json_DIR ${CMAKE_CURRENT_SOURCE_DIR}/json/build)
find_package(nlohmann_json REQUIRED)
target_link_libraries(${PROJECT_NAME}
  PRIVATE nlohmann_json::nlohmann_json)
