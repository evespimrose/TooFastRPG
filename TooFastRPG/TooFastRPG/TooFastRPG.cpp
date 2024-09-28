#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"
#include "GameState.h"

int main()
{
    system(" mode  con lines=80   cols=100 ");
    CursorView();

    Hero* hero = new Hero(0, 0);

    // �ֹ� ����Ʈ �ʱ�ȭ
    std::vector<Resident*> residents = 
    {
        new Resident(16, 1),
        new Resident(5, 6)
    };
    int stage = 1;

    srand(time(NULL));
    // ���� �޴� ���·� �ʱ�ȭ
    MainMenuState* mainMenu = new MainMenuState();
    GameState* gamestate = new GameState(stage, hero, residents);
    Game game(gamestate);

    // ���� ���� ����
    game.run();

    return 0;
}