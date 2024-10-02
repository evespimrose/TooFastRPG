
#include "Portal.h"

void Portal::Update(vector<vector<int>> v)
{
    Socket s;
    s.call = Call::PortalCollision;
    s.x = x;
    s.y = y;
    Notify(s);
}

void Portal::Render()
{
}
