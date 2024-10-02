#include "MainMenuState.h"

MainMenuState::MainMenuState()
{
    system("cls");
    backBuffer = new vector<string>(1);
    frontBuffer = new vector<string>(1);

}

MainMenuState::~MainMenuState()
{
    delete[] backBuffer;
    delete[] frontBuffer;
}

void MainMenuState::HandleInput()
{
    int ch = GetCommand();

    switch (ch)
    {
    case 'Q':
        exit(1);
        break;
    case 32:
    {
        if (parsingSaveFile(vs))
        {
            call = Call::EnterSavedGameState;
        }
        else cout << "불러올 파일이 없습니다!\n";
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

    for (auto& i : *backBuffer)
    {
        cout << i;
        cout << "\n";
    }

    swap(frontBuffer, backBuffer);

    for (auto& i : *backBuffer)
    {
        i = " ";
    }

    //CallBack();
}

void MainMenuState::DrawSceneToBackBuffer()
{
    string s = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                    새 게임 시작 Enter\n\n                                    저장된 게임 불러오기 Space Bar\n\n                                    게임 종료 Q / Esc";
    *backBuffer->begin() = s;
}

