#pragma once
#include "stdafx.h"
#include "Observer.h"

class Hero : public Observer
{
private:
    int x, y;
    bool isCollision;
    int holy;
    bool isHide;

    bool hide_Up = true;
    bool hide_Down = true;
    bool hide_Left = true;
    bool hide_Right = true;

   

public:
    Hero(int startX, int startY) : x(startX), y(startY), isCollision(false), holy(0), isHide(true) {}

    void HandleInput(vector<vector<int>> m);

    void Update(vector<vector<int>>& v);

    void Render();

    void OnNotify(int residentX, int residentY) override;
    void OnNotify(Call c) override;

    int getX() { return x; }
    int getY() { return y; }
    bool getHide() { return isHide; }

    bool CanHeroMove(vector<vector<int>> m, int d);

};

