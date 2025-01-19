#pragma once

#include "../snake/Snake.h"
#include "../food/Food.h"
#include "../utils/Config.h"

class Game {
public:
    void run();

private:
    std::unique_ptr<Snake> snake = nullptr;
    std::unique_ptr<Food> food = nullptr;
    Direction direction = Direction::NONE;
    bool isGameOver = false;

    void processInput();

    void update();

    void render() const;
};
