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
    int stage;

    int moveCountX;
    int moveCountY;

public:
    Resident(shared_ptr<EventManager> em, int stg, int startX, int startY) 
        : Subject(em), stage(stg), x(startX), y(startY), isCollision(false)
    {
        directionX = (rand() % 2 == 0) ? 1 : -1;
        directionY = (rand() % 2 == 0) ? 1 : -1;
        moveCountX = rand() % (stage * RESIDENTRANDOM);
        moveCountY = rand() % (stage * RESIDENTRANDOM);
    }

    void Update(vector<vector<int>> v);

    void Render();

    int getX() { return x; }
    int getY() { return y; }


    void Move(vector<vector<int>> v);
};

