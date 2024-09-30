#include "GameState.h"

GameState::GameState(int stage, Hero* h, vector<Resident*> r) : hero(h), residents(r)
{

    vector<vector<string>> c(MAPMAXW, vector<string>(MAPMAXH, " "));
    SetFrontBuffer(c);
    SetBackBuffer(c);

    vector<vector<int>> m(MAPMAXW, vector<int>(MAPMAXH, 0));
    SetMapBuffer(m);

    switch (stage)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }

    for (Resident* resident : residents) 
        resident->AddObserver(hero); // Resident에 Hero를 옵저버로 추가
}

void GameState::HandleInput() 
{
    hero->HandleInput();
}

void GameState::Update() 
{
    hero->Update();
    for (Resident* resident : residents) 
        resident->Update();
}

void GameState::Render() 
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
    //fill(backBuffer.begin(), backBuffer.end(), ' ');

    hero->Render();
    for (Resident* resident : residents) 
        resident->Render();
}

void GameState::DrawSceneToBackBuffer() 
{
    for (auto& i : backBuffer)
        for(auto& c : i)
            c = '.';

    backBuffer[hero->getY()][hero->getX()] = 'H';

    for (auto& r : residents) {
        backBuffer[r->getY()][r->getX()] = 'R';
    }
}