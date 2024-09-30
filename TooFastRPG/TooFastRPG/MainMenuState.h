#pragma once
#include "GameState.h"
#include "stdafx.h"

class MainMenuState : public State
{
private:
    vector<vector<string>> frontBuffer = {};
    vector<vector<string>> backBuffer = {};
public:
    void HandleInput() override;
    void Update() override;

    void Render() override;

    void DrawSceneToBackBuffer();
};

