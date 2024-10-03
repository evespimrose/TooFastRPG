#include "GameState.h"


GameState::GameState(int s, Hero* h, vector<Resident*> r, Pendant* p, Portal* po) : hero(h), residents(r), pendant(p), portal(po)
{
    system("cls");
    SetStage(s);
    this->AddObserver(hero);

    vector<vector<string>> c(MAPMAXW, vector<string>(MAPMAXH, " "));
    SetFrontBuffer(c);
    SetBackBuffer(c);

    MyMap mm;
    SetMapBuffer(mm.stages[stage]);

    hero->setHide(1000.0 - (double)(stage * 200));

    for (auto* resident : residents) 
        resident->AddObserver(hero); 

    pendant->AddObserver(hero);

    portal->AddObserver(hero);

}

GameState::GameState(int s, Hero* h, vector<Resident*> r, Pendant* p, Portal* po, vector<vector<int>> map) : hero(h), residents(r), pendant(p), portal(po), mapBuffer(map)
{
    this->AddObserver(hero);

    vector<vector<string>> c(MAPMAXW, vector<string>(MAPMAXH, " "));
    SetFrontBuffer(c);
    SetBackBuffer(c);

    hero->setHide(1000.0 - (double)(stage * 200));

    for (auto* resident : residents)
        resident->AddObserver(hero);

    pendant->AddObserver(hero);

    portal->AddObserver(hero);
}

void GameState::HandleInput() 
{
    if (GetAsyncKeyState(VK_F1) & 0x8000)
    {
        SaveFile();
    }
    hero->HandleInput(mapBuffer);
}

void GameState::Update() 
{
    hero->Update();

    for (auto& resident : residents)
        resident->Update(mapBuffer);

    pendant->Update();

    portal->Update();

    if (hero->getHide() && hero->getCanHide())
        mapBuffer[hero->getY()][hero->getX()] = 1;

    Collision();

}

void GameState::Render() 
{
    DrawSceneToBackBuffer();

    cout << "\033[H";  // 콘솔 커서를 최상단으로 이동

    for (auto& i : backBuffer)
    {
        for (auto& j : i)
        {
            cout << j;
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

    pendant->Render();

    portal->Render();

    //cout << " hero->getHide() : " << boolalpha << hero->getHide() << "\n";
    cout << "현재 진행도 저장 : F1\n";

    //CallBack();
}

void GameState::SaveFile()
{
    vector<string> vs;

    int num = 0;

    vs.push_back("Stage");
    vs.push_back(to_string(stage));

    vs.push_back("Hero");

    vs.push_back(to_string(hero->getX()));
    vs.push_back(to_string(hero->getY()));
    vs.push_back(to_string(hero->getHoly()));
    num += 4;

    for (auto& resident : residents)
    {
        vs.push_back("Resident");

        vs.push_back(to_string(resident->getX()));
        vs.push_back(to_string(resident->getY()));
        num += 3;
    }

    vs.push_back("Pendant");
    vs.push_back(to_string(pendant->getX()));
    vs.push_back(to_string(pendant->getY()));
    num += 3;

    vs.push_back("Portal");
    vs.push_back(to_string(portal->getX()));
    vs.push_back(to_string(portal->getY()));
    num += 3;

    vs.push_back("Map");
    num++;
    for(auto &i : mapBuffer)
        for (auto& j : i)
        {
            vs.push_back(to_string(j));
            num ++;
        }

    vector<string>::iterator iter = vs.begin();
    vs.insert(iter, to_string(num));

    // output to json file
    ofstream output_file("output.txt");
    for (auto& i : vs)
        output_file << i << endl;
    output_file.close();
}

void GameState::InitSaveFile()
{
    string num = "0";

    ofstream output_file("output.txt");
    output_file << num << endl;
    output_file.close();

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
                backBuffer[i][j] = "  ";
                break;
            case 1:
                backBuffer[i][j] = "■ ";
                break;
            default:
                break;
            }
        }
    }

    if (!hero->getHide())
        backBuffer[hero->getY()][hero->getX()] = "▲ ";
    else if (!hero->getCanHide())
        backBuffer[hero->getY()][hero->getX()] = "▲ ";

    for (auto& r : residents)
        backBuffer[r->getY()][r->getX()] = "◎";

    if (pendant->getisRender())
        backBuffer[pendant->getY()][pendant->getX()] = "§ ";

    backBuffer[portal->getY()][portal->getX()] = "★";
}

void GameState::Collision()
{
    Call c = hero->getPrevCall();
    Hero* h = hero;

    if (c == Call::ResidentCollision)
    {
        if (hero->getHoly() > 0)
        {
            hero->setHoly(hero->getHoly() - 1);
        }
        else
        {
            InitSaveFile();
            call = Call::EnterMainMenuState;
        }
        hero->setPrevCall(Call::None);
    }
    else if (c == Call::PendantCollision)
    {
        pendant->Move(mapBuffer);
        hero->setPrevCall(Call::None);
    }
    else if (c == Call::PortalCollision)
    {
        SetGameFile(stage, hero);
        call = Call::EnterNextStageGameState;
        hero->setPrevCall(Call::None);
    }
}
