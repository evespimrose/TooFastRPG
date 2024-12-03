#include "EventManager.h"
#include "Observer.h"

void EventManager::Notify(EventType type, const Socket& data) 
{
    for (auto it = observers[type].begin(); it != observers[type].end();) 
    {
        if (auto observer = it->lock()) 
        {
            observer->OnNotify(data);
            ++it;
        } 
        else 
        {
            it = observers[type].erase(it);
        }
    }
}
