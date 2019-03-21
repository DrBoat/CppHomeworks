#pragma once

#include<vector>
#include "Algorithm.h"

class RandomWay final : public Algorithm {
public:
    Ways buildWays(size_t size, Distances const &distances, size_t k) override;

    ~RandomWay() override;
};
