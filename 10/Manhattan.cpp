#include <algorithm>
#include "Manhattan.h"

size_t Manhattan::getMetric(Point first, Point second) {
    return static_cast<size_t>(abs(first.getX() - second.getX()) + abs(first.getY() - second.getY()));
}

Manhattan::~Manhattan() = default;