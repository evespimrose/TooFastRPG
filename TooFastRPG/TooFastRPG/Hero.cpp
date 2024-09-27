#include "Hero.h"

void Hero::handleInput()
{
    // _getch() 메소드를 사용해 화살표 키 입력 처리
    int ch = _getch();
    switch (ch) {
    case 72: // 위쪽 화살표
        y--;
        break;
    case 80: // 아래쪽 화살표
        y++;
        break;
    case 75: // 왼쪽 화살표
        x--;
        break;
    case 77: // 오른쪽 화살표
        x++;
        break;
    }
}

void Hero::update()
{

}

void Hero::render()
{
    // 용사의 위치에 'H'를 표시
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == y && j == x) {
                std::cout << 'H'; // 용사 위치
            }
            else {
                std::cout << '.'; // 빈 공간
            }
        }
        std::cout << std::endl;
    }
}
