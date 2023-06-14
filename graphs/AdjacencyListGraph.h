#ifndef GRAPHS_GRAPHS_ADJACENCYLISTGRAPH_H_
#define GRAPHS_GRAPHS_ADJACENCYLISTGRAPH_H_

#include <vector>
#include <memory>
#include "Arrow.h"
#include "IGraph.h"

class AdjacencyListGraph {
public:
    AdjacencyListGraph(std::shared_ptr<IGraph> graph) : adjacency_list_(graph->getVertexCount()) {
        for (const auto& edge : graph->getEdges()) {
            adjacency_list_[edge.vertex1].push_back({edge.vertex2, edge.weight});
            adjacency_list_[edge.vertex2].push_back({edge.vertex1, edge.weight});
        }
    }

    std::vector<Arrow> getArrowsForVertex(int vertex) {
        return adjacency_list_[vertex];
    }

private:
    std::vector<std::vector<Arrow>> adjacency_list_;
};

#endif  // GRAPHS_GRAPHS_ADJACENCYLISTGRAPH_H_
