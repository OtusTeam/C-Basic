cmake_minimum_required(VERSION 3.12)

project(SumLibrary VERSION 0.0.3)

configure_file(
        config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h
)

add_library(sumLib STATIC sumLib.cpp sumLib.h)

target_compile_features(sumLib PUBLIC cxx_std_17)
set_target_properties(sumLib PROPERTIES CXX_STANDARD_REQUIRED ON)

target_include_directories(
        sumLib
        PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

# ##############################################################################

# Installs the lib.
# You can use "cmake .. -DCMAKE_INSTALL_PREFIX=/path/where/to/install" when generating
# and "cmake --build . --target install" when building.
install(TARGETS sumLib EXPORT sumLibTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)
install(FILES sumLib.h DESTINATION include)

install(EXPORT sumLibTargets
        FILE sumLibConfig.cmake
        NAMESPACE SumLib::
        DESTINATION lib/cmake/SumLib
)

# "cmake --build . --target package" when packaging.
set(CPACK_GENERATOR ZIP)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
include(CPack)

# ##############################################################################
#
if(MSVC)
        target_compile_options(sumLib PUBLIC /W4 /WX)
else()
        target_compile_options(sumLib PUBLIC -Wall -Wextra -Werror -pedantic)
endif()