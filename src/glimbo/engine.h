#pragma once

#include "glimbo/mouse.h"
#include "glimbo/scene.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Window window;
        Scene scene;
        Mouse mouse;

        Engine();

        float update() const;
    };
} // namespace glimbo
