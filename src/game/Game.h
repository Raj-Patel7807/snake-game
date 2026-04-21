#pragma once

#include <string>

#include "../utils/Direction.h"
#include "../config/GameSettings.h"

class Game {
protected:
    int width;
    int height;
    int score;
    bool isGameOver;
    Direction direction;

public:
    Game();

    void run(const std::string &playerName, int initialDelayMs, bool wallsEnabled, GameMode mode, int &maxScore);

protected:
    void resetSession();
};
