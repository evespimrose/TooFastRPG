#pragma once
#include "stdafx.h"
#include "Observer.h"

class Portal : public Subject
{
private:
    int x, y;
    bool isCollision;
    bool isRender = true;

public:
    Portal(int startX, int startY) : x(startX), y(startY), isCollision(false) {}

    void Update(vector<vector<int>> v);

    void Render();

    int getX() { return x; }
    int getY() { return y; }
    bool getisRender() { return isRender; }
};

