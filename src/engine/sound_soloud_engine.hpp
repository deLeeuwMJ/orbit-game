#include <iostream>

#include <soloud.h>
#include <soloud_wav.h>
#include "../core/sound_engine.hpp"

class SoundEngineSOLOUD : public core::SoundEngine
    {
        public:
            ~SoundEngineSOLOUD();
            void setup() override;
            void loadSoundFile(std::string) override;
            void playSound() override;
            bool isActive() override;
            double getSoundTimePosition() override;
            void sleep() override;
        private:
            SoLoud::Soloud engine;
            SoLoud::Wav soundFile;
            SoLoud::handle soundHandle;
    };