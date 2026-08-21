#pragma once

#include "glimbo/common.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Engine();

        void update();

        Window window;

        static void bind(py::module_ &m);

    private:
        uint64_t last_frame = 0;
    };
} // namespace glimbo
