cmake_minimum_required(VERSION 3.10)
project(task_2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_EXE 
Task_2.cpp
funk2/menu.cpp 
funk2/funk_menu.cpp 
funk2/funk_1.cpp
funk2/funk_2.cpp
funk2/funk_3.cpp
funk2/funk_4.cpp
funk2/funk_5.cpp
funk2/funk_6.cpp
funk2/funk_8.cpp
)

include_directories(funk2)

add_executable(task_2 ${SOURCE_EXE} )