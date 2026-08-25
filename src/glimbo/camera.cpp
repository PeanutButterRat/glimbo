#include "camera.h"

#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

using namespace glimbo;

Matrix Camera::view() const {
    const float pitch = glm::radians(rotation.x);
    const float yaw = glm::radians(rotation.y);

    const Vec3 forward = {
            sinf(yaw) * cosf(pitch),
            sinf(pitch),
            -cosf(yaw) * cosf(pitch),
    };

    return glm::lookAt(position, position + forward, {0, 1, 0});
}

Matrix Camera::projection() const {
    const float aspect = viewport.x / viewport.y;
    return glm::perspective(glm::radians(fov), aspect, near, far);
}

void Camera::look(const Vec3 &target) {
    const Vec3 direction = glm::normalize(target - position);

    rotation = {
            glm::degrees(std::asin(direction.y)),
            glm::degrees(std::atan2(direction.x, -direction.z)),
            0,
    };
}
