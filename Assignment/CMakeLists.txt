cmake_minimum_required(VERSION 3.20)
project(Assignment C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment main.c List.c List.h StudentList.c StudentList.h Student.c Student.h StudentHandler.c StudentHandler.h)
