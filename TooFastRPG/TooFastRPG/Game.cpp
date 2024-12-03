#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "GameClearState.h"
#include "GameConfig.h"


void Game::Run()
{
    system(("mode con cols=" + 
        to_string(GameConfig::WINDOW_WIDTH) + 
        " lines=" + 
        to_string(GameConfig::WINDOW_HEIGHT)).c_str());

    while (isRunning) {
        auto frameStart = chrono::high_resolution_clock::now();

        // 1. 입력 처리
        HandleInput();

        // 2. 게임 상태 업데이트
        Update();

        // 3. 화면 렌더링 (이중 버퍼링 활용)
        currentState->Render();

        auto frameTime = chrono::high_resolution_clock::now() - frameStart;
        int frameDuration = chrono::duration_cast<chrono::milliseconds>(frameTime).count();

        if (GameConfig::FRAME_DELAY > frameDuration) 
            this_thread::sleep_for(chrono::milliseconds(GameConfig::FRAME_DELAY - frameDuration));
    }
}

void Game::Stop()
{
    isRunning = false;
}

void Game::ChangeState(unique_ptr<State> newState)
{
    currentState = move(newState);
}


void Game::HandleInput()
{
    if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
    {
        isRunning = false;
    }
    currentState->HandleInput();
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
            int stage = 0;

            // 주민 리스트 초기화
            vector<Resident*> residents;
            auto em = GetEventManager();
            residents.push_back(new Resident(em, stage + 1, 22, 8));
            residents.push_back(new Resident(em, stage + 1, 5, 6));
            residents.push_back(new Resident(em, stage + 1, 20, 20));
            residents.push_back(new Resident(em, stage + 1, 30, 20));

            Pendant* pendant = new Pendant(em, 11, 2);

            Portal* portal = new Portal(em, MAPMAXW - 2, 1);

            ChangeState(make_unique<GameState>(GetEventManager(), stage, hero, residents, pendant, portal));

            break;
        }
        case Call::EnterMainMenuState:
        {
            ChangeState(make_unique<MainMenuState>(GetEventManager()));
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
                else if (vs[i] == "Hero")     h = new Hero(stoi(vs[i + 1]), stoi(vs[i + 2]), stoi(vs[i + 3]));
                else if (vs[i] == "Resident")  r.push_back(new Resident(GetEventManager(), stage + 1, stoi(vs[i + 1]), stoi(vs[i + 2])));
                else if (vs[i] == "Pendant")  p = new Pendant(GetEventManager(), stoi(vs[i + 1]), stoi(vs[i + 2]));
                else if (vs[i] == "Portal")   po = new Portal(GetEventManager(), stoi(vs[i + 1]), stoi(vs[i + 2]));
                else if (vs[i] == "Map")
                {
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

            ChangeState(make_unique<GameState>(GetEventManager(), stage, h, r, p, po));
            break;
        }
        case Call::EnterNextStageGameState:
        {
            int stage = currentState->getStage() + 1;

            Hero* h = {};
            vector<Resident*> r = {};
            Pendant* p = {};
            Portal* po = {};

            switch (stage)
            {
            case 1:
            {
                GameFile gf = currentState->getGameFile();
                h = new Hero(1, 1, gf.h->getHoly());

                r.push_back(new Resident(GetEventManager(), stage + 1, 6, 22));
                r.push_back(new Resident(GetEventManager(), stage + 1, 5, 6));
                r.push_back(new Resident(GetEventManager(), stage + 1, 28, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 35, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 4, 16));

                p = new Pendant(GetEventManager(), 6, 6);
                po = new Portal(GetEventManager(), MAPMAXW - 2, MAPMAXH - 2);

                ChangeState(make_unique<GameState>(GetEventManager(), stage, h, r, p, po));
                break;
            }
            case 2:
            {
                GameFile gf = currentState->getGameFile();
                h = new Hero(MAPMAXW - 2, 1, gf.h->getHoly());
                r.push_back(new Resident(GetEventManager(), stage + 1, 6, 22));
                r.push_back(new Resident(GetEventManager(), stage + 1, 5, 6));
                r.push_back(new Resident(GetEventManager(), stage + 1, 28, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 35, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 4, 16));
                r.push_back(new Resident(GetEventManager(), stage + 1, 6, 10));
                r.push_back(new Resident(GetEventManager(), stage + 1, 2, 20));
                p = new Pendant(GetEventManager(), 15, 15);
                po = new Portal(GetEventManager(), 1, MAPMAXH - 2);

                ChangeState(make_unique<GameState>(GetEventManager(), stage, h, r, p, po));
                break;
            }
            case 3:
            {
                GameFile gf = currentState->getGameFile();
                h = new Hero(MAPMAXW - 2, MAPMAXH - 2, gf.h->getHoly());
                r.push_back(new Resident(GetEventManager(), stage + 1, 22, 8));
                r.push_back(new Resident(GetEventManager(), stage + 1, 5, 6));
                r.push_back(new Resident(GetEventManager(), stage + 1, 20, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 35, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 4, 16));
                r.push_back(new Resident(GetEventManager(), stage + 1, 6, 10));
                r.push_back(new Resident(GetEventManager(), stage + 1, 11, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 30, 30));
                r.push_back(new Resident(GetEventManager(), stage + 1, 22, 7));
                r.push_back(new Resident(GetEventManager(), stage + 1, 15, 16));
                r.push_back(new Resident(GetEventManager(), stage + 1, 26, 10));
                r.push_back(new Resident(GetEventManager(), stage + 1, 31, 20));
                r.push_back(new Resident(GetEventManager(), stage + 1, 30, 10));
                r.push_back(new Resident(GetEventManager(), stage + 1, 22, 17));
                p = new Pendant(GetEventManager(), 20, 30);
                po = new Portal(GetEventManager(), 1, 1);

                ChangeState(make_unique<GameState>(GetEventManager(), stage, h, r, p, po));
                break;
            }
            case 4:
            {
                State* s = new GameClearState(GetEventManager());
                ChangeState(make_unique<GameClearState>(GetEventManager()));
                break;
            }
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
    }
}

