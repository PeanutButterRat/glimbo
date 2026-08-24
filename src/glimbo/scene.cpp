#include "scene.h"

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl3.h>

using namespace glimbo;

void Scene::update(const float dt) const {
    for (const auto &object: objects) {
        object->update(dt);
    }
}

void Scene::draw() {
    for (const auto &object: objects) {
        object->draw(camera);
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ui.draw();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
