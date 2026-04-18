#include "Game.h"
#include "../snake/Snake.h"
#include "../food/Food.h"
#include "../utils/input/Input.h"
#include "../utils/Direction.h"
#include "../config/Config.h"
#include <iostream>

using namespace std;

Game::Game() {
    width = 40;
    height = 20;
    score = 0;
    isGameOver = false;
    Dir = Direction::STOP;
}

void Game::run() {
    Snake snake;
    Food food;

    food.spawn(width, height);

    while (!isGameOver) {
        system(CLEAR);

        // draw boundary
        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << "\n";

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                if (j == 0) cout << "#";

                if (i == snake.getHead().y && j == snake.getHead().x)
                    cout << "O";
                else if (i == food.getPosition().y && j == food.getPosition().x)
                    cout << "F";
                else {
                    bool printed = false;
                    for (auto &t : snake.getTail()) {
                        if (t.y == i && t.x == j) {
                            cout << "o";
                            printed = true;
                            break;
                        }
                    }
                    if (!printed) cout << " ";
                }

                if (j == width - 1) cout << "#";
            }
            cout << "\n";
        }

        for (int i = 0; i < width + 2; i++) cout << "#";
        cout << "\nScore: " << score << endl;

        // input
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': Dir = Direction::LEFT; break;
                case 'd': Dir = Direction::RIGHT; break;
                case 'w': Dir = Direction::UP; break;
                case 's': Dir = Direction::DOWN; break;
                case 'x': isGameOver = true; break;
            }
        }

        snake.move(Dir);

        // collision with food
        if (snake.getHead().x == food.getPosition().x && snake.getHead().y == food.getPosition().y) {
            score += 10;
            snake.grow();
            food.spawn(width, height);
        }

        // wall collision
        if (snake.getHead().x >= width || snake.getHead().x < 0 || snake.getHead().y >= height || snake.getHead().y < 0)
            isGameOver = true;

        // self collision
        for (auto &t : snake.getTail()) {
            if (t.x == snake.getHead().x && t.y == snake.getHead().y)
                isGameOver = true;
        }

        #if defined(_WIN32) || defined(_WIN64)
            Sleep(100);
        #else
            usleep(100000);
        #endif
    }
}
