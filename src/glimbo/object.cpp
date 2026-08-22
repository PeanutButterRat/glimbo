#include "object.h"

#include <glm/gtc/matrix_transform.hpp>

using namespace glimbo;

void Object::add(const std::shared_ptr<Component> &component) {
    components.push_back(component);
    component->owner = this;
}

void Object::update(const float dt) const {
    for (const auto &component: components) {
        component->update(dt);
    }
}

void Object::draw(const Camera &camera) const {
    if (visible) {
        for (const auto &component: components) {
            component->draw(camera);
        }
    }
}

Matrix Object::model() const {
    Matrix model = glm::translate(glm::mat4(1), position);
    model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0, 0, 1));
    model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0, 1, 0));
    model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1, 0, 0));
    model = glm::scale(model, scale);
    return model;
}

void Object::bind(py::module_ &m) {
    py::classh<Object>(m, "Object")
        .def(py::init<>())
        .def("add", &Object::add);
}
