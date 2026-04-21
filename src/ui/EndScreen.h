#pragma once

#include <string>

struct EndChoice {
    bool playAgain;
    bool changeSettings;
};

class EndScreen {
public:
    static EndChoice showGameOverAndAskPlayAgain(const std::string& playerName, int maxScore);
    static void sayGoodbye(const std::string& playerName);
};

