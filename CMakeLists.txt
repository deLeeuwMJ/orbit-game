cmake_minimum_required(VERSION 3.10)

project(orbit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(DEPENDENCY_DIR "${CMAKE_SOURCE_DIR}/_dependencies")

add_subdirectory(${DEPENDENCY_DIR}/SDL EXCLUDE_FROM_ALL)
add_subdirectory(${DEPENDENCY_DIR}/SDL_image EXCLUDE_FROM_ALL)

set(SOURCES
    src/main.cpp
)

add_executable(orbit ${SOURCES})

target_link_libraries(orbit PRIVATE 
    SDL3_image::SDL3_image
    SDL3::SDL3
)