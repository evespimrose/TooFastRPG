#include "GameState.h"

GameState::GameState(int stage, Hero* hero) : frontBuffer(MAPMAXW* MAPMAXH, ' '), backBuffer(MAPMAXW* MAPMAXH, ' '), hero(hero), residents()
{
    switch (stage)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
    for (Resident* resident : residents) 
        resident->addObserver(hero); // Resident에 Hero를 옵저버로 추가
}

void GameState::handleInput() {
    hero->handleInput(); // Hero의 입력 처리 및 notify 호출
}

void GameState::update() {
    hero->update(); // Hero 업데이트
    for (Resident* resident : residents) {
        resident->update(); // Resident 업데이트
    }
}

void GameState::render() {
    drawSceneToBackBuffer();

    std::cout << "\033[H";  // 콘솔 커서를 최상단으로 이동
    for (int i = 0; i < MAPMAXH; ++i) {
        for (int j = 0; j < MAPMAXW; ++j) {
            std::cout << backBuffer[i * MAPMAXW + j] << " ";
        }
        std::cout << "\n";
    }

    std::swap(frontBuffer, backBuffer);
    std::fill(backBuffer.begin(), backBuffer.end(), ' ');

    hero->render();
    for (Resident* resident : residents) {
        resident->render();
    }
}

void GameState::drawSceneToBackBuffer() {
    for (auto& c : backBuffer)
        c = '.';

    backBuffer[hero->getY() * MAPMAXW + hero->getX()] = 'H';

    for (auto& r : residents) {
        backBuffer[r->getY() * MAPMAXW + r->getX()] = 'r';
    }
}