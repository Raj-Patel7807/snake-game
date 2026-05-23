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

    void reset(int boardWidth, int boardHeight);

    void move(Direction direction);

    void grow();

    void shrink(int count);

    void setHead(Point p);

    Point getHead() const;

    std::vector<Point> getTail() const;

    std::vector<Point> getCells() const;

    bool occupies(const Point &p) const;
};
