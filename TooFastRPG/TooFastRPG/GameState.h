#pragma once
#include "stdafx.h"

class GameState
{
    public:
        virtual ~GameState() {}
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

