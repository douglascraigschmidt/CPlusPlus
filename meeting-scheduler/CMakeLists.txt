cmake_minimum_required(VERSION 3.15)
project(meeting_scheduler)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_VERBOSE_MAKEFILE OFF)

add_executable(meeting_scheduler
        meeting.cpp
        main.cpp)
