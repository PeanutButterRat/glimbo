#include "element.h"

#include <imgui.h>

using namespace glimbo;

void Panel::draw() {
    ImGui::SetNextWindowSize({size.x, size.y});
    ImGui::SetNextWindowPos({position.x, position.y});
    ImGui::Begin("Panel", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);

    for (const auto &child: children) {
        child->draw();
    }

    ImGui::End();
}

void Button::draw() {
    if (ImGui::Button(label.c_str()) && callback) {
        callback();
    }
}
