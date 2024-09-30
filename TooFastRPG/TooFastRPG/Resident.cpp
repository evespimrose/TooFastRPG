#include "Resident.h"

void Resident::Update(vector<vector<int>> v)
{
    int oldX = x, oldY = y;
    
    // 일정 간격으로 주민이 이동함
    Move(v);

    if (oldX != x || oldY != y) 
        Notify(x, y); // Hero에게 새로운 좌표 통보
}

void Resident::Render()
{
    std::cout << "Resident at (" << x << ", " << y << "), moveCount : " << moveCountX << ", " << moveCountY << "                                    \n";
}

void Resident::Move(vector<vector<int>> v)
{
    if (moveCountX > 0)
    {
        moveCountX--;

        if (x <= 1 || x >= MAPMAXW - 2 || v[y][x + directionX] == 1) directionX *= -1;

        x += directionX;
    }
    else
        moveCountX = rand() % 15;

    if (moveCountY > 0)
    {
        moveCountY--;

        if (y <= 1 || y >= MAPMAXW - 2 || v[y + directionY][x] == 1) directionY *= -1;

        y += directionY;
    }
    else
        moveCountY = rand() % 15;
  
}



