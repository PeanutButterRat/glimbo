#include "element.h"

#include <imgui.h>
#include <ostream>
#include <ranges>

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

void List::draw() {
    static int focused = -1;
    bool _ = false;

    for (auto const [index, item]: std::views::enumerate(items)) {
        if (ImGui::Selectable(item.c_str(), &_, (index == focused) ? ImGuiSelectableFlags_Highlight : ImGuiSelectableFlags_None)) {
            selected.handle(static_cast<int>(index));
            focused = static_cast<int>(index);
        }
    }
}

void Input::draw() {
    const float saved[3] = {value[0], value[1], value[2]};

    ImGui::Text("%s", label.c_str());
    ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
    ImGui::InputFloat3("##", value, "%.3f", ImGuiInputTextFlags_None);

    if (saved[0] != value[0] || saved[1] != value[1] || saved[2] != value[2]) {
        changed.handle(value[0], value[1], value[2]);
    }
}
