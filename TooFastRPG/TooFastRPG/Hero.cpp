#include "Hero.h"

void Hero::handleInput()
{

    // _getch() 메소드를 사용해 화살표 키 입력 처리
    int ch = getCommand();
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

void Hero::update()
{

}

void Hero::render()
{

}
