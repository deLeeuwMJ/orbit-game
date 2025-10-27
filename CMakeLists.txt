cmake_minimum_required(VERSION 3.10)

project(my_cpp_project_cmake LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(my_program src/main.cpp)