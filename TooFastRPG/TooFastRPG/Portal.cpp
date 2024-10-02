#include "Portal.h"

void Portal::Update()
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
