#include "ObstacleManager.h"
#include <cstdlib>

void ObstacleManager::reset() {
    enabled = false;
    lastRegenMs = 0;
    lastMoveMs = 0;
    lastTargetCount = 0;
    obstacleCells.clear();
}

void ObstacleManager::enable() {
    enabled = true;
}

bool ObstacleManager::isEnabled() const {
    return enabled;
}

const std::vector<Point> &ObstacleManager::obstacles() const {
    return obstacleCells;
}

bool ObstacleManager::contains(const Point &p) const {
    for (const auto &o: obstacleCells) {
        if (o == p) return true;
    }
    return false;
}

bool ObstacleManager::tick(int score, long long elapsedMs, int boardWidth, int boardHeight,
                           const std::vector<Point> &snakeCells, const Point &foodPos) {
    if (!enabled) return false;

    const long long regenEveryMs = 10000;

    int scoreBased = 5 + ((score - 50) / 20) * 3;
    if (scoreBased < 5) scoreBased = 5;

    int timeBased = (int) (elapsedMs / 15000); // +1 every 15s
    if (timeBased > 20) timeBased = 20; // cap to avoid impossible boards

    int targetCount = scoreBased + timeBased;
    if (targetCount < 0) targetCount = 0;

    bool dueToTime = (elapsedMs - lastRegenMs) >= regenEveryMs;
    bool dueToGrowth = targetCount != lastTargetCount;

    if (obstacleCells.empty() || dueToTime || dueToGrowth) {
        regenerate(score, elapsedMs, boardWidth, boardHeight, snakeCells, foodPos);
        lastRegenMs = elapsedMs;
        lastTargetCount = targetCount;
        return true;
    }

    moveSomeObstacles(elapsedMs, boardWidth, boardHeight, snakeCells, foodPos);
    return false;
}

void ObstacleManager::moveSomeObstacles(long long elapsedMs, int boardWidth, int boardHeight,
                                        const std::vector<Point> &snakeCells, const Point &foodPos) {
    if (elapsedMs - lastMoveMs < 700) return;
    lastMoveMs = elapsedMs;

    int moves = (int) obstacleCells.size() / 10;
    if (moves < 1) moves = 1;
    if (moves > 3) moves = 3;

    for (int m = 0; m < moves; m++) {
        if (obstacleCells.empty()) return;
        int idx = rand() % (int) obstacleCells.size();
        Point p = obstacleCells[idx];

        int dir = rand() % 4;
        Point np = p;
        if (dir == 0) np.x++;
        else if (dir == 1) np.x--;
        else if (dir == 2) np.y++;
        else np.y--;

        if (np.x <= 0 || np.x >= boardWidth) continue;
        if (np.y <= 0 || np.y >= boardHeight) continue;

        bool ok = true;
        if (np == foodPos) ok = false;
        for (int i = 0; i < (int) snakeCells.size() && ok; i++) {
            if (snakeCells[i] == np) ok = false;
        }
        for (int i = 0; i < (int) obstacleCells.size() && ok; i++) {
            if (i != idx && obstacleCells[i] == np) ok = false;
        }

        if (ok) obstacleCells[idx] = np;
    }
}

void ObstacleManager::regenerate(int score, long long elapsedMs, int boardWidth, int boardHeight,
                                 const std::vector<Point> &snakeCells, const Point &foodPos) {
    int scoreBased = 5 + ((score - 50) / 20) * 3;
    if (scoreBased < 5) scoreBased = 5;

    int timeBased = (int) (elapsedMs / 15000);
    if (timeBased > 20) timeBased = 20;

    int numObstacles = scoreBased + timeBased;

    if ((int) obstacleCells.size() > numObstacles) {
        obstacleCells.resize(numObstacles);
    }

    while ((int) obstacleCells.size() < numObstacles) {
        Point p{};
        bool valid = false;

        for (int tries = 0; tries < 2000 && !valid; tries++) {
            p.x = 1 + rand() % (boardWidth - 2);
            p.y = 1 + rand() % (boardHeight - 2);

            valid = true;
            if (p == foodPos) valid = false;

            for (const auto &s: snakeCells) {
                if (s == p) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                for (const auto &o: obstacleCells) {
                    if (o == p) {
                        valid = false;
                        break;
                    }
                }
            }
        }

        if (valid) obstacleCells.push_back(p);
    }
}
