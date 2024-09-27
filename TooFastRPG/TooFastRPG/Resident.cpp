#include "Resident.h"

void Resident::update()
{
    int oldX = x, oldY = y;
    // ����: �̵� ó��
    // x++, y++ �Ǵ� NPC ������ ���� ����

    
    // ���� �������� �ֹ��� �̵���
    x += directionX;
    y += directionY;

    // ���� ��踦 ���� ��� ������ �ݴ�� ��ȯ
    if (x <= 0 || x >= MAPMAXW - 1) directionX *= -1;
    if (y <= 0 || y >= MAPMAXW - 1) directionY *= -1;

    if (oldX != x || oldY != y) 
        notify(x, y); // Hero���� ���ο� ��ǥ �뺸

}

void Resident::render()
{
    // �ֹ� ��ġ�� 'R'�� ǥ��
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
