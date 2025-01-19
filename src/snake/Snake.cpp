#include "Snake.h"

void Snake::move(const Direction &direction) {
    if (
        direction != Direction::NONE &&
        (currentDirection != Direction::UP || direction != Direction::DOWN) &&
        (currentDirection != Direction::DOWN || direction != Direction::UP) &&
        (currentDirection != Direction::LEFT || direction != Direction::RIGHT) &&
        (currentDirection != Direction::RIGHT || direction != Direction::LEFT)
    )
        currentDirection = direction;

    for (size_t i = body.size(); i-- > 0;)
        if (i == 0)
            body[i] = {
                std::max(currentDirection == Direction::LEFT || currentDirection == Direction::RIGHT
                             ? body[i].first + (currentDirection == Direction::LEFT ? -1 : 1)
                             : body[i].first, 0),
                std::max(currentDirection == Direction::UP || currentDirection == Direction::DOWN
                             ? body[i].second + (currentDirection == Direction::UP ? -1 : 1)
                             : body[i].second, 0)
            };
        else body[i] = {std::max(body[i - 1].first, 0), std::max(body[i - 1].second, 0)};
}

bool Snake::checkFood(const std::pair<int, int> &position) const {
    return body.front() == position;
}

void Snake::grow(const bool special) {
    for (short i = 0; i < (special ? 2 : 1); ++i) body.push_back(body.back());
}

bool Snake::checkBoundaryCollision() const {
    return body.front().first == 0 || body.front().first == GRID_WIDTH + 1 ||
           body.front().second == 0 || body.front().second == GRID_HEIGHT + 1;
}

bool Snake::checkBodyCollision() const {
    if (currentDirection == Direction::NONE) return true;

    const auto &head = body.front();
    bool collision = false;

    for (size_t i = 1; i < body.size(); ++i) if (head == body[i]) collision = true;

    return collision;
}

const std::vector<std::pair<int, int> > &Snake::getBody() const {
    return body;
}
