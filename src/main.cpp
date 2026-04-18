#include "game/Game.h"
#include "utils/animation/Animation.h"
#include <ctime>
#include <iostream>
#include <cstddef>

int main() {
    srand(time(0));

    std::string name;
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    animation(name);

    Game game;
    game.run();

    return 0;
}
