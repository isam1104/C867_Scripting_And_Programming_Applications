cmake_minimum_required(VERSION 3.24)
project(StudentSystem)

set(CMAKE_CXX_STANDARD 14)

include_directories(StudentSystem)

add_executable(StudentSystem
        StudentSystem/degree.h
        StudentSystem/main.cpp
        StudentSystem/roster.cpp
        StudentSystem/roster.h
        StudentSystem/student.cpp
        StudentSystem/student.h)
