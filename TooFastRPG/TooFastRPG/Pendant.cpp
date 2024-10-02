#include "Pendant.h"

void Pendant::Update(vector<vector<int>> v)
{
    Socket s;
    s.call = Call::PendantCollision;
    s.x = x;
    s.y = y;
    Notify(s);
}

void Pendant::Render()
{
    std::cout << "Nun at (" << x << ", " << y << "), chasity : " << isRender << "                                  \n";
}