cmake_minimum_required(VERSION 3.24)
project(Calendar_Management C)

set(CMAKE_C_STANDARD 99)

add_executable(Calendar_Management main.c list.c cell.c timer.c timer.h tab.c tab.h research.c research.h)
