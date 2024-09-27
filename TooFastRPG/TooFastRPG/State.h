#pragma once
#include "stdafx.h"

class State
{
    public:
        virtual ~State() {}
        virtual void handleInput() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
};

