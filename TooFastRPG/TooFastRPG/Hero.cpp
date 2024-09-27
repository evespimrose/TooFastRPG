#include "Hero.h"

void Hero::handleInput()
{
    // _getch() �޼ҵ带 ����� ȭ��ǥ Ű �Է� ó��
    int ch = _getch();
    switch (ch) {
    case 72: // ���� ȭ��ǥ
        y--;
        break;
    case 80: // �Ʒ��� ȭ��ǥ
        y++;
        break;
    case 75: // ���� ȭ��ǥ
        x--;
        break;
    case 77: // ������ ȭ��ǥ
        x++;
        break;
    }
}

void Hero::update()
{

}

void Hero::render()
{
    system("cls");
    // ����� ��ġ�� 'H'�� ǥ��
    for (int i = 0; i < MAPMAXW; i++) 
    {
        for (int j = 0; j < MAPMAXH; j++) 
        {
            if (i == y && j == x) {
                std::cout << 'H' << " "; // ��� ��ġ
            }
            else {
                std::cout << '.' << " "; // �� ����
            }
        }
        std::cout << std::endl;
    }
}
