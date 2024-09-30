#include "Nun.h"

void Nun::Update(vector<vector<int>> v)
{
    int oldX = x, oldY = y;

    Move(v);

    if (oldX != x || oldY != y)
        Notify(x, y);
}

void Nun::Render()
{
    std::cout << "Nun at (" << x << ", " << y << ")                                  \n";
}

void Nun::Move(vector<vector<int>> v)
{
    if (v[y][x + directionX] == 1) directionX *= -1;      // 벽 및 장애물 충돌 시 방향 전환

    x += directionX;

}