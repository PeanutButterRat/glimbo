#pragma once

#include "glimbo/element.h"
#include "glimbo/object.h"

namespace glimbo {
    struct Scene {
        std::vector<std::shared_ptr<Object>> objects;
        Element ui;
        Camera camera;

        void add(const std::shared_ptr<Object> &object) { objects.push_back(object); }

        std::shared_ptr<Object> find(const std::string &name) const;

        void update(float dt) const;

        void draw();
    };
} // namespace glimbo
