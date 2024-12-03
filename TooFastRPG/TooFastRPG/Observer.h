#pragma once
#include "stdafx.h"
#include <memory>
#include "EventManager.h"

class GameState;  // 전방 선언

// 옵저버 인터페이스
class Observer : public std::enable_shared_from_this<Observer> 
{
public:
    virtual ~Observer() = default;
    virtual void OnNotify(const Socket& data) = 0;
    virtual string GetObserverName() const = 0;
    virtual bool IsActive() const { return true; }

protected:
    void RegisterToEvent(EventType type, EventManager& eventManager) 
    {
        eventManager.Subscribe(type, weak_from_this());
    }

    friend class GameState;  // GameState에서 RegisterToEvent 접근 허용
    friend class Subject;
};

class Subject 
{
private:
    shared_ptr<EventManager> eventManager;

public:
    Subject(shared_ptr<EventManager> em) : eventManager(em) {}
    virtual ~Subject() = default;

    void RegisterObserver(Observer* observer, EventType type) 
    {
        observer->RegisterToEvent(type, *eventManager);
    }

    void NotifyEvent(EventType type, const Socket& data) 
    {
        eventManager->Notify(type, data);
    }
};
