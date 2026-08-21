#include "object.h"

using namespace glimbo;

void Object::update(const float dt) const {
    for (const auto &component: components) {
        component->update(dt);
    }
}

void Object::draw(const Camera &camera) const {
    for (const auto &component: components) {
        component->draw(camera);
    }
}

void Object::bind(py::module_ &m) {
    py::classh<Object>(m, "Object")
        .def(py::init<>())
        .def("add", &Object::add);
}
