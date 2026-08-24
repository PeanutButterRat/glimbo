#pragma once

#include "glimbo/keyboard.h"
#include "glimbo/mouse.h"
#include "glimbo/scene.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Window window;
        Scene scene;
        Mouse mouse;
        Keyboard keyboard;

        Engine();

        float poll() const;
    };
} // namespace glimbo
