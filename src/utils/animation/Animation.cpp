#include "Animation.h"
#include <iostream>
#include "../../config/Config.h"
#include "../color/Color.h"

using std::cout;
using std::flush;

void animation(std::string name) {
    system(CLEAR);

    cout << Color::brightCyan() << "\n\n\n";
    cout << "          *************************************************************************\n\n";
    cout << "                                      S N A K E  G A M E\n\n";
    cout << Color::brightYellow() << "                                      Get Ready, " << name << "..!!\n\n" << Color::brightCyan();
    cout << "          *************************************************************************\n\n\n\n\n\n\n" << Color::reset();

    cout << Color::brightBlue() << "                                    L O A D I N G " << Color::reset();

    for(int i = 0; i < 5; i++) {
        cout << Color::brightBlue() << "." << Color::reset() << flush;

#if defined(_WIN32) || defined(_WIN64)
        Sleep(700);
#else
        usleep(750 * 1000);
#endif
    }

    for(int i = 3; i >= 0; i--) {
        system(CLEAR);

        cout << Color::brightCyan() << "\n\n\n\n\n";
        cout << "\r                                    Starting in:\n\n\n" << Color::reset();

        if(i == 3) {
            cout << Color::brightYellow() << R"(
                                         ____
                                        |___ \
                                          __) |  
                                         |__ <    
                                         ___) |    
                                        |____/     
            )" << Color::reset() << flush;
        } else if(i == 2) {
            cout << Color::brightYellow() << R"(
                                        ______
                                       / ____ \
                                       \/   / /
                                           / / 
                                          / /___
                                         /______| 
            )" << Color::reset() << flush;
        } else if(i == 1) {
            cout << Color::brightYellow() << R"(
                                          _ 
                                         / |
                                         | |
                                         | |
                                         | |
                                         |_|
            )" << Color::reset() << flush;
        } else {
            system(CLEAR);
            cout << Color::brightGreen() << "\n\n\n\n\n\n" R"(
                          _____   _______      __      _____     _______ 
                         / ____| |_______|    /  \     |  __ \  |_______|
                        | (___      | |      / _  \    | |__) |    | |
                         \___ \     | |     / / \  \   |  _  /     | |
                         ____) |    | |    /  ____  \  | | \ \     | |
                        |_____/     |_|   /__/    \__\ |_|  \_\    |_|
            )" << Color::reset() << flush;
        }

#if defined(_WIN32) || defined(_WIN64)
        Sleep(900);
#else
        usleep(950 * 1000);
#endif
    }
}
