#pragma once

#include "glimbo/engine.h"
#include "glimbo/scene.h"

namespace glimbo {
    struct Editor {
        Engine &engine;
        Scene scene;
        bool moving = false;
        std::shared_ptr<Object> focused;
        float distance = 10;
        float inclination = 0;
        float azimuth = 0;
        std::shared_ptr<List> list;

        explicit Editor(Engine &engine);

        void update() const;

        void add(const std::shared_ptr<Object> &object) const;
    };
} // namespace glimbo
