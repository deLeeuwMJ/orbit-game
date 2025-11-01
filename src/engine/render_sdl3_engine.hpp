#pragma once

#include "../core/render_engine.hpp"
#include <SDL3/SDL.h>
#include <functional>

struct SDL3_Clock
{
    uint32_t last_tick_time = 0;
    uint32_t delta = 0;

    void tick()
    {
        uint32_t tick_time = SDL_GetTicks();
        delta = tick_time - last_tick_time;
        last_tick_time = tick_time;
    }
};
class RenderEngineSDL3 : public core::RenderEngine
{
    public:
        ~RenderEngineSDL3();
        void setup() override;
        void render() override;
        void sleep() override;
        bool isActive() override;
        void stop() override;
        void clear() override;
        void setScene(core::SceneRenderable& scene) override;
        core::SceneRenderable* getCurrentScene() const override;
    private:
        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        std::function<void(void)> sceneCallback;
        core::SceneRenderable* currentScene = nullptr;
        bool active = true;
};

