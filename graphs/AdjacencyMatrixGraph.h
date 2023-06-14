#ifndef GRAPHS_GRAPHS_ADJACENCYMATRIXGRAPH_H_
#define GRAPHS_GRAPHS_ADJACENCYMATRIXGRAPH_H_

#include <vector>
#include <memory>
#include <optional>
#include "IGraph.h"

class AdjacencyMatrixGraph : public virtual IGraph {
public:
    AdjacencyMatrixGraph(std::shared_ptr<IGraph> graph)
        : adjacency_matrix_(graph->getVertexCount(), std::vector<std::optional<int>>(
                                                         graph->getVertexCount(), std::nullopt)) {
        std::vector<Edge> edges = graph->getEdges();
        for (const auto& edge : edges) {
            adjacency_matrix_[edge.vertex1][edge.vertex2] = edge.length;
            adjacency_matrix_[edge.vertex2][edge.vertex1] = edge.length;
        }
    }

    int getVertexCount() const override {
        return adjacency_matrix_.size();
    }

    std::vector<Edge> getEdges() const override {
        std::vector<Edge> edges;
        for (int i = 0; i < adjacency_matrix_.size(); ++i) {
            for (int j = i + 1; j < adjacency_matrix_.size(); ++j) {
                if (adjacency_matrix_[i][j].has_value()) {
                    edges.push_back({i, j, adjacency_matrix_[i][j].value()});
                }
            }
        }
        return edges;
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
