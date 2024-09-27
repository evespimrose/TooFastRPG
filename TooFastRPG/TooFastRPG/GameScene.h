#pragma once
#include "stdafx.h"
#include "Scene.h"
#include "Hero.h"
#include "Resident.h"


class GameScene : public Scene
{
private:
    Hero* hero; // ��� ��ü
    std::vector<Resident*> residents; // �ֹ� ��ü��

public:
    GameScene(Hero* hero, std::vector<Resident*> residents) : hero(hero), residents(residents) {}

    void handleInput() override;

    void update() override;

    void render() override;

};

