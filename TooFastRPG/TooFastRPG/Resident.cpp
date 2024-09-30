#include "Resident.h"

void Resident::Update()
{
    int oldX = x, oldY = y;
    
    // 일정 간격으로 주민이 이동함
    Move();

    if (oldX != x || oldY != y) 
        Notify(x, y); // Hero에게 새로운 좌표 통보
}

void Resident::Render()
{
    std::cout << "Resident at (" << x << ", " << y << ")\n";
}

void Resident::Move()
{
    x += directionX;
    y += directionY;

    // 맵의 경계를 넘을 경우 방향을 반대로 전환
    if (x <= 0 || x >= MAPMAXW - 1) directionX *= -1;
    if (y <= 0 || y >= MAPMAXW - 1) directionY *= -1;
}


/*
    주민, 용사가 각각 Map에 놓인 벽과 장애물에 부딪히면 못가거나 방향전환이 되야됨.
    인코딩 오류 해결할 것. 왜안되지?
    Stage마다 다르게 Map 제작할것.
    여신 어쩌구 펜던트 만들것. 기왕이면 Item 클래스로 만들어서 맵에 뿌리자. Subject 붙이는거 잊지말고. 이걸 뿌려주는 주민처럼 움직이는 Nun클래스?



*/
