#pragma once

#include <functional>
#include <memory>
#include <string>

#include "glimbo/math.h"

namespace glimbo {
    struct Element {
        std::vector<std::shared_ptr<Element>> children;
        bool visible = true;

        void add(const std::shared_ptr<Element> &child) { children.push_back(child); }

        virtual void draw();

        virtual ~Element() = default;
    };

    struct Panel : Element {
        std::string title;
        Vec2 size;
        Vec2 position;
        bool closeable = true;

        void draw() override;
    };

    struct Button : Element {
        std::function<void()> callback = nullptr;
        std::string label;

        void draw() override;
    };

} // namespace glimbo
