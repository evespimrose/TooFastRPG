#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <fstream>
#include <map>

#include "json/json.h"

using namespace std;

#define MAPMAXW 40
#define MAPMAXH 40
#define ARROW 224
#define RESIDENTRANDOM 4

enum
{
    ARROW_UP,
    ARROW_DOWN,
    ARROW_LEFT,
    ARROW_RIGHT
};

inline int GetCommand() 
{
    int nkey = -1;
    if (_kbhit()) 
    {
        nkey = _getch(); //방향키의 경우 nkey값은 224
        if (nkey == ARROW)
        {
            nkey = _getch();
        }
    }
    return nkey;
}

inline void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

enum class Call
{
    None,

    EnterGameState,
    EnterSavedGameState,
    EnterMainMenuState,
    EnterNextStageGameState,

    PendantCollision,
    ResidentCollision,
    PortalCollision
};

extern struct Socket
{
    Call call = Call::None;
    int x = 0;
    int y = 0;
    bool flag = false;
};
