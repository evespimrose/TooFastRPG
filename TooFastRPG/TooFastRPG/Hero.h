#pragma once
#include "stdafx.h"
#include "Observer.h"

class Hero : public Observer
{
private:
    int x, y; // 용사의 현재 위치
    bool isCollision;

public:
    Hero(int startX, int startY) : x(startX), y(startY), isCollision(false) {}

    void handleInput();

    void update();

    void render();

    void onNotify(int residentX, int residentY) override;

    // Getter for Hero's position
    int getX() { return x; }
    int getY() { return y; }
};

