#pragma once
#include "stdafx.h"
#include "Observer.h"

class Hero : public Observer
{
private:
    int x, y; // ����� ���� ��ġ
    bool isCollision;
    int holy;

public:
    Hero(int startX, int startY) : x(startX), y(startY), isCollision(false), holy(0) {}

    void HandleInput();

    void Update();

    void Render();

    void OnNotify(int residentX, int residentY) override;

    // Getter for Hero's position
    int getX() { return x; }
    int getY() { return y; }
};

