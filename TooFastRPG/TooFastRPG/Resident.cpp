#include "Resident.h"

void Resident::update()
{
    // 일정 간격으로 주민이 이동함
    x += directionX;
    y += directionY;

    // 맵의 경계를 넘을 경우 방향을 반대로 전환
    if (x <= 0 || x >= 9) directionX *= -1;
    if (y <= 0 || y >= 9) directionY *= -1;
}

void Resident::render()
{
    // 주민 위치에 'R'을 표시
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
