#include "Game.h"

void Game::run()
{
    while (isRunning) {
        auto frameStart = chrono::high_resolution_clock::now();

        // 1. �Է� ó��
        currentState->handleInput();

        // 2. ���� ���� ������Ʈ
        currentState->update();

        // 3. ȭ�� ������ (���� ���۸� Ȱ��)
        currentState->render();

        // FPS ����
        auto frameTime = chrono::high_resolution_clock::now() - frameStart;
        int frameDuration = chrono::duration_cast<chrono::milliseconds>(frameTime).count();

        if (frameDelay > frameDuration) 
            this_thread::sleep_for(chrono::milliseconds(frameDelay - frameDuration));

    }
}

void Game::stop()
{
    isRunning = false;
}

void Game::changeState(State* newState)
{
    delete currentState;
    currentState = newState;
}
