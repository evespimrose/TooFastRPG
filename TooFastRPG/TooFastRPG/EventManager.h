#pragma once
#include "stdafx.h"  // Socket 구조체가 여기 있음
#include <map>
#include <vector>
#include <memory>

class Observer;  // 전방 선언

enum class EventType {
    Collision,
    StateChange,
    GameOver,
};

class EventManager {
private:
    map<EventType, vector<weak_ptr<Observer>>> observers;

public:
    void Subscribe(EventType type, weak_ptr<Observer> observer)
    {
        observers[type].push_back(observer);
    }


    void Notify(EventType type, const Socket& data);  // 선언만 남기고
}; 