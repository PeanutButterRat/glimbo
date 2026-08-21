#pragma once

#include <vector>

#include "glimbo/camera.h"
#include "glimbo/common.h"
#include "glimbo/component.h"

namespace glimbo {
    struct Object {
        std::vector<std::shared_ptr<Component>> components;

        void add(const std::shared_ptr<Component> &component) { components.push_back(component); }

        void update(float dt) const;

        void draw(const Camera &camera) const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
