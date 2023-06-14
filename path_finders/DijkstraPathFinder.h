#ifndef GRAPHS__DIJKSTRAPATHFINDER_H_
#define GRAPHS__DIJKSTRAPATHFINDER_H_

#include <vector>
#include <optional>
#include <set>
#include "IPathFinder.h"
#include "../graphs/AdjacencyListGraph.h"

class DijkstraPathFinder : public virtual IPathFinder {
public:
    int findPath(int vertex1, int vertex2, std::shared_ptr<IGraph> graph) const override {
        AdjacencyListGraph adjacency_list_graph(graph);
        std::vector<std::optional<int>> paths_cost(graph->getVertexCount(), std::nullopt);
        paths_cost[vertex1] = 0;
        std::set<int> in_processing;
        in_processing.insert(vertex1);
        while (!in_processing.empty()) {
            size_t current_vertex = *in_processing.begin();
            int cost_to_current = paths_cost[current_vertex].value();
            in_processing.erase(in_processing.begin());
            for (const auto& arrow : adjacency_list_graph.getArrowsForVertex(current_vertex)) {
                int vertex = arrow.to;
                if (!paths_cost[vertex].has_value() ||
                    (paths_cost[vertex].has_value() &&
                     paths_cost[vertex].value() > cost_to_current + arrow.weight)) {
                    paths_cost[vertex] = cost_to_current + arrow.weight;
                    in_processing.insert(vertex);
                }
            }
        }
        return paths_cost[vertex2].value();
    }
};

#endif  // GRAPHS__DIJKSTRAPATHFINDER_H_
