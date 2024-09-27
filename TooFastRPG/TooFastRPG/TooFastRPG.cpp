﻿#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"

// 상태(State) 인터페이스



int main()
{
    system(" mode  con lines=80   cols=100 ");
    CursorView();

    Hero* hero = new Hero(0, 0);

    // 주민 리스트 초기화
    std::vector<Resident*> residents = {
        new Resident(16, 1),
        new Resident(5, 6)
    };

    srand(time(NULL));
    // 메인 메뉴 상태로 초기화
    MainMenuState* mainMenu = new MainMenuState();
    GameState* gamestate = new GameState(hero, residents);
    Game game(gamestate);

    // 게임 루프 실행
    game.run();

    return 0;
}