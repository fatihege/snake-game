#include "Game.h"
#include "../console/Console.h"
#include "../snake/Snake.h"
#include "../utils/Config.h"

#include <conio.h>
#include <iostream>

void Game::run() {
    Console::clearScreen();
    std::cout << "Hello World!\n";

    const std::vector<std::pair<int, int>> snakeBody = {{4, 5}, {5, 5}, {6, 5}};
    constexpr std::pair snakeDirection = {1, 0};
    Snake &snake = Snake::getInstance(snakeBody, snakeDirection);

    snake.grow();
    snake.move();
    snake.checkCollision({0, 0});
}

void Game::processInput() {
    if (_kbhit() && _getch() == 'q') std::cout << "Pressed Q" << std::endl;
}

void Game::update() {
}

void Game::render() {
    std::vector grid(GRID_HEIGHT, std::string(GRID_WIDTH, ' '));


}
