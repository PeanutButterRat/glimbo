#pragma once

#include "glimbo/engine.h"
#include "glimbo/scene.h"

namespace glimbo {
    struct Editor {
        Engine &engine;
        Scene scene;
        bool moving = false;
        Vec3 focus = {0, 0, 0};
        float distance = 10;
        float inclination = 0;
        float azimuth = 0;

        explicit Editor(Engine &engine);

        void update() const;
    };
} // namespace glimbo
