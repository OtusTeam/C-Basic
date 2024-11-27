cmake_minimum_required(VERSION 3.12)

project(example8)

set(SOURCES
        main.cpp
        math.cpp
)

set(HEADERS
        math.h)

add_executable(main ${SOURCES} ${HEADERS})
target_compile_features(main PUBLIC cxx_std_11)
set_target_properties(main PROPERTIES CXX_STANDARD_REQUIRED ON)

# Separately requesting special available C++ features for compilatory.
# Full list https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(
        main
        PRIVATE
        cxx_generic_lambdas
)

if(MSVC)
        target_compile_options(main PUBLIC /W4 /WX)
else()
        target_compile_options(main PUBLIC -Wall -Wextra -Werror -pedantic)
endif()
