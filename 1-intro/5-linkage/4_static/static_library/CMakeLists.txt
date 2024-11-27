cmake_minimum_required(VERSION 3.12)

project(datetime)

add_library(
	datetime
	STATIC
	datetime.cpp
	datetime.h
)
