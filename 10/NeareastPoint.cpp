#include <climits>
#include "NeareastPoint.h"

Ways NeareastPoint::buildWays(size_t size, Distances const &distances, size_t k) {
    std::vector<bool> visited(size, false);
    Way shortestWay;
    visited[0] = true;
    shortestWay.push_back(0);
    while (shortestWay.size() < size) {
        size_t minDistance = INT_MAX;
        size_t minInd = 0;
        for (size_t v = 0; v < visited.size(); ++v) {
            if (!visited[v]) {
                if (distances[shortestWay.front()][v] < minDistance) {
                    minDistance = distances[shortestWay.front()][v];
                    minInd = v;
                }
                if (distances[shortestWay.back()][v] < minDistance) {
                    minDistance = distances[shortestWay.back()][v];
                    minInd = v;
                }
            }
        }
        if (distances[shortestWay.front()][minInd] < distances[shortestWay.back()][minInd]) {
            shortestWay.insert(shortestWay.begin(), minInd);
        } else {
            shortestWay.push_back(minInd);
        }
        visited[minInd] = true;
    }

    return splitWay(shortestWay, k);
}

NeareastPoint::~NeareastPoint() = default;