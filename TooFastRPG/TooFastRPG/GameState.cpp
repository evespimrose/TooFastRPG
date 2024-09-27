#include "GameState.h"

void GameState::handleInput()
{
    hero->handleInput(); // ��翡 ���� �Է� ó��
}

void GameState::update()
{
    hero->update(); // ����� ���� ������Ʈ
    for (Resident* resident : residents) {
        resident->update(); // �ֹ��� ���� ������Ʈ
    }
}

void GameState::render()
{
    // 1. �� ���ۿ� �׸���
    drawSceneToBackBuffer();

    // 2. �� ���۸� ���
    std::cout << "\033[H";  // �ܼ� Ŀ���� �ֻ������ �̵� (ANSI �̽������� �ڵ�)
    for (int i = 0; i < MAPMAXH; ++i) 
    {
        for (int j = 0; j < MAPMAXW; ++j) 
        {
            std::cout << backBuffer[i * MAPMAXW + j] << " ";
        }
        std::cout << "\n";
    }

    // 3. �� ���۸� ����Ʈ ���ۿ� ��ü
    std::swap(frontBuffer, backBuffer);

    // 4. ���ο� �� ���۸� �ʱ�ȭ (�� ȭ������ ä���)
    std::fill(backBuffer.begin(), backBuffer.end(), ' ');

    hero->render(); // ��� �׸���
    for (Resident* resident : residents) {
        resident->render(); // �ֹ� �׸���
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
