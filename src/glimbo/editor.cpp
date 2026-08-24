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
}

void Editor::update() const {
    const float dt = engine.poll();
    engine.scene.update(dt);
}
