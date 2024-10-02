#include "Hero.h"

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

    if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
    {
        prevCall = Call::ResidentCollision;
    }

    if (hide_Up && hide_Down && hide_Left && hide_Right)
    {

        isHide = true;
    }  
}

void Hero::Update(vector<vector<int>>& v)
{
    if (isHide && canHide > 0)
    {
        v[y][x] = 1;
        canHide = canHide - ((double)100 / (double)60);
        isHide = false;
    }
    if (canHide <= 0)
        canHide = 0;
}

void Hero::Render()
{
    if(!isCollision)
        cout << "Hero at (" << x << ", " << y << ")                           \n";
    else
        cout << "충돌! Hero: (" << x << ", " << y << ")                        \n";

    cout << "은신 잔여 게이지 : " << fixed << canHide / (double)10 << " %                              \n";
    cout << "holy : " << holy << "                                                            \n";
    cout << "Hero State : ";
    switch (prevCall)
    {
    case Call::None:
        cout << "None\n";
        break;
    case Call::EnterGameState:
        cout << "EnterGameState\n";

        break;
    case Call::EnterMainMenuState:
        cout << "EnterMainMenuState\n";

        break;
    case Call::PendantCollision:
        cout << "PendantCollision\n";

        break;
    case Call::ResidentCollision:
        cout << "ResidentCollision\n";

        break;
    case Call::PortalCollision:
        cout << "PortalCollision\n";

        break;
    default:
        break;
    }
}

void Hero::OnNotify(Socket s)
{
    if (s.call != Call::None)
    {
        if (s.call == Call::EnterGameState) int a = 0;
        else if (s.call == Call::ResidentCollision && x == s.x && y == s.y)
        {
            isCollision = x == s.x && y == s.y ? true : false;
            prevCall = x == s.x && y == s.y ? Call::ResidentCollision : Call::None;
        }
        else if (s.call == Call::PendantCollision && x == s.x && y == s.y)
        {
            holy += x == s.x && y == s.y ? 1 : 0;
            prevCall = Call::PendantCollision;
        }
        else if (s.call == Call::PortalCollision && x == s.x && y == s.y)
        {
            prevCall = Call::PortalCollision;
        }


    }
    /*switch (s.call)
    {
    case Call::None:
        break;
    case Call::EnterGameState:
        break;
    case Call::ResidentCollision:
        isCollision = x == s.x && y == s.y ? true : false;
        prevCall = Call::ResidentCollision;
        break;
    case Call::PendantCollision:
        holy += x == s.x && y == s.y ? 1 : 0;
        prevCall = Call::PendantCollision;
        break;
    case Call::PortalCollision:

        break;
    default:
        break;
    }*/
}

bool Hero::CanHeroMove(vector<vector<int>> m, int d)
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
