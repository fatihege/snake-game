#include "Game.h"
#include "../console/Console.h"
#include "../utils/Config.h"
#include "../snake/Snake.h"

#include <conio.h>
#include <iostream>
#include <windows.h>

void Game::run() {
    Console::clear();

    const std::vector<std::pair<int, int> > body = {{4, 5}, {5, 5}, {6, 5}};
    snake = std::make_unique<Snake>(body);

    while (!isGameOver) {
        render();
        processInput();
        update();
        Sleep(FRAME_DELAY);
    }
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
    snake->move(direction);
}

void Game::render() {
    Console::clear();

    auto printHorizontalLine = [] {
        for (int i = 0; i < GRID_WIDTH + 2; ++i) std::cout << (i == 0 || i == GRID_WIDTH + 1 ? '+' : '-');
        std::cout << '\n';
    };

    printHorizontalLine();
    Console::setCursorPosition(0, GRID_HEIGHT + 1);
    printHorizontalLine();

    for (int i = 0; i < GRID_HEIGHT; ++i) {
        Console::setCursorPosition(0, i + 1);
        std::cout << '|';
        Console::setCursorPosition(GRID_WIDTH + 1, i + 1);
        std::cout << '|';
    }

    for (const auto &[x, y]: snake->getBody()) {
        Console::setCursorPosition(x, y + 1);
        std::cout << 'O';
    }

    Console::setCursorPosition(0, GRID_HEIGHT + 2);
}
