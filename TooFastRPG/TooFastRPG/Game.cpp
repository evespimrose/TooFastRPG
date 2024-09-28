#include "Game.h"

void Game::Run()
{
    while (isRunning) {
        auto frameStart = chrono::high_resolution_clock::now();

        // 1. �Է� ó��
        currentState->HandleInput();

        // 2. ���� ���� ������Ʈ
        currentState->Update();

        // 3. ȭ�� ������ (���� ���۸� Ȱ��)
        currentState->Render();

        // FPS ����
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
