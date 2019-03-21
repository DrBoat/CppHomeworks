#pragma once

#include "Metric.h"

class Chebyshev final: public Metric{
public:
    size_t getMetric(Point first, Point second) override;
    ~Chebyshev() override;
};