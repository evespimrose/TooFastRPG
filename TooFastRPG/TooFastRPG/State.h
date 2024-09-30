#pragma once
#include "stdafx.h"
#include "Observer.h"

class State : public Subject
{
    public:
        virtual ~State() {}
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        
};

