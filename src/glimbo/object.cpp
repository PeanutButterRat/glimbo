#include "object.h"

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
    Matrix t = Matrix::translation(position);
    Matrix rx = Matrix::rotation(rotation[0], {1, 0, 0});
    Matrix ry = Matrix::rotation(rotation[1], {1, 0, 0});
    Matrix rz = Matrix::rotation(rotation[2], {1, 0, 0});
    Matrix s = Matrix::scale(scale);
    return t * rz * ry * rx * s;
}
