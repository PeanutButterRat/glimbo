#include "editor.h"

#include "glimbo/element.h"

using namespace glimbo;

Editor::Editor(Engine &engine) : engine(engine) {
    list = std::make_shared<List>();
    list->selected.connect([&](int index) -> void {
        const auto name = list->items[index];
        focused = engine.scene.find(name);
    });

    auto panel = std::make_shared<Panel>();
    panel->title = "Scene";
    panel->position.x = 1000;
    panel->size = {200, 400};
    panel->closeable = false;
    panel->add(list);
    engine.scene.ui.add(panel);

    panel = std::make_shared<Panel>();
    panel->title = "Properties";
    panel->position.x = 1000;
    panel->position.y = 400;
    panel->size = {200, 400};
    panel->closeable = false;
    engine.scene.ui.add(panel);

    auto input = std::make_shared<Input>();
    input->label = "Transform";
    panel->add(input);

    input->changed.connect([&](float x, float y, float z) -> void {
        if (focused) {
            focused->position.x = x;
            focused->position.y = y;
            focused->position.z = z;
        }
    });

    engine.mouse.moved.connect([&](float dx, float dy) -> void {
        if (moving) {
            constexpr float sensitivity = 0.1;
            azimuth -= dx * sensitivity;
            inclination -= -dy * sensitivity;
        }
    });

    engine.mouse.pressed.connect([&](Mouse::Button button) -> void {
        if (button == Mouse::Button::MIDDLE) {
            moving = true;
        }
    });

    engine.mouse.released.connect([&](Mouse::Button button) -> void {
        if (button == Mouse::Button::MIDDLE) {
            moving = false;
        }
    });

    engine.mouse.scrolled.connect([&](int scroll) -> void { distance -= scroll; });
}

void Editor::update() const {
    const float dt = engine.poll();

    engine.scene.camera.position = {
            distance * cos(glm::radians(inclination)) * sin(glm::radians(azimuth)),
            distance * sin(glm::radians(inclination)),
            distance * cos(glm::radians(inclination)) * cos(glm::radians(azimuth)),
    };
    const Vec3 focus = focused ? focused->position : Vec3(0, 0, 0);
    engine.scene.camera.look(focus);

    engine.window.clear();
    engine.scene.draw();
    engine.window.refresh();
}

void Editor::add(const std::shared_ptr<Object> &object) const {
    engine.scene.objects.push_back(object);
    list->items.emplace_back("Cube");
}
