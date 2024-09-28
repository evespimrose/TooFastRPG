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

    vector<char> frontBuffer = {};
    vector<char> backBuffer = {};

public:
    GameState(int stage, Hero* hero, vector<Resident*> residents);

    void HandleInput() override;

    void Update() override;

    void Render() override;

    void DrawSceneToBackBuffer();

};

