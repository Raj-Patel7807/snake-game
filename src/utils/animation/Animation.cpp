#include "Animation.h"
#include <iostream>
#include "../../config/Config.h"

void animation(string name) {
    system(CLEAR);

    cout << "\n\n\n";
    cout << "          *************************************************************************\n\n";
    cout << "                                      S N A K E  G A M E\n\n";
    cout << "                                      Get Ready, " << name << "..!!\n\n";
    cout << "          *************************************************************************\n\n\n\n\n\n\n";

    cout << "                                    L O A D I N G ";
    
    for (int i = 0; i < 5; i++) {
        cout << "." << flush;

        #if defined(_WIN32) || defined(_WIN64)
            Sleep(700);
        #else
             usleep(750 * 1000);
        #endif
    }

    for (int i = 3; i >= 0; i--) {
        system(CLEAR);

        cout << "\n\n\n\n\n";
        cout << "\r                                    Starting in:\n\n\n";

        if(i == 3) {
            cout << R"(
                                         ____
                                        |___ \ 
                                          __) |  
                                         |__ <    
                                         ___) |    
                                        |____/     
            )" << flush;
        } else if(i == 2) {
            cout << R"(
                                        ______
                                       / ____ \
                                       \/   / /
                                           / / 
                                          / /___
                                         /______| 
            )" << flush;
        } else if(i == 1) {
            cout << R"(
                                          _ 
                                         / |
                                         | |
                                         | |
                                         | |
                                         |_|
            )" << flush;
        } else {
            system(CLEAR);
            cout << "\n\n\n\n\n\n" R"(
                          _____   _______      __      _____     _______ 
                         / ____| |_______|    /  \     |  __ \  |_______|
                        | (___      | |      / _  \    | |__) |    | |
                         \___ \     | |     / / \  \   |  _  /     | |
                         ____) |    | |    /  ____  \  | | \ \     | |
                        |_____/     |_|   /__/    \__\ |_|  \_\    |_|
            )" << flush;
        }

        #if defined(_WIN32) || defined(_WIN64)
            Sleep(900);
        #else
             usleep(950 * 1000);
        #endif
    }
}
