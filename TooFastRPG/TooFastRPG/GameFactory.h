#pragma once
#include <memory>
#include <vector>
#include "Hero.h"
#include "Resident.h"
#include "State.h"
#include "Pendant.h"
#include "Portal.h"


// 게임 상태 타입 열거형
enum class StateType {
    MainMenu,
    Game,
    GameClear
};

// 게임 컨텍스트 구조체
struct GameContext {
    int stage;
    Hero* hero;
    vector<Resident*> residents;
    Pendant* pendant;
    Portal* portal;
};

class GameFactory {
public:
    static unique_ptr<Hero> CreateHero(int stage);
    static vector<unique_ptr<Resident>> CreateResidents(int stage);
    static unique_ptr<State> CreateState(StateType type, GameContext& context);
}; 