#pragma once

#include <functional>

#include "glimbo/common.h"
#include "glimbo/scene.h"
#include "glimbo/window.h"

namespace glimbo {
    struct Engine {
        Window window;
        Scene scene;
        std::vector<std::function<void(float, float)>> callbacks;

        Engine();

        float update() const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
