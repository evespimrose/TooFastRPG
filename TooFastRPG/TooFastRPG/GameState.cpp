#include "GameState.h"

GameState::GameState(int stage, Hero* h, vector<Resident*> r) : frontBuffer(MAPMAXW* MAPMAXH, ' '), backBuffer(MAPMAXW* MAPMAXH, ' '), hero(h), residents(r)
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
        resident->AddObserver(hero); // Resident에 Hero를 옵저버로 추가
}

void GameState::HandleInput() {
    hero->HandleInput(); // Hero의 입력 처리 및 notify 호출
}

void GameState::Update() {
    hero->Update(); // Hero 업데이트
    for (Resident* resident : residents) {
        resident->Update(); // Resident 업데이트
    }
}

void GameState::Render() {
    DrawSceneToBackBuffer();

    std::cout << "\033[H";  // 콘솔 커서를 최상단으로 이동
    for (int i = 0; i < MAPMAXH; ++i) {
        for (int j = 0; j < MAPMAXW; ++j) {
            std::cout << backBuffer[i * MAPMAXW + j] << " ";
        }
        std::cout << "\n";
    }

    std::swap(frontBuffer, backBuffer);
    std::fill(backBuffer.begin(), backBuffer.end(), ' ');

    hero->Render();
    for (Resident* resident : residents) {
        resident->Render();
    }
}

void GameState::DrawSceneToBackBuffer() {
    for (auto& c : backBuffer)
        c = '.';

    backBuffer[hero->getY() * MAPMAXW + hero->getX()] = 'H';

    for (auto& r : residents) {
        backBuffer[r->getY() * MAPMAXW + r->getX()] = 'r';
    }
}