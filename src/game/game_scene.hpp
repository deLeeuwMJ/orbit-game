#pragma once

#include <cstdint>
#include <SDL3/SDL.h>
#include "../core/render_scene.hpp"
#include "shuttle.hpp"

class GameScene : public core::SceneRenderable
{
public:
    void setup() override;
    void loadTextures(SDL_Renderer&) override;
    void render(SDL_Renderer&) override;
    void update(uint32_t delta) override;

    core::SceneType getSceneType() const override { return core::SceneType::GAME; }
private:
    SDL_Texture* backgroundTexture = nullptr;
    SDL_Texture* overlayTexture = nullptr;
    SDL_Texture* shuttleBlueTexture = nullptr;
    SDL_Texture* shuttleRedTexture = nullptr;
    SDL_Texture* shuttleGreenTexture = nullptr;

    SDL_Texture* getShuttleTextureByColor(ShuttleColor color);
    void createShuttle(ShuttleColor color);
};
