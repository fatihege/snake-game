#pragma once

constexpr int GRID_WIDTH = 80;
constexpr int GRID_HEIGHT = 40;
constexpr int FRAME_DELAY = 100;

enum class Direction {
    NONE = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};