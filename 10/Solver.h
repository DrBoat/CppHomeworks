#pragma once

#include <map>
#include <string>
#include "Common.h"
#include "Algorithm.h"
#include "Metric.h"

class Solver {
public:
    Solver();

    explicit Solver(const size_t &nPoints);

    explicit Solver(const std::vector<Point> &points);

    ~Solver();

    void solve(const std::string &metric, const std::string &algorithm, const size_t &k);

    void print();

private:
    void setDistances(size_t n, Distances &distances, const std::vector<Point> &points, Metric *metric);

    std::map<std::string, Algorithm *> algorithms;
    std::map<std::string, Metric *> metrics;
    size_t nPoints;
    std::vector<Point> points;
    Ways answer;
};

