#pragma once

#include "../utils/Point.h"
#include <vector>

enum PowerUpType {
    POWER_SHIELD = 1,
    POWER_SLOW = 2,
    POWER_GHOST = 3
};

struct PowerUp {
    Point pos;
    PowerUpType type;
    long long spawnTimeMs;
    int ttlMs;
};

class PowerUpManager {
public:
    void reset();

    void maybeSpawn(int boardWidth, int boardHeight, const std::vector<Point> &forbidden, long long elapsedMs);

    bool hasActive() const;

    PowerUp getActive() const;

    void clear();

    bool isExpired(long long elapsedMs) const;

private:
    bool active = false;
    
    PowerUp current{};
};

