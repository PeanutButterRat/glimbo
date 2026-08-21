#pragma once

#include "glimbo/camera.h"
#include "glimbo/common.h"
#include "glimbo/mesh.h"
#include "glimbo/shader.h"

namespace glimbo {
    struct Component {
        virtual void update(float dt) {}

        virtual void draw(const Camera &camera) const {}

        virtual ~Component() = default;

        static void bind(py::module_ &m);
    };

    struct Model : Component {
        std::shared_ptr<Mesh> mesh;
        std::shared_ptr<Shader> shader;

        Model(const std::shared_ptr<Mesh> &mesh, const std::shared_ptr<Shader> &shader);

        void draw(const Camera &camera) const override;

        static void bind(py::module_ &m);
    };
} // namespace glimbo
