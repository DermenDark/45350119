cmake_minimum_required(VERSION 3.10)
project(MyDynamicLibrary)

set(CMAKE_CXX_STANDARD 11)

add_library(mylib SHARED mylib/mylib.cpp)
add_executable(main main.cpp)
target_link_libraries(main mylib)