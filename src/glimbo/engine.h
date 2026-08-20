#pragma once

#include <cstdint>

#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Engine();

        void update();

        void run();

    private:
        uint64_t last_frame = 0;
        Window window;
    };
} // namespace glimbo
