#pragma once
#include "GameState.h"
#include "stdafx.h"

class MainMenuState : public State
{
public:
    void handleInput() override;
    void update() override;

    void render() override;
};

