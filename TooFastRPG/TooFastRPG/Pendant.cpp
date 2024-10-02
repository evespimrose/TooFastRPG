#include "Pendant.h"

void Pendant::Update()
{
    Socket s;
    s.call = Call::PendantCollision;
    s.x = x;
    s.y = y;
    Notify(s);
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
        nextx = rand() % (MAPMAXW - 2) + 1;
        nexty = rand() % (MAPMAXW - 2) + 1;
    }
    x = nextx;
    y = nexty;
}
