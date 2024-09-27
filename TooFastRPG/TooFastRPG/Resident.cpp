#include "Resident.h"

void Resident::update()
{
    int oldX = x, oldY = y;
    // 예시: 이동 처리
    // x++, y++ 또는 NPC 로직에 따라 변경

    
    // 일정 간격으로 주민이 이동함
    x += directionX;
    y += directionY;

    // 맵의 경계를 넘을 경우 방향을 반대로 전환
    if (x <= 0 || x >= MAPMAXW - 1) directionX *= -1;
    if (y <= 0 || y >= MAPMAXW - 1) directionY *= -1;

    if (oldX != x || oldY != y) 
        notify(x, y); // Hero에게 새로운 좌표 통보

}

void Resident::render()
{
    // 주민 위치에 'R'을 표시
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
