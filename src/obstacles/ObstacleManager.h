#pragma once

#include "../utils/Point.h"
#include <vector>

class ObstacleManager {
public:
    void reset();

    void enable();

    bool isEnabled() const;

    bool tick(int score, long long elapsedMs, int boardWidth, int boardHeight,
              const std::vector<Point> &snakeCells, const Point &foodPos);

    const std::vector<Point> &obstacles() const;

    bool contains(const Point &p) const;

private:
    void regenerate(int score, long long elapsedMs, int boardWidth, int boardHeight,
                    const std::vector<Point> &snakeCells, const Point &foodPos);

    void moveSomeObstacles(long long elapsedMs, int boardWidth, int boardHeight,
                           const std::vector<Point> &snakeCells, const Point &foodPos);

    bool enabled = false;
    long long lastRegenMs = 0;
    long long lastMoveMs = 0;
    int lastTargetCount = 0;
    std::vector<Point> obstacleCells;
};
