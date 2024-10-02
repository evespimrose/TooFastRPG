#include "Resident.h"

void Resident::Update(vector<vector<int>> v)
{
    int oldX = x, oldY = y;
    
    // 일정 간격으로 주민이 이동함
    Move(v);

    if (oldX != x || oldY != y)
    {
        Socket s;
        s.call = Call::ResidentCollision;
        s.x = x;
        s.y = y;
        Notify(s); // Hero에게 새로운 좌표 통보
    }
        
}

void Resident::Render()
{
}

void Resident::Move(vector<vector<int>> v)
{
    if (moveCountX > 0)
    {
        moveCountX--;

        if (v[y][x + directionX] == 1) directionX *= -1;      // 벽 및 장애물 충돌 시 방향 전환

        x += directionX;
    }
    else
        moveCountX = rand() % (stage * RESIDENTRANDOM);

    if (moveCountY > 0)
    {
        moveCountY--;

        if (v[y + directionY][x] == 1) directionY *= -1;

        y += directionY;
    }
    else
        moveCountY = rand() % (stage * RESIDENTRANDOM);
  
}



