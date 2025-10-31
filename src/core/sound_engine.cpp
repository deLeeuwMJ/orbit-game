#include "sound_engine.hpp"
// #include "../component/sound_soloud_engine.hpp"

namespace core
{
    std::unique_ptr<SoundEngine> determineSoundStrategy()
    {
        return std::make_unique<SoundEngineStub>();
    }
}