#pragma once
#include "GameState.h"
#include "stdafx.h"

class MainMenuState : public State
{
public:
    void HandleInput() override;
    void Update() override;

    void Render() override;
};

