#pragma once
#include <string>
#include <Windows.h>

class GameConfig 
{
private:
    GameConfig() = default;  // 싱글톤 패턴

public:
    static GameConfig& Instance() {
        static GameConfig instance;
        return instance;
    }

    // 게임 화면 설정
    static constexpr int WINDOW_WIDTH = 100;
    static constexpr int WINDOW_HEIGHT = 44;
    static constexpr int MAP_MAX_W = 40;
    static constexpr int MAP_MAX_H = 40;

    // 게임 성능 설정
    static constexpr int FPS = 60;
    static constexpr int FRAME_DELAY = 1000 / FPS;

    // 게임플레이 설정
    static constexpr int RESIDENT_RANDOM = 4;
    static constexpr int INITIAL_HERO_HEALTH = 100;
    static constexpr double INITIAL_HIDE_GAUGE = 1000.0;
    static constexpr double HIDE_DECREASE_RATE = 100.0 / 60.0;

    // 키 설정
    static constexpr int ARROW = 224;
    static constexpr int SAVE_KEY = VK_F1;
    static constexpr int PORTAL_KEY = VK_SHIFT;

    // 파일 경로 설정
    static const std::string SAVE_FILE_PATH;
}; 