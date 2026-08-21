#pragma once

#include "glimbo/common.h"
#include "glimbo/math.h"

namespace glimbo {
    struct Camera {
        Vec3 position{0, 0, 0};
        Vec3 rotation{0, 0, 0};
        Vec2 viewport;
        float fov;
        float near;
        float far;

        Camera() : Camera({1000, 800}, 45, 0.1, 100) {}

        Camera(const Vec2 &viewport, float fov, float near, float far) : viewport(viewport), fov(fov), near(near), far(far) {}

        Matrix view() const;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
