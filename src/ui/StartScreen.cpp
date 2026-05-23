#include "StartScreen.h"
#include "../config/Config.h"
#include "../utils/color/Color.h"
#include <iostream>

static void printWelcomeHeader() {
    std::cout << Color::brightCyan();
    std::cout << "\n\n\n";
    std::cout << "          **************************************************************************************\n\n";
    std::cout << "                                 W E L C O M E  T O  S N A K E  G A M E ! !\n\n";
    std::cout << "          **************************************************************************************\n\n\n\n";
    std::cout << Color::reset();
}

std::string StartScreen::welcomeAndGetName() {
    system(CLEAR);
    printWelcomeHeader();

    std::string name;
    std::cout << Color::brightYellow() << "\n\nEnter your Name : " << Color::reset();
    std::getline(std::cin, name);
    return name;
}

GameSettings StartScreen::askSettings() {
    system(CLEAR);
    printWelcomeHeader();

    int modeChoice = 2;
    std::cout << Color::brightMagenta() << "Game Modes\n" << Color::reset();
    std::cout << "1. Classic (No obstacles)\n";
    std::cout << "2. Obstacles (Default)\n";
    std::cout << "3. Survival (Speed keeps increasing)\n\n";
    std::cout << Color::brightYellow() << "Set Game Mode : " << Color::reset();
    std::cin >> modeChoice;
    if(modeChoice < 1 || modeChoice > 3) modeChoice = 2;

    system(CLEAR);
    printWelcomeHeader();

    int diffChoice = 0;
    std::cout << Color::brightMagenta() << "Difficulty Levels\n" << Color::reset();
    std::cout << "1. Easy\n2. Medium\n3. Hard\n\n";
    std::cout << "NOTE : If You Press Key Other than 1, 2 or 3 then Difficulty Will Set Automatically to Medium..\n\n";
    std::cout << Color::brightYellow() << "Set Difficulty Level : " << Color::reset();
    std::cin >> diffChoice;

    int delayMs = 140;
    if(diffChoice == 3) delayMs = 90;
    else if(diffChoice == 2) delayMs = 140;
    else if(diffChoice == 1) delayMs = 190;

    system(CLEAR);
    printWelcomeHeader();

    int wallsEnable = 1;
    std::cout << Color::brightMagenta() << "Walls\n" << Color::reset();
    std::cout << "Do You Want To Enable The Walls..?\n\n";
    std::cout << "NOTE : if Walls are Enable then if you touch the walls, The game is Over..\n";
    std::cout << "If You Press other than 1 or 0 then it will take 1 and walls are enabled automatically..\n\n";
    std::cout << Color::brightYellow() << "Press 1 for Walls Enable and 0 for not enable : " << Color::reset();
    std::cin >> wallsEnable;

    GameSettings s{};
    s.delayMs = delayMs;
    s.wallsEnabled = (wallsEnable == 0) ? false : true;
    s.mode = (GameMode) modeChoice;
    return s;
}
