#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "Hero.h"
#include "Resident.h"
#include "Pendant.h"
#include "Portal.h"


extern struct GameFile
{
    int stage = {};
    Hero* h = {};
};

class State : public Subject
{
protected:
    Call call = Call::None;
    vector<string> vs = {};
    int stage = {};
    GameFile gamefile = {};

    public:
        virtual ~State() {}
        virtual void HandleInput() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;

        void SetStage(int i) { stage = i; }

        Call getCall() { return call; }
        int getStage() { return stage; }
        GameFile getGameFile() { return gamefile; }

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
            case Call::EnterSavedGameState:
                cout << "EnterSavedGameState                                        \n";

                break;
            case Call::EnterNextStageGameState:
                cout << "EnterNextStageGameState                                        \n";

                break;
            default:
                break;
            }
        }

        bool parsingSaveFile(vector<string>& vs)
        {
            ifstream file;

            file.open("output.txt", ifstream::in);

            string line;
            getline(file, line);

            int num = stoi(line);

            if (num == 0)
            {
                return false;
            }


            for (int i = 0; i < num; ++i)
            {
                getline(file, line);
                vs.push_back(line);
            }

            file.close();
            return true;
        }

        virtual void SaveFile() = 0;

        vector<string> getFile() { return vs; }
};

