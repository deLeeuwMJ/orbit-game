#pragma once

#include <SDL3/SDL.h>
#include <memory>
#include <functional>
#include "render_scene.hpp"

namespace core
{
    struct Clock
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
    
    class RenderEngine
    {
        public:
            virtual void setup() = 0;
            virtual void render() = 0;
            virtual void sleep() = 0;
            virtual bool isActive() = 0;
            virtual void stop() = 0;
            virtual void clear() = 0;

            virtual void setScene(SceneRenderable&) = 0;
            virtual SceneRenderable* getCurrentScene() const = 0;
    };

    class RenderEngineSDL3 : public RenderEngine
    {
        public:
            ~RenderEngineSDL3();
            void setup() override;
            void render() override;
            void sleep() override;
            bool isActive() override;
            void stop() override;
            void clear() override;

            void setScene(SceneRenderable& scene) override;
            SceneRenderable* getCurrentScene() const override;
        private:
            SDL_Window* window = nullptr;
            SDL_Renderer* renderer = nullptr;
            std::function<void(void)> sceneCallback;
            SceneRenderable* currentScene = nullptr;
            bool active = true;
    };

    std::unique_ptr<RenderEngine> determineRenderStrategy();
}
