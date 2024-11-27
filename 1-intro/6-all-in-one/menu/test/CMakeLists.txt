cmake_minimum_required(VERSION 3.12)

project(GameMenuTest)

add_executable(menu_test
	menu_test.cpp
)

set_target_properties(menu_test PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_include_directories( menu_test PRIVATE
	${CMAKE_SOURCE_DIR}/menu/
)
target_link_libraries(menu_test PRIVATE
	menu
)
