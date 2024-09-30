#pragma once
#include <vector>

class Observer 
{
public:
    virtual void OnNotify(int x, int y) = 0;
    virtual void OnNotify(Call c) = 0;
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

    void Notify(Call c)
    {
        for (Observer* observer : observers)
        {
            observer->OnNotify(c);
        }
    }
};
