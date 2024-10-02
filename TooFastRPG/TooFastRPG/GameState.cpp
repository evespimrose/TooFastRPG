#include "GameState.h"


GameState::GameState(int s, Hero* h, vector<Resident*> r, Pendant* p, Portal* po) : stage(s), hero(h), residents(r), pendant(p), portal(po)
{
    this->AddObserver(hero);

    vector<vector<string>> c(MAPMAXW, vector<string>(MAPMAXH, " "));
    SetFrontBuffer(c);
    SetBackBuffer(c);

    MyMap mm;
    mm.CreateMap();
    SetMapBuffer(mm.stages[s]);

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

    hero->setHide(1000.0 - (double)(s * 200));

    for (auto* resident : residents) 
        resident->AddObserver(hero); 

    pendant->AddObserver(hero);

    portal->AddObserver(hero);

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

    pendant->Update();

    portal->Update();

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

    CallBack();
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

    if (pendant->getisRender())
        backBuffer[pendant->getY()][pendant->getX()] = "P ";

    backBuffer[portal->getY()][portal->getX()] = "★";
}

void GameState::Collision()
{
    Call c = hero->getPrevCall();
    Hero* h = hero;

    if (c == Call::EnterGameState) int a = 0;
    else if (c == Call::ResidentCollision)
    {
        if (hero->getHoly() > 0)
            hero->setHoly(hero->getHoly() - 1);
        else
            call = Call::EnterMainMenuState;
        //hero->setPrevCall(Call::None);
    }
    else if (c == Call::PendantCollision)
    {
        pendant->Move(mapBuffer);
        hero->setPrevCall(Call::None);
    }
    else if (c == Call::PortalCollision)
    {
        call = Call::EnterGameState;
    }

    //if (c != Call::None)
    //{
    //    switch (c)
    //    {
    //    case Call::ResidentCollision:
    //    {
    //        if (hero->getHoly() > 0)
    //            hero->setHoly(hero->getHoly() - 1);
    //        //else
    //            //call = Call::EnterMainMenuState;
    //        hero->setPrevCall(Call::None);

    //        break;
    //    }
    //    case Call::PendantCollision:
    //    {
    //        pendants.erase(remove_if(pendants.begin(), pendants.end(), [&h](Pendant*& p) { return h->getX() == p->getX() && h->getY() == p->getY(); }), pendants.end());
    //        hero->setPrevCall(Call::None);
    //        break;
    //    }
    //    case Call::PortalCollision:
    //    {
    //        call = Call::EnterGameState;
    //        break;
    //    }
    //    default:
    //        break;
    //    }
    //}
}
