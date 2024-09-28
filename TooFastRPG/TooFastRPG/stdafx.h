#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

#include <vector>

#include <cstdlib>
#include <ctime>
#include <random>
#include <Windows.h>
using namespace std;

#define MAPMAXW 40
#define MAPMAXH 40

inline int GetCommand() {
    if (_kbhit()) {
        return _getch();
    }

    return -1;
}

inline void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}