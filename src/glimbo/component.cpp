#include "component.h"

using namespace glimbo;

Model::Model(const std::shared_ptr<Mesh> &mesh, const std::shared_ptr<Shader> &shader) {
    this->mesh = mesh;
    this->shader = shader;
}

void Model::draw(const Camera &camera) const {
    shader->use();
    shader->set("projection", camera.projection());
    shader->set("view", camera.view());
    mesh->draw();
}

void Component::bind(py::module_ &m) {
    py::classh<Component>(m, "Component");
}

void Model::bind(py::module_ &m) {
    py::classh<Model, Component>(m, "Model")
            .def(py::init<std::shared_ptr<Mesh>, std::shared_ptr<Shader>>())
            .def("draw", &Model::draw);
}
