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

set(SOURCES
    src/main.cpp
    
    src/core/constants.hpp
    src/core/random.hpp
    src/core/render_engine.cpp
    src/core/render_engine.hpp
    src/core/render_scene.hpp
    src/core/sound_engine.cpp
    src/core/sound_engine.hpp

    src/component/render_sdl3_engine.cpp
    src/component/render_sdl3_engine.hpp
    src/component/sound_soloud_engine.cpp
    src/component/sound_soloud_engine.hpp
    src/component/game_scene.cpp
    src/component/game_scene.hpp
    src/component/shuttle_cfg.hpp
    src/component/shuttle.hpp
)

add_executable(orbit ${SOURCES})

target_link_libraries(orbit PRIVATE 
    SDL3_image::SDL3_image
    SDL3::SDL3
    nlohmann_json::nlohmann_json
    soloud
)

# target_include_directories(orbit PRIVATE
#     ${CMAKE_SOURCE_DIR}/_dependencies/SOLOUD/include
# )