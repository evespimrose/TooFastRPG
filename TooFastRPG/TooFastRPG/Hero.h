#pragma once
#include "stdafx.h"
#include "Observer.h"

class Hero : public Observer
{
private:
    int x, y;
    bool isCollision;
    int holy;

public:
    Hero(int startX, int startY) : x(startX), y(startY), isCollision(false), holy(0) {}

    void HandleInput(int ch);

    void Update();

    void Render();

    void OnNotify(int residentX, int residentY) override;
    void OnNotify(Call c) override;

    // Getter for Hero's position
    int getX() { return x; }
    int getY() { return y; }
};

