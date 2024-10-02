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
    delete currentState;
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
            // 다음 스테이지로
            break;
        case Call::EnterMainMenuState:
        {
            State* s = new MainMenuState();
            ChangeState(s);
            break;
        }
        default:
            break;
        }
    }
}
