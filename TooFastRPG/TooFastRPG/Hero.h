#pragma once
#include "stdafx.h"

class Hero
{
private:
    int x, y; // ����� ���� ��ġ

public:
    Hero(int startX, int startY) : x(startX), y(startY) {}

    void handleInput();

    void update();

    void render();

    // Getter for Hero's position
    int getX() { return x; }
    int getY() { return y; }
};

