#ifndef GRAPHS__PATHFINDERTESTER_H_
#define GRAPHS__PATHFINDERTESTER_H_

#include <iostream>
#include <chrono>
#include "path_finders/IPathFinder.h"
#include "config.h"

class PathFinderTester {
public:
    uint64_t getAverageExecutionTime(const std::shared_ptr<IPathFinder> path_finder,
                                    const std::shared_ptr<IGraph> graph) {
        uint64_t total_time = 0;
        auto [vertex1, vertex2] = twoRandomVertices(graph);
        for (int i = 0; i < kTestCount; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
            path_finder->findPath(vertex1, vertex2, graph);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            total_time += std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
        }
        return total_time / kTestCount;
    }

private:
    std::pair<int, int> twoRandomVertices(const std::shared_ptr<IGraph> graph) {
        return {0, graph->getVertexCount() - 1};
    }
};

#endif  // GRAPHS__PATHFINDERTESTER_H_
