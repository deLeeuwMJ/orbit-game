#include "render_scene.hpp"
#include "random.hpp"
#include <iostream>
#include <SDL3_image/SDL_image.h>

static model::ObjectPosition newPosition = { 100, 100 };
static model::ObjectColor randomColor = random_gen::colorRGBA();

void GameScene::loadTextures(SDL_Renderer& renderer)
{
    std::cout << "LOADING GAME SCENE TEXTURES..." << std::endl;
    this->ballTexture = IMG_LoadTexture(&renderer, "_resources/ball.png");
}

void GameScene::render(SDL_Renderer& renderer)
{
    SDL_FRect rect = { newPosition.x, newPosition.y, static_cast<float>(ballTexture->w), static_cast<float>(ballTexture->h) };
    SDL_RenderTexture(&renderer, ballTexture, NULL, &rect);
}

void GameScene::update()
{
    newPosition.x += 1;
    newPosition.y += 1;
}