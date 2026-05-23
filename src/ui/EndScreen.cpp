#include "EndScreen.h"
#include "../config/Config.h"
#include "../utils/color/Color.h"
#include <iostream>

static void printGameOverHeader(int maxScore) {
    system(CLEAR);

    std::cout << Color::brightRed() << "\n\n\n";
    std::cout << R"(
                              _____                         ____                 
                             / ____|                       / __ \
                            | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ 
                            | | |_ |/ _` | '_ ` _ \ / _ \ | |  | \ \ / / _ \ '__|
                            | |__| | (_| | | | | | |  __/ | |__| |\ V /  __/ |   
                             \_____|\__,_|_| |_| |_|\___|  \____/  \_/ \___|_|   
        )" << Color::reset() << "\n\n\n";

    std::cout << Color::brightRed() << "                                        G A M E  O V E R  ! ! !\n" << Color::reset();
    std::cout << "\n";
    std::cout << Color::brightYellow() << "Your Highest Score : " << Color::reset() << maxScore << "\n\n";
}

EndChoice EndScreen::showGameOverAndAskPlayAgain(const std::string & /*playerName*/, int maxScore) {
    EndChoice out{};

    printGameOverHeader(maxScore);
    std::cout << "Do You Want To Play Again..?\n\n";
    std::cout << "NOTE : If You Press Key Other Than 0 or 1 Then Computer will treat it as 0..\n";
    std::cout << Color::brightYellow() << "Enter 1 For \"YES\" and 0 For \"NO\" : " << Color::reset();

    int play = 0;
    std::cin >> play;
    out.playAgain = (play == 1 || play == 49);

    if(!out.playAgain) {
        out.changeSettings = false;
        return out;
    }

    printGameOverHeader(maxScore);
    std::cout << "Do You Want To Change Game Settings..?\n\n";
    std::cout << Color::brightYellow() << "Enter 1 For \"YES\" and 0 For \"NO\" : " << Color::reset();
    int change = 0;
    std::cin >> change;
    out.changeSettings = (change == 1 || change == 49);
    return out;
}

void EndScreen::sayGoodbye(const std::string &playerName) {
    std::cout << Color::brightCyan() << "\n\n\n\n\nOkay, Byee...  " << Color::reset();
    std::cout << "Thank You " << Color::brightYellow() << playerName << Color::reset() << " For Playing Our Game..!!\n\n\n\n";
}
