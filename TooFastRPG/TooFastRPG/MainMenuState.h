#pragma once
#include "State.h"
#include <memory>

class MainMenuState : public State
{
private:
    vector<string> frontBuffer;
    vector<string> backBuffer;
    

public:
    MainMenuState(shared_ptr<EventManager> em = nullptr);
    ~MainMenuState();

    void HandleInput() override;
    void Update() override;

    void Render() override;
    void SaveFile() override {};

    void DrawSceneToBackBuffer();
    
};

