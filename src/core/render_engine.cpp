#include <iostream>

#include "render_engine.hpp"
#include "constants.hpp"
#include <SDL3_image/SDL_image.h>

namespace core
{
    std::unique_ptr<RenderEngine> determineRenderStrategy()
    {
        return std::make_unique<RenderEngineSDL3>();
    }

    void RenderEngineSDL3::setup()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
            return;
        }

        if (!SDL_CreateWindowAndRenderer(
            WINDOW_TITLE,
            WINDOW_WIDTH, WINDOW_HEIGHT, 
            0,
            &window, &renderer)) 
        {
            std::cerr << "Window/Renderer creation failed: " << SDL_GetError() << std::endl;
            SDL_Quit();
            return;
        }
    }

    void RenderEngineSDL3::render()
    {
        this->clear();

        if (sceneCallback)
            sceneCallback();

        SDL_RenderPresent(renderer);
    }

    void RenderEngineSDL3::clear()
    {
        SDL_SetRenderDrawColor(renderer, 248, 233, 210, 255);
        SDL_RenderClear(renderer);
    }

    void RenderEngineSDL3::stop()
    {
        this->active = false;
    }

    bool RenderEngineSDL3::isActive()
    {
        return this->active;
    }

    void RenderEngineSDL3::sleep()
    {
        SDL_Delay(1000/60);
    }

    void RenderEngineSDL3::setScene(SceneRenderable& scene)
    {
        std::cout << "Switched to "<< scene.getSceneType() << std::endl;

        currentScene = &scene;
        currentScene->loadTextures(*renderer);

        switch(scene.getSceneType())
        {
            case SceneType::GAME:
                sceneCallback = [this]() {
                    if (currentScene) {
                        currentScene->render(*renderer);
                    }
                };
                break;
        }
    }

    SceneRenderable* RenderEngineSDL3::getCurrentScene() const
    {
        return currentScene;
    }

    RenderEngineSDL3::~RenderEngineSDL3()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}