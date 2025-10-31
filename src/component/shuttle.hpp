#pragma once

#include <cstdint>

namespace model
{
    enum ShuttleColor : uint16_t
    {
        BLUE = 0,
        RED,
        GREEN,
    };

    struct ShuttleObject
    {
        model::ObjectPosition position;
        model::ShuttleColor type;
    };
}