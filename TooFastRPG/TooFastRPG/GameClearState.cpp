#include "GameClearState.h"
#include "MainMenuState.h"

void GameClearState::HandleInput()
{
    int ch = GetCommand();
    switch (ch)
    {
    case 'q':
    case 'Q':
        InitSaveFile();
        call = Call::EnterMainMenuState;
    default:
        break;
    }
}

void GameClearState::Update()
{
}

void GameClearState::Render()
{
    DrawSceneToBackBuffer();
    cout << "\033[H";

    for (auto& i : backBuffer)
        cout << i;

    swap(frontBuffer, backBuffer);

    for (auto& i : backBuffer)
        i = " ";
}

void GameClearState::DrawSceneToBackBuffer()
{
    string s = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                      Game Clear!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n                              메인 메뉴로 돌아가려면 q / Q를 누르세요.\n";
    backBuffer[0] = s;
}

