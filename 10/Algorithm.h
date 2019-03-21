#pragma once
#include "Common.h"
class Algorithm {
public:
    virtual Ways buildWays(size_t n, Distances const & distances, size_t k) = 0;
    Ways splitWay(Way &shortestWay, size_t k);
    virtual ~Algorithm();
};

