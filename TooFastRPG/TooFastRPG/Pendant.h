#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "MyMap.h"

class Pendant : public Subject
{
private:
    int x, y;
    bool isCollision;
    bool isRender = true;

public:
    Pendant(int startX, int startY) : x(startX), y(startY), isCollision(false) {}

    void Update(vector<vector<int>> v);

    void Render();

    int getX() { return x; }
    int getY() { return y; }
    bool getisRender() { return isRender; }

};
