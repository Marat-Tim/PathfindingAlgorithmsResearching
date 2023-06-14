#ifndef GRAPHS_GRAPHS_ADJACENCYMATRIXGRAPH_H_
#define GRAPHS_GRAPHS_ADJACENCYMATRIXGRAPH_H_

#include <vector>
#include <memory>
#include <optional>
#include "IGraph.h"

class AdjacencyMatrixGraph {
public:
    AdjacencyMatrixGraph(std::shared_ptr<IGraph> graph)
        : adjacency_matrix_(graph->getVertexCount(), std::vector<std::optional<int>>(
                                                         graph->getVertexCount(), std::nullopt)) {
        std::vector<Edge> edges = graph->getEdges();
        for (const auto& edge : edges) {
            adjacency_matrix_[edge.vertex1][edge.vertex2] = edge.weight;
            adjacency_matrix_[edge.vertex2][edge.vertex1] = edge.weight;
        }
    }

    int getVertexCount() const {
        return adjacency_matrix_.size();
    }

    std::optional<int> lengthBetween(int vertex1, int vertex2) const {
        return adjacency_matrix_[vertex1][vertex2];
    }

    void setLength(int vertex1, int vertex2, int length) {
        adjacency_matrix_[vertex1][vertex2] = length;
        adjacency_matrix_[vertex2][vertex1] = length;
    }

private:
    std::vector<std::vector<std::optional<int>>> adjacency_matrix_;
};

#endif  // GRAPHS_GRAPHS_ADJACENCYMATRIXGRAPH_H_
