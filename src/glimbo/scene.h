#pragma once

#include "glimbo/common.h"
#include "glimbo/element.h"
#include "glimbo/object.h"

namespace glimbo {
    struct Scene {
        std::vector<std::shared_ptr<Object>> objects;
        std::vector<std::shared_ptr<Element>> elements;
        Camera camera;

        void add(const std::shared_ptr<Object> &object) { objects.push_back(object); }

        void add(const std::shared_ptr<Element> &element) { elements.push_back(element); }

        void update(float dt) const;

        void draw() const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
