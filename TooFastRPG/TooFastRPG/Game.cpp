#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"


void Game::Run()
{
    while (isRunning) {
        auto frameStart = chrono::high_resolution_clock::now();

        // 1. 입력 처리
        currentState->HandleInput();

        // 2. 게임 상태 업데이트
        Update();

        // 3. 화면 렌더링 (이중 버퍼링 활용)
        currentState->Render();

        auto frameTime = chrono::high_resolution_clock::now() - frameStart;
        int frameDuration = chrono::duration_cast<chrono::milliseconds>(frameTime).count();

        if (frameDelay > frameDuration) 
            this_thread::sleep_for(chrono::milliseconds(frameDelay - frameDuration));
    }
}

void Game::Stop()
{
    isRunning = false;
}

void Game::ChangeState(State* newState)
{
    currentState = newState;
}

void Game::Update()
{
    currentState->Update();

    if (currentState->getCall() != Call::None)
    {
        switch (currentState->getCall())
        {
        case Call::None:
            break;
        case Call::EnterGameState:
        {
            Hero* hero = new Hero(1, MAPMAXH - 2);
            cout << "Hero Done\n";
            int stage = 0;

            // 주민 리스트 초기화
            vector<Resident*> residents =
            {
                new Resident(stage + 1, 22, 8),
                new Resident(stage + 1, 5, 6),
                new Resident(stage + 1, 20, 20),
                new Resident(stage + 1, 30, 20)
            };
            cout << "Resident Done\n";

            Pendant* pendant = new Pendant(11, 2);
            cout << "Pendant Done\n";


            Portal* portal = new Portal(MAPMAXW - 2, 1);
            cout << "Portal Done\n";


            GameState* gamestate = new GameState(stage, hero, residents, pendant, portal);
            cout << "GameState Done\n";

            ChangeState(gamestate);

            break;
        }
        case Call::EnterMainMenuState:
        {
            State* s = new MainMenuState();
            ChangeState(s);

            break;
        }
        case Call::EnterSavedGameState:
        {
            vector<string> vs = currentState->getFile();
            int stage = 0;
            Hero* h = {};
            vector<Resident*> r = {};
            Pendant* p = {};
            Portal* po = {};
            vector<vector<int>> vi(MAPMAXH, vector<int>(MAPMAXW));

            for (int i = 0; i < vs.size();++i)
            {
                if (vs[i] == "Stage")         stage = stoi(vs[i + 1]);
                else if (vs[i] == "Hero")     h = new Hero(stoi(vs[i + 1]), stoi(vs[i + 2]));
                else if (vs[i] == "Resident") r.push_back(new Resident(stage + 1, stoi(vs[i + 1]), stoi(vs[i + 2])));
                else if (vs[i] == "Pendant")  p = new Pendant(stoi(vs[i + 1]), stoi(vs[i + 2]));
                else if (vs[i] == "Portal")   po = new Portal(stoi(vs[i + 1]), stoi(vs[i + 2]));
                else if (vs[i] == "Map")
                {
                    cout << "MapCheck : Good" << endl;
                    for (int j = 0; j < MAPMAXH; ++j)
                    {
                        for (int k = 0; k < MAPMAXW; ++k)
                        {
                            if(i + 1 + j * MAPMAXH + k < vs.size())
                                vi[j][k] = (stoi(vs[i + 1 + j * MAPMAXH + k]));
                        }
                    }
                }
            }

            State* gamestate = new GameState(stage, h, r, p, po);

            ChangeState(gamestate);

            break;
        }
        case Call::EnterNextStageGameState:
        {

            break;
        }
        default:
            break;
        }
    }
}
