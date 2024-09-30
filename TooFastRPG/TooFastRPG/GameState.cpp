#include "GameState.h"

GameState::GameState(int stage, Hero* h, vector<Resident*> r) : hero(h), residents(r)
{
    vector<vector<char>> c(MAPMAXW, vector<char>(MAPMAXH, ' '));
    SetFrontBuffer(c);
    SetBackBuffer(c);

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

void GameState::HandleInput() {
    hero->HandleInput(); // Hero의 입력 처리 및 notify 호출
}

void GameState::Update() {
    hero->Update(); // Hero 업데이트
    for (Resident* resident : residents) {
        resident->Update(); // Resident 업데이트
    }
}

void GameState::Render() {
    DrawSceneToBackBuffer();

    cout << "\033[H";  // 콘솔 커서를 최상단으로 이동
    /*for (int i = 0; i < MAPMAXH; ++i) {
        for (int j = 0; j < MAPMAXW; ++j) {
            cout << backBuffer[i * MAPMAXW + j] << " ";
        }
        cout << "\n";
    }*/

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
    for (Resident* resident : residents) {
        resident->Render();
    }
}

void GameState::DrawSceneToBackBuffer() {
    for (auto& i : backBuffer)
        for(auto& c : i)
            c = '.';

    backBuffer[hero->getY()][hero->getX()] = 'H';

    for (auto& r : residents) {
        backBuffer[r->getY()][r->getX()] = 'r';
    }
}