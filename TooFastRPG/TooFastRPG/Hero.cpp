#include "Hero.h"
#include "GameConfig.h"

void Hero::HandleInput(vector<vector<int>> m)
{
    // _getch()
    //int ch = GetCommand();
    if (GetAsyncKeyState(VK_UP) & 0x8000) 
    {
        hide_Up = false;
        isHide = false;
        if(CanHeroMove(m, ARROW_UP)) 
            y--;
    }
    else
        hide_Up = true;

    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        hide_Down = false;
        isHide = false;
        if (CanHeroMove(m, ARROW_DOWN)) 
            y++;
    }
    else
        hide_Down = true;

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        hide_Left = false;
        isHide = false;

        if (CanHeroMove(m, ARROW_LEFT)) 
            x--;
    }
    else
        hide_Left = true;

    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        hide_Right = false;
        isHide = false;

        if (CanHeroMove(m, ARROW_RIGHT)) 
            x++;
    }
    else
        hide_Right = true;

    if (GetAsyncKeyState(GameConfig::PORTAL_KEY) & 0x8000)
        prevCall = Call::PortalCollision;

    if (hide_Up && hide_Down && hide_Left && hide_Right)
        isHide = true;
}

void Hero::Update()
{
    if (isHide && canHide > 0)
        canHide -= GameConfig::HIDE_DECREASE_RATE;

    if (canHide <= 0) 
        canHide = 0;
}

void Hero::Render()
{
    cout << "은신 잔여 게이지 : " << fixed << canHide / (double)10 << " %                                 \n"; 
    cout << "배리어 : " << holy << "개                                                                \n";
}

void Hero::OnNotify(const Socket& data)
{
    if (data.call != Call::None)
    {
        if (data.call == Call::EnterGameState) 
            int a = 0;
        else if (data.call == Call::ResidentCollision && x == data.x && y == data.y)
        {
            isCollision = x == data.x && y == data.y ? true : false;
            prevCall = x == data.x && y == data.y ? Call::ResidentCollision : Call::None;
        }
        else if (data.call == Call::PendantCollision && x == data.x && y == data.y)
        {
            holy++;
            prevCall = Call::PendantCollision;
        }
        else if (data.call == Call::PortalCollision && x == data.x && y == data.y)
            prevCall = Call::PortalCollision;
    }
}

bool Hero::CanHeroMove(vector<vector<int>> m, int d) const
{
    switch (d)
    {
    case ARROW_UP:
        if (m[y - 1][x] == 1)
            return false;
        break;
    case ARROW_DOWN:
        if (m[y + 1][x] == 1)
            return false;
        break;
    case ARROW_LEFT:
        if (m[y][x - 1] == 1)
            return false;
        break;
    case ARROW_RIGHT:
        if (m[y][x + 1] == 1)
            return false;
        break;
    default:
        break;
    }
    return true;
}
