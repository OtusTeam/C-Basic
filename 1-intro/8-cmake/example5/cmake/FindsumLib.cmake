# Find module for the sumLib
# Exports
# SUMLIB_INCLUDE_DIRS - for include folder path
# SUMLIB_LIB - for lib path
# This is the directory where the sumLib is located.
# By default SUMLIBDIR environment variable value is taken.
set(SUMLIB_ROOT
    "$ENV{SUMLIBDIR}"
    CACHE PATH "sumLib root directory.")

# Look for headers.
find_path(SUMLIB_INCLUDE_DIRS
    NAMES sumLib.h
    HINTS $ENV{SUMLIBDIR}
    PATHS ${SUMLIB_ROOT}
    PATH_SUFFIXES include
)
message("Found path: SUMLIB_INCLUDE_DIRS = ${SUMLIB_INCLUDE_DIRS}")

# Not just "find path or file", it find_library - file name/path depends on OS.
find_library(SUMLIB_LIB
    NAMES sumLib
    HINTS $ENV{SUMLIBDIR}
    PATHS ${SUMLIB_ROOT}
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH
)
message("Found path: SUMLIB_LIB = ${SUMLIB_LIB}")

# Support the REQUIRED and QUIET arguments, and set SUMLIB_FOUND if found.
# https://cmake.org/cmake/help/latest/module/FindPackageHandleStandardArgs.html
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(sumLib DEFAULT_MSG
    SUMLIB_LIB
    SUMLIB_INCLUDE_DIRS)
