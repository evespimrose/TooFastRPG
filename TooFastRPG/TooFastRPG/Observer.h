#pragma once

class Observer 
{
public:
    virtual void OnNotify(Socket s) = 0;
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

    void Notify(Socket s)
    {
        for (Observer* observer : observers) 
        {
            observer->OnNotify(s);
        }
    }

};
