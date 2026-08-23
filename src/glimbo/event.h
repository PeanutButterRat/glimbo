#pragma once

#include <functional>

namespace glimbo {
    template<typename... Args>
    struct Event {
        using Callback = std::function<void(Args...)>;

        void connect(const Callback &callback) { callbacks.push_back(callback); }

        void handle(Args... args) const {
            for (const auto &callback: callbacks) {
                callback(args...);
            }
        }

    private:
        std::vector<Callback> callbacks;
    };
} // namespace glimbo
