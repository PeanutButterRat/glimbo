#include "scene.h"

using namespace glimbo;

void Scene::update(float dt) const {
    if (root) {
        root->update(dt);
    }
}

void Scene::draw() const {
    if (root) {
        root->draw(camera);
    }
}

void Scene::bind(py::module_ &m) {
    py::classh<Scene>(m, "Scene")
        .def_readonly("camera", &Scene::camera)
        .def("add", &Scene::add)
        .def("draw", &Scene::draw);
}

