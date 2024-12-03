#pragma once
#include "State.h"
#include <memory>
#include "Hero.h"
#include "Resident.h"
#include "Pendant.h"
#include "Portal.h"

class SaveManager;
class CollisionManager;
class GameRenderer;

class GameState : public State
{
private:
    Hero* hero;
    vector<Resident*> residents;
    Pendant* pendant;
    Portal* portal;

    vector<vector<string>> frontBuffer = {};
    vector<vector<string>> backBuffer = {};
    vector<vector<int>> mapBuffer = {};

    unique_ptr<GameRenderer> renderer;
    unique_ptr<CollisionManager> collisionManager;
    unique_ptr<SaveManager> saveManager;

public:
    GameState(shared_ptr<EventManager> em, int s, Hero* hero, vector<Resident*> residents, Pendant* pendant, Portal* portal);
    GameState(shared_ptr<EventManager> em, int s, Hero* hero, vector<Resident*> residents, Pendant* pendant, Portal* portal, vector<vector<int>> map);

    void HandleInput() override;

    void Update() override;

    void Render() override;

    void SaveFile() override;

    void InitSaveFile();

    void DrawSceneToBackBuffer();

    void SetFrontBuffer(vector<vector<string>>& c) { frontBuffer = c; }
    void SetBackBuffer(vector<vector<string>>& c) { backBuffer = c; }

    void SetGameFile(int i, Hero* h) { gamefile.stage = i; gamefile.h = h;}

    void SetMapBuffer(vector<vector<int>>& i) { mapBuffer = i; }

    void Collision();

    int getStage() { return stage; }
};

class GameRenderer 
{
    void Render(const GameState& state);
};

class CollisionManager 
{
    void CheckCollisions(GameState& state);
};

class SaveManager 
{
    void SaveGame(const GameState& state);
};