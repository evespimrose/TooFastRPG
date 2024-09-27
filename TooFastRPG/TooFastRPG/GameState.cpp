#include "GameState.h"

void GameState::handleInput()
{
    hero->handleInput(); // 용사에 대한 입력 처리
}

void GameState::update()
{
    hero->update(); // 용사의 상태 업데이트
    for (Resident* resident : residents) {
        resident->update(); // 주민의 상태 업데이트
    }
}

void GameState::render()
{
    hero->render(); // 용사 그리기
    for (Resident* resident : residents) {
        resident->render(); // 주민 그리기
    }
}
