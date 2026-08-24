#include "component.h"
#include "object.h"

using namespace glimbo;

Model::Model(const std::shared_ptr<Mesh> &mesh, const std::shared_ptr<Shader> &shader) {
    this->mesh = mesh;
    this->shader = shader;
}

void Model::draw(const Camera &camera) const {
    shader->use();
    shader->set("model", owner->model());
    shader->set("view", camera.view());
    shader->set("projection", camera.projection());
    mesh->draw();
}
