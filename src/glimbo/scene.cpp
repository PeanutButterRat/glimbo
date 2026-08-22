#include "scene.h"

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl3.h>

using namespace glimbo;

void Scene::update(const float dt) const {
    for (const auto &object : objects) {
        object->update(dt);
    }
}

void Scene::draw() const {
    for (const auto &object : objects) {
        object->draw(camera);
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    for (const auto &element : elements) {
        element->draw();
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Scene::bind(py::module_ &m) {
    py::classh<Scene>(m, "Scene")
        .def_readonly("camera", &Scene::camera)
        .def("draw", &Scene::draw);
}

