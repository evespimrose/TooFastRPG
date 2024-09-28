#pragma once
#include "stdafx.h"

class State
{
    public:
        virtual ~State() {}
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};

