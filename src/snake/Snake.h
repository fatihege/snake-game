#pragma once

#include <mutex>
#include <vector>

#include "../utils/Config.h"

class Snake {
    std::vector<std::pair<int, int> > body;
    Direction currentDirection = Direction::NONE;

public:
    explicit Snake(const std::vector<std::pair<int, int> > &body): body(body) {
    }

    void move(const Direction &direction);

    [[nodiscard]] bool checkFood(const std::pair<int, int> &position) const;

    void grow(bool special);

    bool checkBoundaryCollision() const;

    bool checkBodyCollision() const;

    [[nodiscard]] const std::vector<std::pair<int, int> > &getBody() const;
};
