#pragma once
#include "stdafx.h"
#include "State.h"
#include "Hero.h"
#include "Resident.h"


class GameState : public State
{
private:
    Hero* hero; // ��� ��ü
    std::vector<Resident*> residents; // �ֹ� ��ü��

    vector<char> frontBuffer = {};
    vector<char> backBuffer = {};

public:
    GameState(int stage, Hero* hero, vector<Resident*> residents);

    void HandleInput() override;

    void Update() override;

    void Render() override;

    void DrawSceneToBackBuffer();

};

