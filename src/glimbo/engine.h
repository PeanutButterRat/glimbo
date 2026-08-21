#pragma once

#include "glimbo/camera.h"
#include "glimbo/common.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Engine();

        void update();

        Window window;
        Camera camera;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
