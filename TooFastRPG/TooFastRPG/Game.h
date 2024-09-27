#pragma once
#include "stdafx.h"
#include "GameState.h"

class Game
{
private:
    bool isRunning;
    State* currentState;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

public:
    Game(State* initialState) : currentState(initialState), isRunning(true) {}

    void run();

    void stop();

    void changeState(State* newState);
};

