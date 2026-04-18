#include "Food.h"
#include <cstdlib>

void Food::spawn(int width, int height) {
    position.x = rand() % width;
    position.y = rand() % height;
}

Point Food::getPosition() const {
    return position;
}
