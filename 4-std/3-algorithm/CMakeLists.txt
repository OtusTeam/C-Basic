cmake_minimum_required(VERSION 3.5)

project(17.STL_2)

add_executable(binary_search binary_search.cpp)
set_target_properties(binary_search PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(sort sort.cpp)
set_target_properties(sort PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(heap heap.cpp)
set_target_properties(heap PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(min_max min_max.cpp)
set_target_properties(min_max PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(copy copy.cpp)
set_target_properties(copy PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(transform transform.cpp)
set_target_properties(transform PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(remove remove.cpp)
set_target_properties(remove PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(rotate rotate.cpp)
set_target_properties(rotate PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(any_of any_of.cpp)
set_target_properties(any_of PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(accumulate accumulate.cpp)
set_target_properties(accumulate PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(permutations permutations.cpp)
set_target_properties(permutations PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )

add_executable(partition partition.cpp)
set_target_properties(partition PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        )