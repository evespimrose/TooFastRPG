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
    // 1. 백 버퍼에 그리기
    drawSceneToBackBuffer();

    // 2. 백 버퍼를 출력
    std::cout << "\033[H";  // 콘솔 커서를 최상단으로 이동 (ANSI 이스케이프 코드)
    for (int i = 0; i < MAPMAXH; ++i) 
    {
        for (int j = 0; j < MAPMAXW; ++j) 
        {
            std::cout << backBuffer[i * MAPMAXW + j] << " ";
        }
        std::cout << "\n";
    }

    // 3. 백 버퍼를 프론트 버퍼와 교체
    std::swap(frontBuffer, backBuffer);

    // 4. 새로운 백 버퍼를 초기화 (빈 화면으로 채우기)
    std::fill(backBuffer.begin(), backBuffer.end(), ' ');

    hero->render(); // 용사 그리기
    for (Resident* resident : residents) {
        resident->render(); // 주민 그리기
    }
}

void GameState::drawSceneToBackBuffer()
{
    for (auto& c : backBuffer)
        c = '.';

    backBuffer[hero->getY() * MAPMAXW + hero->getX()] = 'H';

    for (auto& r : residents)
    {
        backBuffer[r->getY() * MAPMAXW + r->getX()] = 'r';
    }
}
