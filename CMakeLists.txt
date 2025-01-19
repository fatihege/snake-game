cmake_minimum_required(VERSION 3.30)
project(snake_game)

set(CMAKE_CXX_STANDARD 20)

add_executable(snake_game main.cpp
        src/console/Console.cpp
        src/console/Console.h
        src/food/Food.cpp
        src/food/Food.h
        src/game/Game.cpp
        src/game/Game.h
        src/snake/Snake.cpp
        src/snake/Snake.h
        src/utils/Config.h
        src/utils/Utility.cpp
        src/utils/Utility.h
)
