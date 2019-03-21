#include <algorithm>
#include "Chebyshev.h"

size_t Chebyshev::getMetric(Point first, Point second) {
    return static_cast<size_t>(std::max(abs(first.getX() - second.getX()), abs(first.getY() - second.getY())));
}

Chebyshev::~Chebyshev() = default;
