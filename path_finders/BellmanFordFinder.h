#ifndef GRAPHS_PATH_FINDERS_BELLMANFORDFINDER_H_
#define GRAPHS_PATH_FINDERS_BELLMANFORDFINDER_H_

#include <vector>
#include <optional>
#include "IPathFinder.h"

class BellmanFordFinder : public virtual IPathFinder {
public:
    int findPath(int vertex1, int vertex2, std::shared_ptr<IGraph> graph) const override {
        int n = graph->getVertexCount();
        std::vector<std::optional<int>> paths_cost(n, std::nullopt);
        paths_cost[vertex1] = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (const auto& edge : graph->getEdges()) {
                if (paths_cost[edge.vertex1].has_value()) {
                    if (!paths_cost[edge.vertex2].has_value() ||
                        (paths_cost[edge.vertex2].has_value() &&
                         paths_cost[edge.vertex2].value() >
                             paths_cost[edge.vertex1].value() + edge.weight)) {
                        paths_cost[edge.vertex2] = paths_cost[edge.vertex1].value() + edge.weight;
                    }
                }
                if (paths_cost[edge.vertex2].has_value()) {
                    if (!paths_cost[edge.vertex1].has_value() ||
                        (paths_cost[edge.vertex1].has_value() &&
                         paths_cost[edge.vertex1].value() >
                             paths_cost[edge.vertex2].value() + edge.weight)) {
                        paths_cost[edge.vertex1] = paths_cost[edge.vertex2].value() + edge.weight;
                    }
                }
            }
        }
        return paths_cost[vertex2].value();
    }
};

#endif  // GRAPHS_PATH_FINDERS_BELLMANFORDFINDER_H_
