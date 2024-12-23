cmake_minimum_required(VERSION 3.10)
project(task_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_EXE 
Task_1.cpp 
funk1/osnova.cpp 
funk1/menu.cpp 
funk1/funk_menu.cpp 
funk1/funk_1.cpp
funk1/funk_2.cpp
funk1/funk_3.cpp
funk1/funk_4.cpp
funk1/funk_5.cpp
funk1/funk_6.cpp)

include_directories(funk1)

add_executable(task_1 ${SOURCE_EXE} )