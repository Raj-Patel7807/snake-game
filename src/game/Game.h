#pragma once
#include <vector>

#include "../utils/Direction.h"

using namespace std;

class Game {
protected:
    int width;
    int height;
    int score;
    bool isGameOver;
    Direction Dir;

public:
    Game();

    void run();

protected:
    void draw();
    void input();
    void logic();
};
