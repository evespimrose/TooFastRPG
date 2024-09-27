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
    hero->render(); // ��� �׸���
    for (Resident* resident : residents) {
        resident->render(); // �ֹ� �׸���
    }
}
