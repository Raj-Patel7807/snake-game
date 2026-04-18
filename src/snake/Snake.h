#pragma once
#include "../utils/Point.h"
#include "../utils/Direction.h"
#include <vector>

class Snake {
private:
    Point head;
    std::vector<Point> tail;

public:
    Snake();

    void move(Direction direction);
    void grow();

    Point getHead() const;
    std::vector<Point> getTail() const;
};
