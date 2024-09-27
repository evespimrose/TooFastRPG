#include "Resident.h"

void Resident::update()
{
    // ���� �������� �ֹ��� �̵���
    x += directionX;
    y += directionY;

    // ���� ��踦 ���� ��� ������ �ݴ�� ��ȯ
    if (x <= 0 || x >= 9) directionX *= -1;
    if (y <= 0 || y >= 9) directionY *= -1;
}

void Resident::render()
{
    // �ֹ� ��ġ�� 'R'�� ǥ��
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
