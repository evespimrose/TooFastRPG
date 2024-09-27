#include "GameScene.h"

void GameScene::handleInput()
{
    hero->handleInput(); // ��翡 ���� �Է� ó��
}

void GameScene::update()
{
    hero->update(); // ����� ���� ������Ʈ
    for (Resident* resident : residents) {
        resident->update(); // �ֹ��� ���� ������Ʈ
    }
}

void GameScene::render()
{
    system("cls"); // �ܼ� ȭ�� ����� (Windows ȯ��)

    hero->render(); // ��� �׸���
    for (Resident* resident : residents) {
        resident->render(); // �ֹ� �׸���
    }
}
