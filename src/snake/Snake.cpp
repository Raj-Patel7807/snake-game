#include "Snake.h"

Snake::Snake() {
    head = {10, 10};
}

void Snake::move(Direction direction) {
    if(!tail.empty()) {
        for(int i = tail.size() - 1; i > 0; i--) {
            tail[i] = tail[i - 1];
        }

        tail[0] = head;
    }

    switch(direction) {
        case Direction::LEFT: head.x--; break;
        case Direction::RIGHT: head.x++; break;
        case Direction::UP: head.y--; break;
        case Direction::DOWN: head.y++; break;
    }
}

void Snake::grow() {
    if(!tail.empty()) {
        tail.push_back(tail.back());
    } else {
        tail.push_back(head);
    }
}

Point Snake::getHead() const {
    return head;
}

std::vector<Point> Snake::getTail() const {
    return tail;
}
