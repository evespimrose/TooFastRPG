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

    double canHide;
    Call prevCall = Call::None;

public:
    Hero(int startX, int startY) : x(startX), y(startY), isCollision(false), holy(0), isHide(true), canHide(0) {}
    Hero(int startX, int startY, int h) : x(startX), y(startY), isCollision(false), holy(0), isHide(true), canHide(h) {}

    void HandleInput(vector<vector<int>> m);

    void Update(vector<vector<int>>& v);

    void Render();

    void OnNotify(Socket s) override;
    void SetHide(double i) { canHide = i; }
    void SetPrevCall(Call c) { prevCall = c; }

    int getX() { return x; }
    int getY() { return y; }
    bool getHide() { return isHide; }
    bool getCanHide() { return canHide; }
    Call getPrevCall() { return prevCall; }

    bool CanHeroMove(vector<vector<int>> m, int d);

};

