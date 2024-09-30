#pragma once

enum class Call
{
    None,

    EnterGameState,

    NunCollision,
    ResidentCollision,

};

class Observer 
{
public:
    virtual void OnNotify(Call c, int x, int y) = 0;
    virtual void OnNotify(Call c, int x, int y, bool& flag) = 0;
    virtual void OnNotify(Call c) = 0;
};

class Subject 
{
private:
    vector<Observer*> observers;

public:
    void AddObserver(Observer* observer) 
    {
        observers.push_back(observer);
    }

    void Notify(Call c, int x, int y)
    {
        for (Observer* observer : observers) 
        {
            observer->OnNotify(c, x, y);
        }
    }

    void Notify(Call c, int x, int y, bool& flag)
    {
        for (Observer* observer : observers)
        {
            observer->OnNotify(c, x, y, flag);
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
