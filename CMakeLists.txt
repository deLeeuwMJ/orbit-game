cmake_minimum_required(VERSION 3.10)

project(orbit LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

set(DEPENDENCY_DIR "${CMAKE_SOURCE_DIR}/_dependencies")

include(libs.cmake)

add_subdirectory(${DEPENDENCY_DIR}/SDL EXCLUDE_FROM_ALL)
add_subdirectory(${DEPENDENCY_DIR}/SDL_image EXCLUDE_FROM_ALL)
add_subdirectory(${DEPENDENCY_DIR}/nlohmann_json EXCLUDE_FROM_ALL)
add_soloud_sdk()

set(FILE_SRC_DIR src)
set(SRC_CORE_DIR ${FILE_SRC_DIR}/core)
set(SRC_ENGINE_DIR ${FILE_SRC_DIR}/engine)
set(SRC_GAME_DIR ${FILE_SRC_DIR}/game)

set(SOURCES
    ${FILE_SRC_DIR}/main.cpp

    ${SRC_CORE_DIR}/constants.hpp
    ${SRC_CORE_DIR}/random.hpp
    ${SRC_CORE_DIR}/render_engine.cpp
    ${SRC_CORE_DIR}/render_engine.hpp
    ${SRC_CORE_DIR}/render_scene.hpp
    ${SRC_CORE_DIR}/sound_engine.cpp
    ${SRC_CORE_DIR}/sound_engine.hpp

    ${SRC_ENGINE_DIR}/render_sdl3_engine.cpp
    ${SRC_ENGINE_DIR}/render_sdl3_engine.hpp
    ${SRC_ENGINE_DIR}/sound_soloud_engine.cpp
    ${SRC_ENGINE_DIR}/sound_soloud_engine.hpp
    
    ${SRC_GAME_DIR}/game_scene.cpp
    ${SRC_GAME_DIR}/game_scene.hpp
    ${SRC_GAME_DIR}/shuttle_cfg.hpp
    ${SRC_GAME_DIR}/shuttle.hpp
)

add_executable(orbit ${SOURCES})

target_link_libraries(orbit PRIVATE 
    SDL3_image::SDL3_image
    SDL3::SDL3
    nlohmann_json::nlohmann_json
    soloud
)