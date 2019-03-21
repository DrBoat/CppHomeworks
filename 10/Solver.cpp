#include "Solver.h"
#include "Eucledian.h"
#include "Chebyshev.h"
#include "Manhattan.h"
#include "NeareastPoint.h"
#include "AllVariants.h"
#include "RandomWay.h"
#include <iostream>
#include <cassert>

#define setValueMap metrics["euclidean"] = new Eucledian();\
                    metrics["manhattan"] = new Manhattan();\
                    metrics["chebyshev"] = new Chebyshev();\
                    algorithms["random"] = new RandomWay();\
                    algorithms["all"] = new AllVariants();\
                    algorithms["near"] = new NeareastPoint();

Solver::Solver() : nPoints(0), points(0), answer(0) {
    setValueMap;
}

Solver::Solver(const size_t &nPoints) : nPoints(nPoints), points(nPoints, Point()) {
    setValueMap;
}

Solver::Solver(const std::vector<Point> &points) : nPoints(points.size()), points(points), answer(0) {
    setValueMap;
}

void Solver::solve(const std::string &metric, const std::string &algorithm, const size_t &k) {
    Distances distances(nPoints);
    assert(metrics.find(metric) != metrics.end());
    setDistances(nPoints, distances, points, metrics[metric]);
    assert(algorithms.find(algorithm) != algorithms.end());
    answer = algorithms[algorithm]->buildWays(nPoints, distances, k);
}

void Solver::print() {
    if (answer.back().empty()) {
        answer.pop_back();
    }
    for (size_t i = 0; i < answer.size(); ++i) {
        std::cout << i + 1 << " Way:" << std::endl;
        for (size_t aj : answer[i]) {
            std::cout << aj + 1 << " ";
        }
        std::cout << std::endl;
    }
}

void Solver::setDistances(size_t n, Distances &distances, const std::vector<Point> &points, Metric *metric) {
    for (size_t i = 0; i < distances.size(); ++i) {
        distances[i].resize(n);
        for (size_t j = 0; j < distances[i].size(); ++j) {
            if (i != j) {
                distances[i][j] = metric->getMetric(points[i], points[j]);
            } else {
                distances[i][j] = 0;
            }
        }
    }
}

Solver::~Solver() = default;
