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
#include "GameConfig.h"

using namespace std;

#define ARROW GameConfig::Instance().ARROW
#define MAPMAXW GameConfig::Instance().MAP_MAX_W
#define MAPMAXH GameConfig::Instance().MAP_MAX_H
#define RESIDENTRANDOM GameConfig::Instance().RESIDENT_RANDOM

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
