#pragma once

#include "glimbo/engine.h"
#include "glimbo/scene.h"

namespace glimbo {
    struct Editor {
        Engine &engine;
        Scene scene;

        explicit Editor(Engine &engine);

        void update() const;
    };
} // namespace glimbo
