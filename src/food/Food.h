#pragma once
#include "../utils/Point.h"

class Food {
private:
    Point position;

public:
    void spawn(int width, int height);
    Point getPosition() const;
};
