#pragma once

#include "glimbo/common.h"
#include "glimbo/object.h"

namespace glimbo {
    struct Scene {
        std::shared_ptr<Object> root = nullptr;
        Camera camera;

        void add(const std::shared_ptr<Object> &object) { root = object; }

        void update(float dt) const;

        void draw() const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
