#pragma once
#include "GameState.h"
#include "stdafx.h"

class MainMenuState : public State
{
private:
    vector<string>* frontBuffer = {};
    vector<string>* backBuffer = {};
    

public:
    MainMenuState();
    ~MainMenuState();

    void HandleInput() override;
    void Update() override;

    void Render() override;
    void SaveFile() override {};

    void DrawSceneToBackBuffer();
    
};

