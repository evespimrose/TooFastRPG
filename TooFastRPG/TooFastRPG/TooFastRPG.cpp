#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"

int main()
{
    system(" mode  con lines=80   cols=100 ");
    CursorView();

    Hero* hero = new Hero(1, MAPMAXH - 2);

    int stage = 0;

    // 주민 리스트 초기화
    std::vector<Resident*> residents = 
    {
        new Resident(stage + 1, 16, 2),
        new Resident(stage + 1, 5, 6),
        new Resident(stage + 1, 20, 20)

    };

    std::vector<Nun*> nuns =
    {
        new Nun(stage + 1, 16, 2),

    };

    

    srand(time(NULL));
    // 메인 메뉴 상태로 초기화
    MainMenuState* mainMenu = new MainMenuState();
    GameState* gamestate = new GameState(stage, hero, residents, nuns);
    Game game(gamestate);

    // 게임 루프 실행
    game.Run();

    return 0;
}