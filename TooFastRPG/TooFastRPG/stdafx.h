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
#define ARROW 224

enum
{
    ARROW_UP = 72,
    ARROW_DOWN = 80,
    ARROW_LEFT = 75,
    ARROW_RIGHT = 77
};

enum class Call
{

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

/*
    주민, 용사가 각각 Map에 놓인 벽과 장애물에 부딪히면 못가거나 방향전환이 되야됨.
    인코딩 오류 해결할 것. 왜안되지?     해결. 일단 컴퓨터 설정까지 바꿔버렸지만 뭐..어떻게든 되겠지
    Stage마다 다르게 Map 제작할것.
    여신 어쩌구 펜던트 만들것. 기왕이면 Item 클래스로 만들어서 맵에 뿌리자. Subject 붙이는거 잊지말고. 이걸 뿌려주는 주민처럼 움직이는 Nun클래스?



*/