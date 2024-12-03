#pragma once
#include "State.h"
#include <memory>

class GameClearState : public State
{
private:
    vector<string> frontBuffer;
    vector<string> backBuffer;


public:
    GameClearState() 
    {
        system("cls");
        frontBuffer.resize(3);
        backBuffer.resize(3);
    }

    void HandleInput() override;
    void Update() override;

    void Render() override;
    void SaveFile() override {};

    void DrawSceneToBackBuffer();

    void InitSaveFile()
    {
        string num = "0";

        ofstream output_file("output.txt");
        output_file << num << endl;
        output_file.close();
    }
};

