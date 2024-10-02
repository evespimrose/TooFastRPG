#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"

int main()
{
    system(" mode  con lines=44   cols=100 ");
    CursorView();
    cout.precision(3);
    SetConsoleOutputCP(CP_UTF8);

    Hero* hero = new Hero(1, MAPMAXH - 2);

    int stage = 0;

    // 주민 리스트 초기화
    vector<Resident*> residents = 
    {
        new Resident(stage + 1, 22, 8),
        new Resident(stage + 1, 5, 6),
        new Resident(stage + 1, 20, 20),
        new Resident(stage + 1, 30, 20)
    };

    Pendant* pendant = new Pendant(11, 2);

    Portal* portal = new Portal(MAPMAXW - 2, 1);

    srand(time(NULL));
    // 메인 메뉴 상태로 초기화
    MainMenuState* mainMenu = new MainMenuState();
    GameState* gamestate = new GameState(stage, hero, residents, pendant, portal);
    Game game(mainMenu);

    // 게임 루프 실행
    game.Run();

    return 0;
}