#include "RandomWay.h"
#include <algorithm>
#include <random>
#include <ctime>

Ways RandomWay::buildWays(size_t size, Distances const &distances, size_t k) {
    std::vector<bool> visited(size, false);
    Way shortestWay;
    std::vector<size_t> inds(size);
    for (size_t i = 0; i < inds.size(); ++i) {
        inds[i] = i;
    }
    visited[0] = true;
    std::mt19937 gen;
    gen.seed(static_cast<unsigned int>(time(nullptr)));
    size_t ind = gen() % size;
    std::sort(inds.begin(), inds.end(), [distances, ind](size_t &left, size_t &right) {
        return distances[ind][left] < distances[ind][right];
    });
    for (size_t &indI : inds) {
        shortestWay.push_back(static_cast<size_t &&>(indI));
    }
    return splitWay(shortestWay, k);
}

RandomWay::~RandomWay() = default;
