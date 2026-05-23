#include "PowerUp.h"
#include <cstdlib>

static bool containsPts(const std::vector<Point> &pts, const Point &p) {
    for(int i = 0; i < (int) pts.size(); i++) {
        if(pts[i] == p) return true;
    }
    return false;
}

void PowerUpManager::reset() {
    active = false;
}

bool PowerUpManager::hasActive() const {
    return active;
}

PowerUp PowerUpManager::getActive() const {
    return current;
}

void PowerUpManager::clear() {
    active = false;
}

bool PowerUpManager::isExpired(long long elapsedMs) const {
    if(!active) return false;
    if(current.ttlMs <= 0) return false;
    return (elapsedMs - current.spawnTimeMs) >= current.ttlMs;
}

void PowerUpManager::maybeSpawn(int boardWidth, int boardHeight, const std::vector<Point> &forbidden, long long elapsedMs) {
    if(active) return;

    int r = rand() % 1000;
    if(r > 6) return; // ~0.7%

    PowerUp p{};
    p.spawnTimeMs = elapsedMs;
    p.ttlMs = 10000; // 10 sec to pick it up

    int t = rand() % 3;
    if(t == 0) p.type = POWER_SHIELD;
    else if(t == 1) p.type = POWER_SLOW;
    else p.type = POWER_GHOST;

    for(int tries = 0; tries < 5000; tries++) {
        p.pos.x = 1 + rand() % (boardWidth - 2);
        p.pos.y = 1 + rand() % (boardHeight - 2);
        if(!containsPts(forbidden, p.pos)) {
            current = p;
            active = true;
            return;
        }
    }
}
