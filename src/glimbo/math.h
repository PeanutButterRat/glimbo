#pragma once

#include <glm/glm.hpp>

#include "glimbo/common.h"

namespace glimbo {
    using Vec2 = glm::vec2;
    using Vec3 = glm::vec3;
    using Vec4 = glm::vec4;
    using Matrix = glm::mat4;

    void bind_math(py::module_ &m);
}; // namespace glimbo
