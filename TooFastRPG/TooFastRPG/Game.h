#pragma once
#include "stdafx.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "GameClearState.h"


class Game : public Observer
{
private:
    bool isRunning;
    State* currentState;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

public:
    Game(State* initialState) : currentState(initialState), isRunning(true) {}

    void Run();

    void Stop();

    void ChangeState(State* newState);

    void Update();

    void HandleInput();

    void OnNotify(Socket s) override {}
};

