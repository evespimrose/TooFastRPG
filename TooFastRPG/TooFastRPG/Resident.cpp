#include "Resident.h"

void Resident::update()
{
    // ���� �������� �ֹ��� �̵���
    x += directionX;
    y += directionY;

    // ���� ��踦 ���� ��� ������ �ݴ�� ��ȯ
    if (x <= 0 || x >= MAPMAXW - 1) directionX *= -1;
    if (y <= 0 || y >= MAPMAXW - 1) directionY *= -1;
}

void Resident::render()
{
    // �ֹ� ��ġ�� 'R'�� ǥ��
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}
