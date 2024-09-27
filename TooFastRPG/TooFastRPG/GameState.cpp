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
        resident->addObserver(hero); // Resident�� Hero�� �������� �߰�
}

void GameState::handleInput() {
    hero->handleInput(); // Hero�� �Է� ó�� �� notify ȣ��
}

void GameState::update() {
    hero->update(); // Hero ������Ʈ
    for (Resident* resident : residents) {
        resident->update(); // Resident ������Ʈ
    }
}

void GameState::render() {
    drawSceneToBackBuffer();

    std::cout << "\033[H";  // �ܼ� Ŀ���� �ֻ������ �̵�
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