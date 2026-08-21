#include "camera.h"

#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

using namespace glimbo;

Matrix Camera::view() const {
    const float pitch = rotation.x;
    const float yaw = rotation.y;
    const float x = sinf(glm::radians(yaw)) * cosf(glm::radians(pitch));
    const float y = sinf(glm::radians(pitch));
    const float z = -cosf(glm::radians(yaw)) * cosf(glm::radians(pitch));

    const Vec3 forward = glm::normalize(Vec3(x, y, z));
    const Vec3 up = glm::normalize(glm::cross(forward, Vec3(0, 1, 0)));
    const Vec3 right = glm::normalize(glm::cross(up, forward));

    return glm::lookAt(position, position + forward, right);

}

Matrix Camera::projection() const {
    const float aspect = viewport.x / viewport.y;
    return glm::perspective(glm::radians(fov), aspect, near, far);
}

void Camera::bind(py::module_ &m) {
    py::class_<Camera>(m, "Camera")
        .def_readwrite("position", &Camera::position)
        .def("view", &Camera::view);
}
