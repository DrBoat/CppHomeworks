#pragma once
#include "Metric.h"

class Manhattan final : public Metric {
public:
    size_t getMetric(Point first, Point second) override;
    ~Manhattan() override;
};