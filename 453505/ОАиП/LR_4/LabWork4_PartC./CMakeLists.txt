cmake_minimum_required(VERSION 3.5.0)
project(LabWork4_PartC VERSION 0.1.0 LANGUAGES C)

add_executable(LabWork4_PartC, Task_4.c Task_5.c Task_6.c)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)