cmake_minimum_required(VERSION 3.2)

project(ProjestWithGTest)

find_package(GTest CONFIG REQUIRED)

# Test target
add_executable(
    test_assertions
    test/test_assertions.cpp
)
target_link_libraries(test_assertions PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_include_directories(test_assertions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
    test_fixtures
    test/test_fixtures.cpp
)
target_link_libraries(test_fixtures PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_include_directories(test_fixtures PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(
    test_mocks
    test/test_mocks.cpp
)
target_link_libraries(test_mocks PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
target_include_directories(test_mocks PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

if (MSVC)
    # @see https://github.com/google/googletest/blob/master/googletest/README.md
    # Visual Studio Dynamic vs Static Runtimes
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    target_compile_options(
        test_assertions PRIVATE
        /W4
    )
    target_compile_options(
        test_fixtures PRIVATE
        /W4
    )
    target_compile_options(
        test_mocks PRIVATE
        /W4
    )
else ()
    target_compile_options(
        test_assertions PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_fixtures PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(
        test_mocks PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()
