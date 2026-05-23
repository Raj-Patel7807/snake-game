#include "Food.h"
#include <cstdlib>

static bool contains(const std::vector<Point> &pts, const Point &p) {
    for(const auto &x: pts) {
        if(x == p) {
            return true;
        }
    }
    return false;
}

void Food::spawn(int width, int height, const std::vector<Point> &forbidden, long long elapsedMs) {
    int r = rand() % 100;

    if(r < 70) {
        type = FOOD_NORMAL;
    } else if(r < 85) {
        type = FOOD_SPECIAL;
    } else if(r < 92) {
        type = FOOD_POISON;
    } else {
        type = FOOD_BONUS_TIMED;
    }

    spawnTimeMs = elapsedMs;
    ttlMs = 0;
    if(type == FOOD_BONUS_TIMED) {
        ttlMs = 7000; // 7 Seconds
    }

    Point p{};

    for(int tries = 0; tries < 5000; tries++) {
        p.x = 1 + rand() % (width - 2);
        p.y = 1 + rand() % (height - 2);

        if(!contains(forbidden, p)) {
            position = p;
            return;
        }
    }

    position = p;
}

Point Food::getPosition() const {
    return position;
}

FoodType Food::getType() const {
    return type;
}

bool Food::isExpired(long long elapsedMs) const {
    if(type != FOOD_BONUS_TIMED) {
        return false;
    }
    if(ttlMs <= 0) {
        return false;
    }
    return (elapsedMs - spawnTimeMs) >= ttlMs;
}
