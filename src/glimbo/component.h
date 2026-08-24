#pragma once

#include <memory>

#include "glimbo/camera.h"
#include "glimbo/mesh.h"
#include "glimbo/shader.h"

namespace glimbo {
    struct Object;

    struct Component {
        Object *owner;

        virtual void update(float dt) {}

        virtual void draw(const Camera &camera) const {}

        virtual ~Component() = default;
    };

    struct Model : Component {
        std::shared_ptr<Mesh> mesh;
        std::shared_ptr<Shader> shader;

        Model(const std::shared_ptr<Mesh> &mesh, const std::shared_ptr<Shader> &shader);

        void draw(const Camera &camera) const override;
    };
} // namespace glimbo
