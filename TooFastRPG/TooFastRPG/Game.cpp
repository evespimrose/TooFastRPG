#include "Game.h"

void Game::run()
{
    while (isRunning) {
        auto frameStart = chrono::high_resolution_clock::now();

        // 1. 입력 처리
        currentState->handleInput();

        // 2. 게임 상태 업데이트
        currentState->update();

        // 3. 화면 렌더링 (이중 버퍼링 활용)
        currentState->render();

        // FPS 유지
        auto frameTime = chrono::high_resolution_clock::now() - frameStart;
        int frameDuration = chrono::duration_cast<chrono::milliseconds>(frameTime).count();
        if (frameDelay > frameDuration) {
            this_thread::sleep_for(chrono::milliseconds(frameDelay - frameDuration));
        }
    }
}

void Game::stop()
{
    isRunning = false;
}

void Game::changeState(GameState* newState)
{
    delete currentState;
    currentState = newState;
}
