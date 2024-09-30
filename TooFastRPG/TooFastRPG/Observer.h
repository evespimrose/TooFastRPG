#pragma once
#include <vector>

class Observer 
{
public:
    virtual void OnNotify(int x, int y) = 0; // Resident�� ��ġ ������ �뺸����
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
