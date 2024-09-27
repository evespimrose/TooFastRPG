#pragma once
#include "stdafx.h"
#include "State.h"
#include "Hero.h"
#include "Resident.h"


class GameState : public State
{
private:
    Hero* hero; // ¿ë»ç °´Ã¼
    std::vector<Resident*> residents; // ÁÖ¹Î °´Ã¼µé

public:
    GameState(Hero* hero, std::vector<Resident*> residents) : hero(hero), residents(residents) {}

    void handleInput() override;

    void update() override;

    void render() override;

};

