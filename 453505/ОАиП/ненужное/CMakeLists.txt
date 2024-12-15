cmake_minimum_required(VERSION 3.10)
project(MyDynamicLibrary)

set(CMAKE_CXX_STANDARD 11)

# Опции для включения санитайзеров
option(ENABLE_ASAN "Enable AddressSanitizer" ON)
option(ENABLE_TSAN "Enable ThreadSanitizer" OFF)

# Проверка на совместимость
if (ENABLE_ASAN AND ENABLE_TSAN)
    message(FATAL_ERROR "Cannot enable both AddressSanitizer and ThreadSanitizer at the same time.")
endif()

if (ENABLE_ASAN)
    message(STATUS "AddressSanitizer is enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
    set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -fsanitize=address")
endif()

if (ENABLE_TSAN)
    message(STATUS "ThreadSanitizer is enabled")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
    set(CMAKE_LINK_FLAGS "${CMAKE_LINK_FLAGS} -fsanitize=thread")
endif()

add_library(mylib SHARED mylib/mylib.cpp)
add_executable(main main.cpp)
target_link_libraries(main mylib)