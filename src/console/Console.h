#pragma once

#include <windows.h>

class Console {
public:
    static void setCursorPosition(int x, int y);

    static void hideCursor();

    static void clear();

    static bool hasResized();

    static COORD getConsoleSize();
};
