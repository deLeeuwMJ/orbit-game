#pragma once

#include "model.hpp"
#include <random>

namespace random_gen
{
    model::ObjectColor colorRGBA()
    {
        model::ObjectColor color;
        color.r = rand() % 256;
        color.g = rand() % 256;
        color.b = rand() % 256;
        color.a = 255;
        return color;
    }
}