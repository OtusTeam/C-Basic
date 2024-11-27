cmake_minimum_required(VERSION 3.5)

project(static_library)

add_library(sumLib STATIC 
	sum.h
	sum.cpp
)