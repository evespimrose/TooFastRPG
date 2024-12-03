#pragma once
#include "stdafx.h"
#include "State.h"
#include <memory>

class Game : public Observer
{
private:
    bool isRunning;
    unique_ptr<State> currentState;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

public:
    Game(unique_ptr<State> initialState) : currentState(move(initialState)), isRunning(true) {}

    void Run();

    void Stop();

    void ChangeState(unique_ptr<State> newState);

    void Update();

    void HandleInput();

    void OnNotify(Socket s) override {}
};

