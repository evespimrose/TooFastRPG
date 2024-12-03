#include "MainMenuState.h"

MainMenuState::~MainMenuState() {}

void MainMenuState::HandleInput()
{
    int ch = GetCommand();

    switch (ch)
    {
    case 32:
    {
        if (parsingSaveFile(vs))
            call = Call::EnterSavedGameState;
        else 
            cout << "불러올 파일이 없습니다!\n";
        break;
    }
        
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
        cout << i << "\n";

    swap(frontBuffer, backBuffer);

    for (auto& i : backBuffer)
        i = " ";
}

void MainMenuState::DrawSceneToBackBuffer()
{
    string s = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                제목..은 마왕성에 가고 싶습니다로 하겠습니다. 근데..좀비..를 곁들인\n\n\n\n                                         새 게임 시작 Enter\n\n                                  저장된 게임 불러오기 Space Bar\n\n                                           게임 종료 Esc";
    backBuffer[0] = s;
}

