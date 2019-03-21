#pragma once

#include "Point.h"
#include "Common.h"

class Metric {
public:
    virtual ~Metric();

    virtual size_t getMetric(Point first, Point second) = 0;
};