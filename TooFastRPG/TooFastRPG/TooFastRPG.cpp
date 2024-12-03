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

    srand(time(NULL));

    Game game(make_unique<MainMenuState>());

    // 게임 루프 실행
    game.Run();

    return 0;
}