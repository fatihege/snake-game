#pragma once

#include <utility>

class Food {
    std::pair<int, int> position = {0, 0};
    bool special = false;

public:
    Food();

    void refresh();

    [[nodiscard]] std::pair<int, int> getPosition() const;

    [[nodiscard]] bool isSpecial() const;
};
