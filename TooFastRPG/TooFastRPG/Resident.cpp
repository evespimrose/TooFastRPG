#include "Resident.h"

void Resident::Update()
{
    int oldX = x, oldY = y;
    
    // 일정 간격으로 주민이 이동함
    x += directionX;
    y += directionY;

    // 맵의 경계를 넘을 경우 방향을 반대로 전환
    if (x <= 0 || x >= MAPMAXW - 1) directionX *= -1;
    if (y <= 0 || y >= MAPMAXW - 1) directionY *= -1;

    if (oldX != x || oldY != y) 
        Notify(x, y); // Hero에게 새로운 좌표 통보
}

void Resident::Render()
{
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
