#include "Pendant.h"

void Pendant::Update()
{
    Socket data{Call::PendantCollision, x, y};
    NotifyEvent(EventType::Collision, data);
}

void Pendant::Render()
{
}

void Pendant::Move(vector<vector<int>> v)
{
    int nextx = 0;
    int nexty = 0;
    while (v[nextx][nexty] != 0)
    {
        nextx = rand() % (MAPMAXW - 3) + 1;
        nexty = rand() % (MAPMAXW - 3) + 1;
    }
    x = nextx;
    y = nexty;
}
