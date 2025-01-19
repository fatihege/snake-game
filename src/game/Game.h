#pragma once

#include "../snake/Snake.h"
#include "../utils/Config.h"

class Game {
public:
    void run();

private:
    std::unique_ptr<Snake> snake = nullptr;
    Direction direction = Direction::NONE;
    bool isGameOver = false;

    void processInput();

    void update();

    void render();
};
