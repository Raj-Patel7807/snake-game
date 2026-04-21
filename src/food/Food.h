#pragma once
#include "../utils/Point.h"
#include <vector>

enum FoodType {
    FOOD_NORMAL = 1,
    FOOD_SPECIAL = 2,
    FOOD_POISON = 3,
    FOOD_BONUS_TIMED = 4
};

class Food {
private:
    Point position;
    FoodType type = FOOD_NORMAL;
    long long spawnTimeMs = 0;
    int ttlMs = 0;

public:
    void spawn(int width, int height, const std::vector<Point>& forbidden, long long elapsedMs);

    Point getPosition() const;

    FoodType getType() const;

    bool isExpired(long long elapsedMs) const;
};
