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
    GameState(Hero* hero, std::vector<Resident*> residents) : frontBuffer(MAPMAXW* MAPMAXH, ' '), backBuffer(MAPMAXW* MAPMAXH, ' '), hero(hero), residents(residents) {}

    void handleInput() override;

    void update() override;

    void render() override;

    void drawSceneToBackBuffer();

};

