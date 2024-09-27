#include "GameScene.h"

void GameScene::handleInput()
{
    hero->handleInput(); // 용사에 대한 입력 처리
}

void GameScene::update()
{
    hero->update(); // 용사의 상태 업데이트
    for (Resident* resident : residents) {
        resident->update(); // 주민의 상태 업데이트
    }
}

void GameScene::render()
{
    system("cls"); // 콘솔 화면 지우기 (Windows 환경)

    hero->render(); // 용사 그리기
    for (Resident* resident : residents) {
        resident->render(); // 주민 그리기
    }
}
