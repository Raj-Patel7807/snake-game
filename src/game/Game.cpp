#include "Game.h"
#include "../obstacles/ObstacleManager.h"
#include "../powerups/PowerUp.h"
#include "../snake/Snake.h"
#include "../food/Food.h"
#include "../utils/Direction.h"
#include "../config/Config.h"
#include "../utils/Point.h"
#include "../utils/color/Color.h"
#include <vector>
#include <iostream>

using std::cout;

Game::Game() {
    width = 70;
    height = 20;
    score = 0;
    isGameOver = false;
    direction = Direction::STOP;
}

void Game::resetSession() {
    score = 0;
    isGameOver = false;
    direction = Direction::STOP;
}

static bool isOpposite(Direction a, Direction b) {
    return (a == Direction::LEFT && b == Direction::RIGHT) || (a == Direction::RIGHT && b == Direction::LEFT) || (a == Direction::UP && b == Direction::DOWN) || (a == Direction::DOWN && b == Direction::UP);
}

static int maxInt(int a, int b) {
    return (a > b) ? a : b;
}

static std::vector<Point> buildForbiddenCells(const Snake &snake, const ObstacleManager &obstacleMgr) {
    std::vector<Point> forbidden = snake.getCells();
    const std::vector<Point> &obs = obstacleMgr.obstacles();

    for(int i = 0; i < (int) obs.size(); i++) {
        forbidden.push_back(obs[i]);
    }
    return forbidden;
}

