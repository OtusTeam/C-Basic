cmake_minimum_required(VERSION 3.15)

project(20.move_n_noexcept)

add_executable(rvo rvo.cpp)
add_executable(move move.cpp)
add_executable(universal_references universal_references.cpp)
add_executable(exceptions exceptions.cpp)
add_executable(noexcept noexcept.cpp)

set_target_properties(
  noexcept rvo move universal_references exceptions
  PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
