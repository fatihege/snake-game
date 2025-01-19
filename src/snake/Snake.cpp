#include "Snake.h"

#include <iostream>
#include <ostream>

void Snake::move(const Direction &direction) {
    if (direction == Direction::NONE) return;

    for (int i = body.size() - 1; i >= 0; --i)
        if (i == 0)
            body[i] = {
                std::max(direction == Direction::LEFT || direction == Direction::RIGHT
                    ? body[i].first + (direction == Direction::LEFT ? -1 : 1)
                    : body[i].first, 0),
                std::max(direction == Direction::UP || direction == Direction::DOWN
                    ? body[i].second + (direction == Direction::UP ? -1 : 1)
                    : body[i].second, 0)
            };
        else body[i] = {std::max(body[i - 1].first, 0), std::max(body[i - 1].second, 0)};
}

bool Snake::checkFood(const std::pair<int, int> &position) const {
    return body[0].first == position.first && body[0].second == position.second;
}

void Snake::grow(const int amount) {
    std::cout << "Grew\n";
}

bool Snake::checkCollision(const std::pair<int, int> &point) {
    std::cout << "Checked collision\n";
    return false;
}

const std::vector<std::pair<int, int> > &Snake::getBody() const {
    return body;
}
