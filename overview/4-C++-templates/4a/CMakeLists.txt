cmake_minimum_required(VERSION 3.16)
project(4a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(4a
        main.cpp
        stack.cpp
        stack.h
        stack.inl)
