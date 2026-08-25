#include "editor.h"

#include "glimbo/element.h"

using namespace glimbo;

Editor::Editor(Engine &engine) : engine(engine) {
    const auto panel = std::make_shared<Panel>();
    panel->title = "Scene";
    panel->position.x = 1000;
    panel->size = {200, 800};
    panel->closeable = false;
    engine.scene.ui.add(panel);

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
    engine.scene.camera.look(focus);

    engine.window.clear();
    engine.scene.draw();
    engine.window.refresh();
}
