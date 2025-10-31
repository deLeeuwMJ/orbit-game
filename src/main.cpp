#include <iostream>
#include <fstream>
#include <string>

#include "stdint.h"
#include "component/game_scene.hpp"
#include "core/render_engine.hpp"
#include "core/constants.hpp"

int main(int argc, char* argv[]) {
    auto renderEngine = core::determineRenderStrategy();
    renderEngine->setup();

    std::unique_ptr<SceneRenderable> gameScene = std::make_unique<GameScene>();
    renderEngine->setScene(*gameScene);

    core::Clock clock{};

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