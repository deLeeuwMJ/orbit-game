#include <cstdint>

namespace model
{
    struct ObjectPosition
    {
        float x;
        float y;
    };

    struct ObjectColor
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
}