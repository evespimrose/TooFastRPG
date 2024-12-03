#pragma once
#include "stdafx.h"
#include "State.h"
#include <memory>

class Game : public Observer
{
private:
    bool isRunning;
    unique_ptr<State> currentState;
    shared_ptr<EventManager> eventManager;
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

public:
    Game(unique_ptr<State> initialState) : eventManager(make_shared<EventManager>()), currentState(move(initialState)), isRunning(true)
    {
        eventManager->Subscribe(EventType::StateChange, weak_from_this());
    }

    void Run();

    void Stop();

    void ChangeState(unique_ptr<State> newState);

    void Update();

    void HandleInput();

    void OnNotify(const Socket& data) override {}

    string GetObserverName() const override { return "Game"; }

    shared_ptr<EventManager> GetEventManager() const { return eventManager; }
};

