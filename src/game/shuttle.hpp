#pragma once

#include <cstdint>
#include "../core/model.hpp"

enum ShuttleColor : uint16_t
{
    BLUE = 0,
    RED,
    GREEN,
};

struct ShuttleObject
{
    model::ObjectPosition position;
    ShuttleColor type;
};
