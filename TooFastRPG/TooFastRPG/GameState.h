#pragma once
#include "stdafx.h"
#include "State.h"
#include "Hero.h"
#include "Resident.h"


class GameState : public State
{
private:
    Hero* hero;
    vector<Resident*> residents;

    vector<vector<string>> frontBuffer = {};
    vector<vector<string>> backBuffer = {};
    vector<vector<int>> mapBuffer = {};

public:
    GameState(int stage, Hero* hero, vector<Resident*> residents);

    void HandleInput() override;

    void Update() override;

    void Render() override;

    void DrawSceneToBackBuffer();

    void SetFrontBuffer(vector<vector<string>>& c) { frontBuffer = c; }
    void SetBackBuffer(vector<vector<string>>& c) { backBuffer = c; }

    void SetMapBuffer(vector<vector<int>>& i) { mapBuffer = i; }

    bool CanHeroMove();
};

