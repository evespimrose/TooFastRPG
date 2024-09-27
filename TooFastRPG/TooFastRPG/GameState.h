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

public:
    GameState(Hero* hero, std::vector<Resident*> residents) : hero(hero), residents(residents) {}

    void handleInput() override;

    void update() override;

    void render() override;

};

