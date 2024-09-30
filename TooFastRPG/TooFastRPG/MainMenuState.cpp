#include "MainMenuState.h"

void MainMenuState::HandleInput()
{
    int ch = GetCommand();

    switch (ch)
    {
    case 27:
    case 'Q':
        break;
    case 32:
        break;
    case 13:
        call = Call::EnterGameState;
        break;
    default:
        break;
    }

}

void MainMenuState::Update()
{
}

void MainMenuState::Render()
{
    DrawSceneToBackBuffer();

    cout << "\033[H";  // 콘솔 커서를 최상단으로 이동

    for (auto& i : backBuffer)
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    swap(frontBuffer, backBuffer);

    for (auto& i : backBuffer)
    {
        fill(i.begin(), i.end(), ' ');
    }
}

void MainMenuState::DrawSceneToBackBuffer()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n새 게임 시작 Enter\n\n저장된 게임 불러오기 Space Bar\n\n게임 종료는 Q / Esc\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
