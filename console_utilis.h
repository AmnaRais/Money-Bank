#ifndef CONSOLE_UTILIS_H
#define CONSOLE_UTILIS_H

#include <windows.h>

inline void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#endif
