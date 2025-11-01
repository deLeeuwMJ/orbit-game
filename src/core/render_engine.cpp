#include <iostream>

#include "../engine/render_sdl3_engine.hpp"
#include "render_engine.hpp"
#include "constants.hpp"

namespace core
{
    std::unique_ptr<RenderEngine> determineRenderStrategy()
    {
        return std::make_unique<RenderEngineSDL3>();
    }
}