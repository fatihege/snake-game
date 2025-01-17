#include "Game.h"
#include "../console/Console.h"
#include "../utils/Config.h"
#include "../snake/Snake.h"
#include "../utils/Utility.h"

#include <conio.h>
#include <iostream>
#include <windows.h>

void Game::run() {
    Console::clear();

    const std::pair randomPosition = {Utility::randomNumber(3, GRID_WIDTH - 2), Utility::randomNumber(3, GRID_HEIGHT - 2)};
    const std::vector body = {randomPosition, {5, randomPosition.second}, {6, randomPosition.second}};
    snake = std::make_unique<Snake>(body);
    food = std::make_unique<Food>();

    while (!isGameOver) {
        render();
        processInput();
        update();
        Sleep(FRAME_DELAY);
    }

    std::cout << "\nYour Score: " << snake->getBody().size() - body.size() << "\nPress Enter to exit...\n";
    std::cin.get();
}

void Game::processInput() {
    if (_kbhit()) {
        switch (static_cast<char>(_getch())) {
            case 'w':
            case 'W':
                direction = Direction::UP;
                break;
            case 's':
            case 'S':
                direction = Direction::DOWN;
                break;
            case 'a':
            case 'A':
                direction = Direction::LEFT;
                break;
            case 'd':
            case 'D':
                direction = Direction::RIGHT;
                break;
            case 'q':
            case 'Q':
                isGameOver = true;
                break;
            default: ;
        }
    }
}

void Game::update() {
    if (snake->checkBoundaryCollision() || snake->checkBodyCollision()) isGameOver = true;

    snake->move(direction);

    if (snake->checkFood(food->getPosition())) {
        snake->grow(food->isSpecial());
        food->refresh();
    }
}

void Game::render() const {
    if (Console::hasResized()) Console::clear();

    auto printHorizontalLine = [] {
        for (int i = 0; i < GRID_WIDTH + 2; ++i) std::cout << (i == 0 || i == GRID_WIDTH + 1 ? '+' : '-');
    };

    Console::setCursorPosition(0, 0);
    printHorizontalLine();

    Console::setCursorPosition(0, GRID_HEIGHT + 1);
    printHorizontalLine();

    for (int i = 0; i < GRID_HEIGHT; ++i) {
        Console::setCursorPosition(0, i + 1);
        std::cout << '|';
        Console::setCursorPosition(GRID_WIDTH + 1, i + 1);
        std::cout << '|';
    }

    Console::setCursorPosition(food->getPosition().first, food->getPosition().second);
    std::cout << (food->isSpecial() ? 'X' : 'x');

    static std::vector<std::pair<int, int> > previousBody;
    const auto &body = snake->getBody();

    for (const auto &segment: previousBody) {
        if (std::ranges::find(body, segment) == body.end()) {
            Console::setCursorPosition(segment.first, segment.second);
            std::cout << ' ';
        }
    }

    for (int i = 0; i < body.size(); ++i) {
        Console::setCursorPosition(body[i].first, body[i].second);
        std::cout << (i == 0 ? 'O' : 'o');
    }

    previousBody = body;

    Console::setCursorPosition(0, GRID_HEIGHT + 2);
}
