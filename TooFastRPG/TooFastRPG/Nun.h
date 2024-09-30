#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "MyMap.h"

class Nun : public Subject
{
private:
    int x, y;
    int directionX, directionY;
    bool isCollision;
    int stage;

public:
    Nun(int stg, int startX, int startY) : stage(stg), x(startX), y(startY), isCollision(false)
    {
        directionX = (rand() % 2 == 0) ? 1 : -1;
        directionY = 0;
    }

    void Update(vector<vector<int>> v);

    void Render();

    int getX() { return x; }
    int getY() { return y; }


    void Move(vector<vector<int>> v);
};
