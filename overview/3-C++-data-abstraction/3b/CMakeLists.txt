cmake_minimum_required(VERSION 3.16)
project(3b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(3b
        main.cpp
        simple_string.cpp
        simple_string.h
        stack.cpp
        stack.h
        stack.inl)
