#include "element.h"

#include <imgui.h>
#include <ostream>

using namespace glimbo;

void Element::draw() {
    for (const auto &child: children) {
        if (child->visible) {
            child->draw();
        }
    }
}

void Panel::draw() {
    ImGui::SetNextWindowSize({size.x, size.y});
    ImGui::SetNextWindowPos({position.x, position.y});
    ImGui::Begin(title.c_str(), closeable ? &visible : nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse);
    Element::draw();
    ImGui::End();
}

void Button::draw() {
    if (ImGui::Button(label.c_str()) && callback) {
        callback();
    }
}
