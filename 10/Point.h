#pragma once

#include "Common.h"

class Point {
public:
    Point();

    ~Point();

    Point(const int &x, const int &y);

    void setX(int x);

    void setY(int y);

    int getX();

    int getY();

private:
    int x;
    int y;
};