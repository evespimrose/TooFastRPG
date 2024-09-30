#include "Hero.h"

void Hero::HandleInput(int ch)
{
    // _getch()
    //int ch = GetCommand();

    switch (ch) 
    {
    case ARROW_UP:
        if(y > 0)
            y--;
        break;
    case ARROW_DOWN:
        if(y < MAPMAXH - 1)
            y++;
        break;
    case ARROW_LEFT:
        if(x > 0)
            x--;
        break;
    case ARROW_RIGHT:
        if (x < MAPMAXW - 1)
            x++;
        break;
    default:
        break;
    }
}

void Hero::Update()
{

}

void Hero::Render()
{
    if(!isCollision)
        std::cout << "Hero at (" << x << ", " << y << ")\n";
    else
        std::cout << "충돌! Hero: (" << x << ", " << y << ")\n";
}

void Hero::OnNotify(int residentX, int residentY)
{
    isCollision = x == residentX && y == residentY ? true : false;

}

void Hero::OnNotify(Call c)
{

}
