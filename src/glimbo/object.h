#pragma once

#include <vector>

#include "glimbo/camera.h"
#include "glimbo/component.h"
#include "glimbo/math.h"

namespace glimbo {
    struct Object {
        Vec3 position = Vec3(0, 0, 0);
        Vec3 rotation = Vec3(0, 0, 0);
        Vec3 scale = Vec3(1, 1, 1);
        bool visible = true;
        std::vector<std::shared_ptr<Component>> components;

        void add(const std::shared_ptr<Component> &component);

        void update(float dt) const;

        void draw(const Camera &camera) const;

        Matrix model() const;
    };
} // namespace glimbo
