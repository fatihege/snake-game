#include "Console.h"

#include <iostream>
#include <windows.h>
#include <conio.h>

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

void Console::clearScreen() {
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
