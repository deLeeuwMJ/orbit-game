#pragma once

#include <memory>
#include "render_scene.hpp"
#include <iostream>

namespace core
{
    class RenderEngine
    {
        public:
            virtual void setup() = 0;
            virtual void render() = 0;
            virtual void sleep() = 0;
            virtual bool isActive() = 0;
            virtual void stop() = 0;
            virtual void clear() = 0;

            virtual void setScene(SceneRenderable&) = 0;
            virtual SceneRenderable* getCurrentScene() const = 0;
    };

    std::unique_ptr<RenderEngine> determineRenderStrategy();

    inline std::ostream& operator<<(std::ostream& os, const SceneType& type) {
        switch (type) {
            case SceneType::GAME: return os << "GAME";
            default: return os << "UNKNOWN";
        }
    }
}
