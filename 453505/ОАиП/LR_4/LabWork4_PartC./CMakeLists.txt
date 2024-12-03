cmake_minimum_required(VERSION 3.5.0)
project(LabWork4_PartC VERSION 0.1.0 LANGUAGES C)

add_executable(LabWork4_PartC Task_4.c Task_5.c Task_6.c)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
