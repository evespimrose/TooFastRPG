#include "stdafx.h"
#include "Game.h"
#include "MainMenuState.h"

// 상태(State) 인터페이스



int main() {
    srand(time(NULL));
    // 메인 메뉴 상태로 초기화
    MainMenuState* mainMenu = new MainMenuState();
    Game game(mainMenu);

    // 게임 루프 실행
    game.run();

    return 0;
}