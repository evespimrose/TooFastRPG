#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "MyMap.h"

class Resident : public Subject
{
private:
    int x, y; 
    int directionX, directionY; 
    bool isCollision;

public:
    Resident(int startX, int startY) : x(startX), y(startY), isCollision(false)
    {
        directionX = (rand() % 2 == 0) ? 1 : -1;
        directionY = (rand() % 2 == 0) ? 1 : -1;
    }

    void Update();

    void Render();

    int getX() { return x; }
    int getY() { return y; }


    void Move();
};

