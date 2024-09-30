#pragma once
#include "stdafx.h"
#include "State.h"
#include "Hero.h"
#include "Resident.h"


class GameState : public State
{
private:
    Hero* hero; // ¿ë»ç °´Ã¼
    vector<Resident*> residents; // ÁÖ¹Î °´Ã¼µé

    vector<vector<char>> frontBuffer = {};
    vector<vector<char>> backBuffer = {};

public:
    GameState(int stage, Hero* hero, vector<Resident*> residents);

    void HandleInput() override;

    void Update() override;

    void Render() override;

    void DrawSceneToBackBuffer();

    void SetFrontBuffer(vector<vector<char>>& c) { frontBuffer = c; }
    void SetBackBuffer(vector<vector<char>>& c) { backBuffer = c; }


};

