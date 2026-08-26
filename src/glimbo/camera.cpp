#include "camera.h"

#include <cmath>

using namespace glimbo;

Matrix Camera::view() const {
    const float pitch = radians(rotation[0]);
    const float yaw = radians(rotation[1]);

    const Vec3 forward = {
        sinf(yaw) * cosf(pitch),
        sinf(pitch),
        -cosf(yaw) * cosf(pitch),
    };

    return Matrix::look_at(position, position + forward, {0, 1, 0});
}

Matrix Camera::projection() const {
    const float aspect = viewport[0] / viewport[1];
    return Matrix::perspective(fov, aspect, near, far);
}

void Camera::look_at(const Vec3 &target) {
    const Vec3 direction = (target - position).normalized();

    rotation = {
        degrees(std::asin(direction[1])),
        degrees(std::atan2(direction[0], -direction[2])),
        0,
    };
}
