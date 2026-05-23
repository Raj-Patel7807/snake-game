#pragma once

enum GameMode {
    MODE_CLASSIC = 1, MODE_OBSTACLES = 2, MODE_SURVIVAL = 3
};

struct GameSettings {
    int delayMs;
    bool wallsEnabled;
    GameMode mode;
};