void Game::run(const std::string &playerName, int initialDelayMs, bool wallsEnabled, GameMode mode, int &maxScore) {
    Snake snake;
    Food food;
    ObstacleManager obstacleMgr;
    PowerUpManager powerMgr;

    resetSession();
    snake.reset(width, height);

    int delayMs = initialDelayMs;
    bool paused = false;
    bool showHelp = true;
    long long elapsedMs = 0;

    bool shieldActive = false;
    long long slowUntilMs = 0;
    long long ghostUntilMs = 0;

    food.spawn(width, height, buildForbiddenCells(snake, obstacleMgr), elapsedMs);

    while(!isGameOver) {
        system(CLEAR);

        if(!paused) {
            elapsedMs += delayMs;
        }

        if(mode != MODE_CLASSIC) {
            if(score >= 50 && !obstacleMgr.isEnabled()) {
                obstacleMgr.enable();
            }
            if(obstacleMgr.isEnabled()) {
                (void) obstacleMgr.tick(score, elapsedMs, width, height, snake.getCells(), food.getPosition());
            }
        }

        if(!paused && food.isExpired(elapsedMs)) {
            food.spawn(width, height, buildForbiddenCells(snake, obstacleMgr), elapsedMs);
        }

        if(!paused) {
            std::vector<Point> forbidden = buildForbiddenCells(snake, obstacleMgr);

            forbidden.push_back(food.getPosition());
            powerMgr.maybeSpawn(width, height, forbidden, elapsedMs);

            if(powerMgr.isExpired(elapsedMs)) {
                powerMgr.clear();
            }
        }

        cout << "\n\n";
        cout << Color::brightCyan();
        for(int i = 0; i < width + 2; i++) {
            cout << "-";
        }
        cout << Color::reset();
        cout << "\n";

        for(int y = 1; y < height; y++) {
            for(int x = 0; x <= width + 1; x++) {
                if(x == 0 || x == width + 1) {
                    cout << Color::brightCyan() << "|" << Color::reset();
                    continue;
                }

                Point p{x, y};
                if(snake.getHead() == p) cout << Color::brightGreen() << "O" << Color::reset();
                else if(food.getPosition() == p) {
                    if(food.getType() == FOOD_SPECIAL) {
                        cout << Color::brightYellow() << "$" << Color::reset();
                    } else if(food.getType() == FOOD_POISON) {
                        cout << Color::brightRed() << "!" << Color::reset();
                    } else if(food.getType() == FOOD_BONUS_TIMED) {
                        cout << Color::brightCyan() << "*" << Color::reset();
                    } else {
                        cout << Color::yellow() << "@" << Color::reset();
                    }
                } else if(powerMgr.hasActive() && powerMgr.getActive().pos == p) {
                    PowerUp u = powerMgr.getActive();

                    if(u.type == POWER_SHIELD) {
                        cout << Color::cyan() << "S" << Color::reset();
                    } else if(u.type == POWER_SLOW) {
                        cout << Color::blue() << "T" << Color::reset();
                    } else {
                        cout << Color::brightCyan() << "G" << Color::reset();
                    }
                } else {
                    bool printed = false;
                    for(auto &t: snake.getTail()) {
                        if(t == p) {
                            cout << Color::green() << "o" << Color::reset();
                            printed = true;
                            break;
                        }
                    }

                    if(!printed && obstacleMgr.contains(p)) {
                        cout << Color::brightWhite() << "#" << Color::reset();
                        printed = true;
                    }

                    if(!printed) cout << " ";
                }
            }

            if(showHelp) {
                if(y == 2) cout << "       ---------- Legend ----------";
                if(y == 4) cout << "       @ = Normal Fruit (5 points)";
                if(y == 5) cout << "       $ = Special Fruit (20 points)";
                if(y == 6) cout << "       ! = Poison Fruit (-10 points)";
                if(y == 7) cout << "       * = Timed Bonus (+30 points)";
                if(y == 8) cout << "       # = Obstacles (Be Safe!)";
                if(y == 9) cout << "       O = Snake Head | o = Snake Tail";

                if(y == 11) cout << "       ---------- Controls ----------";
                if(y == 12) cout << "       Powerups: S=Shield | T=Slow | G=Ghost";
                if(y == 13) cout << "       W / A / S / D or Arrow Keys = Move";
                if(y == 14) cout << "       P = Pause | R = Resume";
                if(y == 15) cout << "       X = Reset | ESC = Exit";
                if(y == 16) cout << "       H = Toggle Help";
            }

            if(y == 18) cout << "       " << playerName << "'s Score : " << score;
            if(y == 19) {
                cout << "       " << playerName << "'s High Score : " << maxScore;

                if(shieldActive) cout << "   " << Color::cyan() << "[Shield]" << Color::reset();
                if(elapsedMs < slowUntilMs) cout << "   " << Color::blue() << "[Slow]" << Color::reset();
                if(elapsedMs < ghostUntilMs) cout << "   " << Color::brightCyan() << "[Ghost]" << Color::reset();
            }

            cout << "\n";
        }

        cout << Color::brightCyan();
        for(int i = 0; i <= width + 1; i++) cout << "-";
        cout << Color::reset();
        cout << "\n\n";

        if(_kbhit()) {
            int ch = _getch();
            bool isArrowKey = false;

#if defined(_WIN32) || defined(_WIN64)
            if(ch == 0 || ch == 224) {
                ch = _getch();
                if(ch == 72 || ch == 80 || ch == 75 || ch == 77) {
                    isArrowKey = true;
                }
            }
#endif

            if(ch == 27) {
                isGameOver = true;
            } else if(!isArrowKey && (ch == 'p' || ch == 'P')) {
                paused = true;
            } else if(!isArrowKey && (ch == 'r' || ch == 'R')) {
                paused = false;
            } else if(!isArrowKey && (ch == 'h' || ch == 'H')) {
                showHelp = !showHelp;
            } else if(!isArrowKey && (ch == 'x' || ch == 'X')) {
                resetSession();
                paused = false;
                delayMs = initialDelayMs;
                elapsedMs = 0;
                obstacleMgr.reset();
                powerMgr.reset();
                snake.reset(width, height);
                food.spawn(width, height, buildForbiddenCells(snake, obstacleMgr), elapsedMs);
                shieldActive = false;
                slowUntilMs = 0;
                ghostUntilMs = 0;

                for(int c = 3; c >= 1; c--) {
                    system(CLEAR);
                    cout << Color::brightCyan() << "\n\n\n\t\tStarting in " << c << "...\n" << Color::reset();
#if defined(_WIN32) || defined(_WIN64)
                    Sleep(700);
#else
                    usleep(700 * 1000);
#endif
                }
                continue;
            } else if(!paused) {
                Direction next = direction;
                if(ch == 'a' || ch == 'A' || ch == 75) next = Direction::LEFT;
                else if(ch == 'd' || ch == 'D' || ch == 77) next = Direction::RIGHT;
                else if(ch == 'w' || ch == 'W' || ch == 72) next = Direction::UP;
                else if(ch == 's' || ch == 'S' || ch == 80) next = Direction::DOWN;

                if(direction == Direction::STOP) {
                    if(next == Direction::UP || next == Direction::DOWN || next == Direction::RIGHT) direction = next;
                } else if(!isOpposite(direction, next)) {
                    direction = next;
                }
            }
        }

        if(!paused && direction != Direction::STOP) {
            snake.move(direction);

            Point head = snake.getHead();
            bool shieldUsedThisFrame = false;
            bool ghostActive = (elapsedMs < ghostUntilMs);

            if(wallsEnabled) {
                if(head.x >= width || head.x <= 0 || head.y >= height || head.y <= 0) {
                    if(ghostActive) {
                        if(head.x >= width) head.x = 1;
                        else if(head.x <= 0) head.x = width - 1;
                        if(head.y >= height) head.y = 1;
                        else if(head.y <= 0) head.y = height - 1;
                        snake.setHead(head);
                    }
                    if(shieldActive) {
                        shieldActive = false;
                        shieldUsedThisFrame = true;
                        if(head.x >= width) head.x = width - 1;
                        else if(head.x <= 0) head.x = 1;
                        if(head.y >= height) head.y = height - 1;
                        else if(head.y <= 0) head.y = 1;
                        snake.setHead(head);
                    } else {
                        if(!ghostActive) isGameOver = true;
                    }
                }
            } else {
                if(head.x >= width) head.x = 1;
                else if(head.x <= 0) head.x = width - 1;
                if(head.y >= height) head.y = 1;
                else if(head.y <= 0) head.y = height - 1;
                snake.setHead(head);
            }

            if(!shieldUsedThisFrame) {
                for(const auto &t: snake.getTail()) {
                    if(t == snake.getHead()) {
                        isGameOver = true;
                        break;
                    }
                }
            }

            if(powerMgr.hasActive() && powerMgr.getActive().pos == snake.getHead()) {
                PowerUp u = powerMgr.getActive();
                if(u.type == POWER_SHIELD) shieldActive = true;
                else if(u.type == POWER_SLOW) slowUntilMs = elapsedMs + 8000;
                else if(u.type == POWER_GHOST) ghostUntilMs = elapsedMs + 8000;
                powerMgr.clear();
            }

            ghostActive = (elapsedMs < ghostUntilMs);

            if(!ghostActive && obstacleMgr.isEnabled() && obstacleMgr.contains(snake.getHead())) {
                if(shieldActive) shieldActive = false;
                else isGameOver = true;
            }

            if(snake.getHead() == food.getPosition()) {
                if(food.getType() == FOOD_SPECIAL) score += 20;
                else if(food.getType() == FOOD_NORMAL) score += 5;
                else if(food.getType() == FOOD_POISON) {
                    score -= 10;
                    if(score < 0) score = 0;
                    snake.shrink(2);
                } else if(food.getType() == FOOD_BONUS_TIMED) {
                    score += 30;
                }

                if(score > maxScore) maxScore = score;
                if(food.getType() == FOOD_NORMAL || food.getType() == FOOD_SPECIAL || food.getType() == FOOD_BONUS_TIMED) {
                    snake.grow();
                }
                food.spawn(width, height, buildForbiddenCells(snake, obstacleMgr), elapsedMs);

                if(score % 25 == 0) delayMs = maxInt(50, delayMs - 10);
            }
        }

        if(!paused && mode == MODE_SURVIVAL) {
            if(elapsedMs % 10000 < delayMs) {
                delayMs = maxInt(50, delayMs - 5);
            }
        }

#if defined(_WIN32) || defined(_WIN64)
        int realDelay = delayMs;
        if(elapsedMs < slowUntilMs) realDelay += 140;
        Sleep(realDelay);
#else
        int realDelay = delayMs; if(elapsedMs < slowUntilMs) realDelay += 140; usleep(realDelay * 1000);
#endif
    }
}
