cmake_minimum_required(VERSION 3.17)
project(Session6_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment3rdex main.c HealthHandler.c HealthHandler.h Room.c Room.h Humidity.c Humidity.h Temperature.c Temperature.h List.c List.h TempDriver.c TempDriver.h HumidityDriver.c HumidityDriver.h)