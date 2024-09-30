#include "GameState.h"

GameState::GameState(int stage, Hero* h, vector<Resident*> r, vector<Nun*> n) : hero(h), residents(r), nuns(n)
{
    this->AddObserver(hero);

    vector<vector<string>> c(MAPMAXW, vector<string>(MAPMAXH, " "));
    SetFrontBuffer(c);
    SetBackBuffer(c);

    MyMap mm;
    mm.CreateMap();
    SetMapBuffer(mm.stages[stage]);

    /*switch (stage)
    {
    case 0:
        break;
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
    }*/

    hero->SetHide(1000.0 - (double)(stage * 200));

    for (Resident* resident : residents) 
        resident->AddObserver(hero); 

}

void GameState::HandleInput() 
{
    hero->HandleInput(mapBuffer);
}

void GameState::Update() 
{
    hero->Update(mapBuffer);

    for (auto& resident : residents)
        resident->Update(mapBuffer);

    for (auto& nun : nuns)
        nun->Update(mapBuffer);
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

    for (auto& resident : residents) 
        resident->Render();

    for (auto& nun : nuns)
        nun->Render();
}

void GameState::DrawSceneToBackBuffer() 
{
    for (int i = 0; i < mapBuffer.size(); ++i)
    {
        for (int j = 0; j < mapBuffer[0].size(); ++j)
        {
            switch (mapBuffer[i][j])
            {
            case 0:
                backBuffer[i][j] = ". ";
                break;
            case 1:
                backBuffer[i][j] = "■ ";
                break;
            case 2:
                backBuffer[i][j] = "★";
                break;
            default:
                break;
            }
        }
    }

    if(!hero->getHide())
        backBuffer[hero->getY()][hero->getX()] = "H ";
    else if(!hero->getCanHide())
        backBuffer[hero->getY()][hero->getX()] = "H ";
    for (auto& r : residents)         
        backBuffer[r->getY()][r->getX()] = "R ";

    for (auto& n : nuns)
        if(n->getChastity())
            backBuffer[n->getY()][n->getX()] = "N ";
}
