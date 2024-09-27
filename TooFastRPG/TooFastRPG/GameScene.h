#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Hero.h"
#include "Resident.h"


class GameScene : public Scene
{
private:
    Hero* hero; // ¿ë»ç °´Ã¼
    std::vector<Resident*> residents; // ÁÖ¹Î °´Ã¼µé

public:
    GameScene(Hero* hero, std::vector<Resident*> residents) : hero(hero), residents(residents) {}

    void handleInput() override;

    void update() override;

    void render() override;

};

