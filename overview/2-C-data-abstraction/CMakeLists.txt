cmake_minimum_required(VERSION 3.15)
project(C-data-abstraction)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(C-data-abstraction
        main.cpp
        stack.cpp)
