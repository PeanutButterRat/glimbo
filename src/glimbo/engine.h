#pragma once

#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Engine();

        void update();

        Window window;

    private:
        uint64_t last_frame = 0;
    };
} // namespace glimbo
