#pragma once

#include <string>
#include "../config/GameSettings.h"

class StartScreen {
public:
    static std::string welcomeAndGetName();

    static GameSettings askSettings();
};

