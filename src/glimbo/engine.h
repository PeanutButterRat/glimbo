#pragma once

#include "glimbo/common.h"
#include "glimbo/scene.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Window window;
        Scene scene;

        Engine();

        void update() const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
