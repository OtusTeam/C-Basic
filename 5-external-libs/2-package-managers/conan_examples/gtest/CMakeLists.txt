cmake_minimum_required(VERSION 3.2)

project(ProjestWithGTest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Test target
add_executable(
    test_assertions
    test/test_assertions.cpp
)
target_compile_features(test_assertions PUBLIC cxx_std_20)
target_link_libraries(test_assertions PRIVATE ${CONAN_LIBS})
target_include_directories(test_assertions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
    test_fixtures
    test/test_fixtures.cpp
)
target_compile_features(test_fixtures PUBLIC cxx_std_20)
target_link_libraries(test_fixtures PRIVATE ${CONAN_LIBS})
target_include_directories(test_fixtures PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
    test_mocks
    test/test_mocks.cpp
)
target_compile_features(test_mocks PUBLIC cxx_std_20)
target_link_libraries(test_mocks PRIVATE ${CONAN_LIBS})
target_include_directories(test_mocks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
