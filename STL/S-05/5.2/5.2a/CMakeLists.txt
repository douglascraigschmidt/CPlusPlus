cmake_minimum_required(VERSION 3.15)
project(5_2a)

if (MOVE)
    add_definitions(-DMOVE=${MOVE})
else()
    add_definitions(-DMOVE=)
endif()

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(5_2a
        main.cpp
        simple_string.cpp)
