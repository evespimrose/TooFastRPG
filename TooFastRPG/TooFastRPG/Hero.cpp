#include "Hero.h"

void Hero::HandleInput()
{
    // _getch() �޼ҵ带 ����� ȭ��ǥ Ű �Է� ó��
    int ch = GetCommand();
    switch (ch) {
    case 72: // ���� ȭ��ǥ
        if(y > 0)
            y--;
        break;
    case 80: // �Ʒ��� ȭ��ǥ
        if(y < MAPMAXH - 1)
            y++;
        break;
    case 75: // ���� ȭ��ǥ
        if(x > 0)
            x--;
        break;
    case 77: // ������ ȭ��ǥ
        if (x < MAPMAXW - 1)
            x++;
        break;
    default:
        break;
    }
}

void Hero::Update()
{

}

void Hero::Render()
{
    if(!isCollision)
        std::cout << "Hero at (" << x << ", " << y << ")\n";
    else
        std::cout << "�浹 �߻�! Hero: (" << x << ", " << y << ")\n";
}

void Hero::OnNotify(int residentX, int residentY)
{
    isCollision = x == residentX && y == residentY ? true : false;

}
