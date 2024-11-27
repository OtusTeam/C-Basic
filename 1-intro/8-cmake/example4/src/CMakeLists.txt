cmake_minimum_required(VERSION 3.12)

project(Main VERSION 0.0.6)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_executable(mainSumLib main.cpp)

target_compile_features(mainSumLib PUBLIC cxx_std_17)
set_target_properties(mainSumLib PROPERTIES CXX_STANDARD_REQUIRED ON)

target_include_directories(
        mainSumLib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

# find_package here to find package (see the file in example root
# - it doesn't build library)
#-DCMAKE_PREFIX_PATH for custom prefix path
find_package(sumLib CONFIG REQUIRED)

target_link_libraries(mainSumLib SumLib::sumLib)

if(MSVC)
        target_compile_options(mainSumLib PUBLIC /W4 /WX)
else()
        target_compile_options(mainSumLib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()