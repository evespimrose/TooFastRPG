#pragma once
#include <vector>

class Observer 
{
public:
    virtual void OnNotify(int x, int y) = 0; // Resident의 위치 변경을 통보받음
};

class Subject 
{
private:
    std::vector<Observer*> observers;

public:
    void AddObserver(Observer* observer) 
    {
        observers.push_back(observer);
    }

    void Notify(int x, int y) 
    {
        for (Observer* observer : observers) 
        {
            observer->OnNotify(x, y);
        }
    }
};
