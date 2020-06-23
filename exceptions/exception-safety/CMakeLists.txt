cmake_minimum_required(VERSION 3.15)
project(exception-safety)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 14)

add_executable(exception-safety
        main.cpp
        throw_exception.cpp)
