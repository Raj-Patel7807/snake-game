#include "Snake.h"

Snake::Snake() {
    head = {10, 10};
}

void Snake::reset(int boardWidth, int boardHeight) {
    head = {boardWidth / 2, boardHeight / 2};
    tail.clear();

    tail.push_back({head.x - 1, head.y});
    tail.push_back({head.x - 2, head.y});
}

void Snake::move(Direction direction) {
    if (!tail.empty()) {
        for (int i = tail.size() - 1; i > 0; i--) {
            tail[i] = tail[i - 1];
        }

        tail[0] = head;
    }

    switch (direction) {
        case Direction::LEFT: head.x--;
            break;
        case Direction::RIGHT: head.x++;
            break;
        case Direction::UP: head.y--;
            break;
        case Direction::DOWN: head.y++;
            break;
        case Direction::STOP: break;
    }
}

void Snake::grow() {
    if (!tail.empty()) {
        tail.push_back(tail.back());
    } else {
        tail.push_back(head);
    }
}

void Snake::shrink(int count) {
    if (count <= 0) return;
    while (count > 0 && !tail.empty()) {
        tail.pop_back();
        count--;
    }
}

void Snake::setHead(Point p) {
    head = p;
}

Point Snake::getHead() const {
    return head;
}

std::vector<Point> Snake::getTail() const {
    return tail;
}

std::vector<Point> Snake::getCells() const {
    std::vector<Point> cells;
    cells.reserve(1 + tail.size());
    cells.push_back(head);
    for (const auto &t: tail) cells.push_back(t);
    return cells;
}

bool Snake::occupies(const Point &p) const {
    if (head == p) return true;
    for (const auto &t: tail) {
        if (t == p) return true;
    }
    return false;
}
