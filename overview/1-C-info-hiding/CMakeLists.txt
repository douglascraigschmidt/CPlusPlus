cmake_minimum_required(VERSION 3.15)
project(C-info-hiding)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(C-info-hiding
        main.cpp
        stack.cpp)
