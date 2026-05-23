#include "game/Game.h"
#include "utils/animation/Animation.h"
#include "ui/StartScreen.h"
#include "ui/EndScreen.h"
#include "persistence/HighScore.h"
#include "utils/color/Color.h"
#include <ctime>
#include <iostream>

int main() {
    srand(time(0));
    Color::enableVirtualTerminal();

    std::string name = StartScreen::welcomeAndGetName();
    const std::string highScoreFile = "highscore.txt";
    int maxScore = HighScore::load(highScoreFile);
    bool playAgain = false;
    GameSettings settings = StartScreen::askSettings();

    do {
        animation(name);

        Game game;
        game.run(name, settings.delayMs, settings.wallsEnabled, settings.mode, maxScore);

        HighScore::save(highScoreFile, maxScore);
        EndChoice end = EndScreen::showGameOverAndAskPlayAgain(name, maxScore);
        playAgain = end.playAgain;
        if(playAgain && end.changeSettings) {
            settings = StartScreen::askSettings();
        }
    } while(playAgain);

    EndScreen::sayGoodbye(name);

    return 0;
}
