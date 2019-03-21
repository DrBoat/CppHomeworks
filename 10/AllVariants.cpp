#include <algorithm>
#include <climits>
#include "AllVariants.h"

Ways AllVariants::buildWays(size_t size, Distances const &distances, size_t k) {
    std::vector<size_t> permutation(size);
    for (size_t i = 0; i < permutation.size(); ++i) {
        permutation[i] = i;
    }
    Way shortestWay = permutation;
    int minDistance = INT_MAX;
    do {
        int curDistance = 0;
        for (size_t i = 1; i < permutation.size(); ++i) {
            curDistance += distances[permutation[i - 1]][permutation[i]];
        }
        if (curDistance < minDistance) {
            minDistance = curDistance;
            shortestWay = permutation;
        }
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return splitWay(shortestWay, k);
}

AllVariants::~AllVariants() = default;