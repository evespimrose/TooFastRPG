#include "State.h"
#include <fstream>

bool State::parsingSaveFile(vector<string>& vs) 
{
    ifstream file("output.txt", ifstream::in);
    string line;
    getline(file, line);
    int num = stoi(line);
    if (num == 0) return false;
    
    for (int i = 0; i < num; ++i) {
        getline(file, line);
        vs.push_back(line);
    }
    file.close();
    return true;
}

//void State::MyCallBack() 
//{
//    cout << "Call : ";
//    switch (call) {
//        case Call::None: cout << "None\n"; break;
//        case Call::EnterGameState: cout << "EnterGameState\n"; break;
//        case Call::EnterMainMenuState: cout << "EnterMainMenuState\n"; break;
//        case Call::PendantCollision: cout << "PendantCollision\n"; break;
//        case Call::ResidentCollision: cout << "ResidentCollision\n"; break;
//        case Call::PortalCollision: cout << "PortalCollision\n"; break;
//        case Call::EnterSavedGameState: cout << "EnterSavedGameState\n"; break;
//        case Call::EnterNextStageGameState: cout << "EnterNextStageGameState\n"; break;
//    }
//} 