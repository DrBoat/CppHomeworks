#include "Point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const int &x, const int &y) : x(x), y(y) {}

void Point::setX(int x) {
    this->x = x;
}

void Point::setY(int y) {
    this->y = y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

Point::~Point() = default;