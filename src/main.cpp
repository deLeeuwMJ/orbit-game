#include <iostream>
#include <fstream>
#include <string>

#include "stdint.h"

#include "game/game_scene.hpp"
#include "engine/render_sdl3_engine.hpp"
#include "engine/sound_soloud_engine.hpp"

#include "core/file_path.hpp"
#include "core/render_engine.hpp"
#include "core/sound_engine.hpp"
#include "core/constants.hpp"

int main(int argc, char* argv[]) {
    auto renderEngine = core::determineRenderStrategy();
    renderEngine->setup();

    auto soundEngine = core::determineSoundStrategy();
    soundEngine->setup();
    soundEngine->loadSoundFile(core::getFilePathSFX("piano_loop.wav"));
    soundEngine->playSound();

    std::unique_ptr<core::SceneRenderable> gameScene = std::make_unique<GameScene>();
    renderEngine->setScene(*gameScene);

    SDL3_Clock clock{};

    SDL_Event event;
    while (renderEngine->isActive()) {
        clock.tick();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) {
                renderEngine->stop();
            }
        }

        auto const &currentScene = renderEngine->getCurrentScene();
        if (currentScene)
            currentScene->update(clock.delta);

        renderEngine->render();
    }

    return 0;
}