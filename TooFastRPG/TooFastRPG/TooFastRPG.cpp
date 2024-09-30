#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"

int main()
{
    system(" mode  con lines=80   cols=100 ");
    CursorView();

    Hero* hero = new Hero(1, 1);

    // 주민 리스트 초기화
    std::vector<Resident*> residents = 
    {
        new Resident(16, 1),
        new Resident(5, 6)
    };

    int stage = 1;

    srand(time(NULL));
    // 메인 메뉴 상태로 초기화
    MainMenuState* mainMenu = new MainMenuState();
    GameState* gamestate = new GameState(stage, hero, residents);
    Game game(gamestate);

    // 게임 루프 실행
    game.Run();

    return 0;
}