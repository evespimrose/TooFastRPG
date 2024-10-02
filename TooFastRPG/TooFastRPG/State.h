#pragma once
#include "stdafx.h"
#include "Observer.h"

class State : public Subject
{
protected:
    Call call = Call::None;
    public:
        virtual ~State() {}
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        Call getCall() { return call; }
        void CallBack()
        {
            cout << "Call : ";
            switch (call)
            {
            case Call::None:
                cout << "None\n";
                break;
            case Call::EnterGameState:
                cout << "EnterGameState                                            \n";

                break;
            case Call::EnterMainMenuState:
                cout << "EnterMainMenuState                                        \n";

                break;
            case Call::PendantCollision:
                cout << "PendantCollision                                        \n";

                break;
            case Call::ResidentCollision:
                cout << "ResidentCollision                                        \n";

                break;
            case Call::PortalCollision:
                cout << "PortalCollision                                        \n";

                break;
            default:
                break;
            }
        }
};

