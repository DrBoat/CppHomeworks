#pragma once
#include "Metric.h"

class Eucledian final : public Metric {
public:
    size_t getMetric(Point first, Point second) override;
    ~Eucledian() override;
};