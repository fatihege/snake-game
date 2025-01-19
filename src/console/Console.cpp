#include "Console.h"

#include <iostream>
#include <windows.h>

namespace {
    COORD lastConsoleSize = {0, 0};
}

void Console::setCursorPosition(const int x, const int y) {
    const COORD coord = {static_cast<SHORT>(x), static_cast<SHORT>(y)};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::hideCursor() {
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    info.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void Console::clear() {
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD charsWritten;
    constexpr COORD topLeft = {0, 0};

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    const DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, topLeft, &charsWritten);

    setCursorPosition(0, 0);
}

bool Console::hasResized() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); !GetConsoleScreenBufferInfo(hConsole, &csbi))
        return false;

    if (const COORD currentSize = csbi.dwSize; currentSize.X != lastConsoleSize.X ||
        currentSize.Y != lastConsoleSize.Y) {
        lastConsoleSize = currentSize;
        return true;
    }

    return false;
}

COORD Console::getConsoleSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); GetConsoleScreenBufferInfo(hConsole, &csbi))
        return csbi.dwSize;

    return {0, 0};
}
