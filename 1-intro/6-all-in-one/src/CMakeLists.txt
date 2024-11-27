cmake_minimum_required(VERSION 3.12)

project(Game)

add_executable(game
	gamestate/gamestate.cpp
	gamestate/gamestate.h
	serialize/serialize.cpp
	serialize/serialize.h
	visualize/visualize.cpp
	visualize/visualize.h
	game.cpp
)
target_include_directories( game PRIVATE
	${CMAKE_SOURCE_DIR}/src/
)
target_include_directories( game PRIVATE
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/menu/
)
target_link_libraries( game PRIVATE
	menu
)
set_target_properties( game PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
