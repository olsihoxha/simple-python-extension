cmake_minimum_required(VERSION 3.21)
project(test C)

set(CMAKE_C_STANDARD 99)

add_executable(test fputs.c)
find_package(PythonLibs REQUIRED)

include_directories(${PYTHON_INCLUDE_DIRS})
