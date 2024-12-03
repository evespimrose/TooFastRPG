#include "Portal.h"

void Portal::Update()
{
    Socket data{Call::PortalCollision, x, y};
    NotifyEvent(EventType::Collision, data);
}

void Portal::Render()
{
}
