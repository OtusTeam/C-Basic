cmake_minimum_required(VERSION 3.12)

project(GameMenu)

add_library( menu
	menu.cpp
	menu.h
)

set_target_properties( menu PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

if(WITH_TESTS)
	add_subdirectory(test)
endif()