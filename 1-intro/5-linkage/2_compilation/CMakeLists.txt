cmake_minimum_required(VERSION 3.12)

project(compilation)

add_executable(
	compilation
	compilation.cpp
	compilation.h
)
set_target_properties(compilation PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
if (MSVC)
	# Do the preprocessing only and exit
	# Warning - linkage will fail!
#	target_compile_options(compilation PRIVATE
#		/P
#	)

	# /FA Assembly code; .asm
	# /FAc Machine and assembly code; .cod
	# /FAs Source and assembly code; .asm
	# /FAcs Machine, source, and assembly code; .cod
#	target_compile_options(compilation PRIVATE
#		/FAcs
#	)
endif()
