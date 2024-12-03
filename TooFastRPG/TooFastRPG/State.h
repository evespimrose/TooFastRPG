#pragma once
#include "stdafx.h"
#include "Observer.h"
#include "Hero.h"
#include <memory>

// GameFile 구조체를 먼저 정의
struct GameFile {
    int stage = {};
    Hero* h = {};
};

// 기본 State 인터페이스
class State : public Subject 
{
protected:
    Call call = Call::None;
    vector<string> vs = {};
    int stage = {};
    GameFile gamefile = {};

public:
    State(shared_ptr<EventManager> em) : Subject(em) {}
    virtual ~State() = default;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void SaveFile() = 0;

    // 공통 기능들
    void SetStage(int i) { stage = i; }
    Call getCall() { return call; }
    int getStage() { return stage; }
    GameFile getGameFile() { return gamefile; }
    vector<string> getFile() { return vs; }

    //void MyCallBack();  
    bool parsingSaveFile(vector<string>& vs);
};

