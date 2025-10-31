#include "../component/game_scene.hpp"
#include <iostream>
#include <SDL3_image/SDL_image.h>
#include "shuttle_cfg.hpp"
#include <vector>

struct ShuttleData
{
    model::ShuttleObject shuttle;
    SDL_Texture* texture;
};

static std::vector<ShuttleData> activeShuttles{};

SDL_Texture* GameScene::getShuttleTextureByColor(model::ShuttleColor color)
{
    switch (color)
    {
        case model::ShuttleColor::BLUE:
            return this->shuttleBlueTexture;
        case model::ShuttleColor::RED:
            return this->shuttleRedTexture;
        case model::ShuttleColor::GREEN:
            return this->shuttleGreenTexture;
        default:
            return nullptr;
    }
}

void GameScene::createShuttle(model::ShuttleColor color)
{
    model::ObjectPosition spawnPosition;

    switch (color)
    {
        case model::ShuttleColor::BLUE:
            spawnPosition = BLUE_SHUTTLE_SPAWN_LOCATION;
            break;
        case model::ShuttleColor::RED:
            spawnPosition = RED_SHUTTLE_SPAWN_LOCATION;
            break;
        case model::ShuttleColor::GREEN:
            spawnPosition = GREEN_SHUTTLE_SPAWN_LOCATION;
            break;
    }

    auto newShuttle = model::ShuttleObject{
        .position = spawnPosition,
        .type = color
    };

    auto shuttleData = ShuttleData{
        .shuttle = newShuttle,
        .texture = getShuttleTextureByColor(color)
    };

    activeShuttles.push_back(shuttleData);
}

void GameScene::setup()
{
    std::cout << "SETTING UP GAME SCENE..." << std::endl;

    createShuttle(model::ShuttleColor::BLUE);
    createShuttle(model::ShuttleColor::RED);
    createShuttle(model::ShuttleColor::GREEN);
}

void GameScene::loadTextures(SDL_Renderer& renderer)
{
    std::cout << "LOADING GAME SCENE TEXTURES..." << std::endl;

    this->backgroundTexture = IMG_LoadTexture(&renderer, "_resources/background.png");
    this->overlayTexture = IMG_LoadTexture(&renderer, "_resources/overlay.png");
    this->shuttleBlueTexture = IMG_LoadTexture(&renderer, "_resources/shuttle_blue.png");
    this->shuttleRedTexture = IMG_LoadTexture(&renderer, "_resources/shuttle_red.png");
    this->shuttleGreenTexture = IMG_LoadTexture(&renderer, "_resources/shuttle_green.png");
}

void GameScene::render(SDL_Renderer& renderer)
{
    SDL_FRect backgroundRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
    SDL_RenderTexture(&renderer, backgroundTexture, NULL, &backgroundRect);

    SDL_FRect overlayRect = { WINDOW_WIDTH * 0.8f, 0, 5, WINDOW_HEIGHT };
    SDL_RenderTexture(&renderer, overlayTexture, NULL, &overlayRect);

    for (const auto& shuttleData : activeShuttles)
    {
        const auto& shuttlePos = shuttleData.shuttle.position;
        SDL_FRect shuttleRect = { shuttlePos.x, shuttlePos.y, static_cast<float>(shuttleData.texture->w)/2, static_cast<float>(shuttleData.texture->h)/2 };
        SDL_RenderTexture(&renderer, shuttleData.texture, NULL, &shuttleRect);
    }
}

void GameScene::update(uint32_t deltaMs)
{
    for (auto& shuttleData : activeShuttles)
    {
        shuttleData.shuttle.position.x += SHUTTLE_SPEED * deltaMs;
    }
}