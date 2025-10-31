#pragma once

#include <cstdint>
#include <SDL3/SDL.h>
#include "model.hpp"

enum SceneType : uint16_t
{
    NONE = 0,
    GAME,
};

class SceneRenderable
{
public:
    virtual ~SceneRenderable() = default;
    virtual void setup() = 0;
    virtual void loadTextures(SDL_Renderer&) = 0;
    virtual void render(SDL_Renderer&) = 0;
    virtual void update(uint32_t delta) = 0;

    virtual SceneType getSceneType() const = 0;
};
