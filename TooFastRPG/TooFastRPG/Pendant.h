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
    Pendant(shared_ptr<EventManager> em, int startX, int startY) : Subject(em), x(startX), y(startY), isCollision(false) {}

    void Update();

    void Render();

    int getX() { return x; }
    int getY() { return y; }
    bool getisRender() { return isRender; }

    void Move(vector<vector<int>> v);
};
