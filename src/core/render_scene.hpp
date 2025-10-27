#pragma once

#include <cstdint>
#include <SDL3/SDL.h>

enum SceneType : uint16_t
{
    NONE = 0,
    GAME,
};

class SceneRenderable
{
public:
    virtual ~SceneRenderable() = default;
    virtual void loadTextures(SDL_Renderer& renderer) = 0;
    virtual void render(SDL_Renderer& renderer) = 0;
    virtual void update() = 0;
    
    virtual SceneType getSceneType() const = 0;
};

class GameScene : public SceneRenderable
{
public:
    void loadTextures(SDL_Renderer& renderer) override;
    void render(SDL_Renderer& renderer) override;
    void update() override;
    
    SceneType getSceneType() const override { return SceneType::GAME; }
};
