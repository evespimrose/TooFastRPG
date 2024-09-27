#pragma once
#include "stdafx.h"

class Scene
{
public:
    virtual ~Scene() {}
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

};

