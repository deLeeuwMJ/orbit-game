#include "render_scene.hpp"
#include "random.hpp"
#include <iostream>
#include <SDL3_image/SDL_image.h>

static model::ObjectPosition newPosition = { 100, 100 };
static model::ObjectColor randomColor = random_gen::colorRGBA();

void GameScene::loadTextures(SDL_Renderer& renderer)
{
    // Not Implemented
}

void GameScene::render(SDL_Renderer& renderer)
{
    SDL_SetRenderDrawColor(&renderer, randomColor.r, randomColor.g, randomColor.b, randomColor.a);
    SDL_FRect rect = { newPosition.x, newPosition.y, 200, 200 };
    SDL_RenderFillRect(&renderer, &rect);
}

void GameScene::update()
{
    newPosition.x += 1;
    newPosition.y += 1;
}