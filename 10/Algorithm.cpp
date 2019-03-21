#include "Algorithm.h"

Ways Algorithm::splitWay(Way &shortestWay, size_t k) {
    Ways routes;
    while (shortestWay.size() >= k) {
        Way route(shortestWay.begin(), shortestWay.begin() + k);
        routes.push_back(route);
        shortestWay.erase(shortestWay.begin(), shortestWay.begin() + k);
    }
    routes.push_back(Way(shortestWay.begin(), shortestWay.end())); //
    return routes;
}

Algorithm::~Algorithm() = default;