#pragma once

#include <cstdint>
#include <SDL3/SDL.h>

namespace core
{
    enum class SceneType : uint16_t
    {
        NONE = 0,
        GAME,
    };
    
    class SceneRenderable
    {
    public:
        virtual ~SceneRenderable() = default;
        virtual void setup() = 0;
        virtual void loadTextures(SDL_Renderer&) = 0; // TODO: Make SDL_Renderer generic
        virtual void render(SDL_Renderer&) = 0;
        virtual void update(uint32_t delta) = 0;
    
        virtual SceneType getSceneType() const = 0;
    };
}