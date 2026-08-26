#pragma once

#include "glimbo/math.h"

namespace glimbo {
    struct Camera {
        Vec3 position = {0, 0, 0};
        Vec3 rotation = {0, 0, 0};
        Vec2 viewport;
        float fov;
        float near;
        float far;

        Camera() : Camera({1000, 800}, 45, 0.1, 100) {}

        Camera(const Vec2 &viewport, float fov, float near, float far) : viewport(viewport), fov(fov), near(near), far(far) {}

        Matrix view() const;

        Matrix projection() const;

        void look_at(const Vec3 &target);
    };
} // namespace glimbo
