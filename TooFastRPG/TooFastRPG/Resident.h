#pragma once
#include "stdafx.h"

class Resident
{
private:
    int x, y; // 주민의 현재 위치
    int directionX, directionY; // 이동 방향 (1 또는 -1)

public:
    Resident(int startX, int startY) : x(startX), y(startY) 
    {
        directionX = (rand() % 2 == 0) ? 1 : -1;
        directionY = (rand() % 2 == 0) ? 1 : -1;
    }

    void update();

    void render();

    int getX() { return x; }
    int getY() { return y; }
};

