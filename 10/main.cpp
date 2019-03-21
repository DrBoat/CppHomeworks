#include <iostream>
#include <fstream>
#include <cassert>
#include "Solver.h"
#include "RandomWay.h"

using std::cout, std::endl, std::cerr;

int main() {
    /*
     * There are settings in "/cmake-build-debug" directory
     *
     * Commands for algorithms: all, random, near
     * Commands for metrics: euclidean, manhattan, chebyshev
     *
     * Count of points >= 0
     * k >= 0
     */
    std::fstream cin;
    std::string metric, algorithm;
    try {
        cin.open("settings.txt");
        cin >> algorithm >> metric;
        cin.close();
    } catch (std::exception &e) {
        cerr << e.what();
        cin.close();
    }
    cout << "Metric: " << metric << endl << "Algorithm: " << algorithm << endl;
    size_t n, k;
    n = k = 0;
    std::vector<Point> points;
    try {
        cin.open("test.txt");
        cin >> n >> k;
        for(size_t i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        cin.close();
    } catch (std::exception &e) {
        cerr << e.what();
        cin.close();
    }
    assert(n >= 0);
    assert(k >= 0);
    Solver solver(points);
    solver.solve(metric, algorithm, k);
    solver.print();
    return 0;
}