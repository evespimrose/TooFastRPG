#pragma once
#include "State.h"

class MainMenuState : public State
{
private:
    vector<string> frontBuffer;
    vector<string> backBuffer;
    

public:
    MainMenuState() 
    {
        system("cls");
        frontBuffer.resize(1);
        backBuffer.resize(1);
    }
    ~MainMenuState();

    void HandleInput() override;
    void Update() override;

    void Render() override;
    void SaveFile() override {};

    void DrawSceneToBackBuffer();
    
};

