#include "Hero.h"

void Hero::HandleInput()
{
    // _getch() 메소드를 사용해 화살표 키 입력 처리
    int ch = GetCommand();
    switch (ch) {
    case 72: // 위쪽 화살표
        if(y > 0)
            y--;
        break;
    case 80: // 아래쪽 화살표
        if(y < MAPMAXH - 1)
            y++;
        break;
    case 75: // 왼쪽 화살표
        if(x > 0)
            x--;
        break;
    case 77: // 오른쪽 화살표
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
        std::cout << "충돌 발생! Hero: (" << x << ", " << y << ")\n";
}

void Hero::OnNotify(int residentX, int residentY)
{
    isCollision = x == residentX && y == residentY ? true : false;

}
