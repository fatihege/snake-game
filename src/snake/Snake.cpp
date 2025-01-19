#include "Snake.h"

#include <iostream>
#include <ostream>

void Snake::move(const Direction &direction) {
    if (direction == Direction::NONE) return;

    for (int i = body.size() - 1; i >= 0; --i)
        if (i == 0)
            body[i] = {
                direction == Direction::LEFT || direction == Direction::RIGHT
                    ? body[i].first + (direction == Direction::LEFT ? -1 : 1)
                    : body[i].first,
                direction == Direction::UP || direction == Direction::DOWN
                    ? body[i].second + (direction == Direction::UP ? -1 : 1)
                    : body[i].second
            };
        else body[i] = {body[i - 1].first, body[i - 1].second};
}

void Snake::grow() {
    std::cout << "Grew\n";
}

bool Snake::checkCollision(const std::pair<int, int> &point) {
    std::cout << "Checked collision\n";
    return false;
}

const std::vector<std::pair<int, int> > &Snake::getBody() const {
    return body;
}
