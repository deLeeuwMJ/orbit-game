#pragma once

#include <string>
#include <memory>

namespace core
{   
    class SoundEngine
    {
        public:
            virtual void setup() = 0;
            virtual void loadSoundFile(std::string) = 0;
            virtual void playSound() = 0;
            virtual bool isActive() = 0;
            virtual double getSoundTimePosition() = 0;
            virtual void sleep() = 0;
    };

    class SoundEngineStub : public SoundEngine
    {
        public:
            void setup() override {}
            void loadSoundFile(std::string) override {}
            void playSound() override {}
            bool isActive() override { return false; }
            double getSoundTimePosition() override { return 0.0; }
            void sleep() override {}
    };

    std::unique_ptr<SoundEngine> determineSoundStrategy();
}
