#ifndef GRAPHS_GENERATORS_GRAPHBUILDER_H_
#define GRAPHS_GENERATORS_GRAPHBUILDER_H_

#include <memory>
#include <vector>
#include <iostream>
#include "../graphs/IGraph.h"
#include "../graphs/SimpleGraph.h"

class GraphBuilder {
public:
    GraphBuilder() : vertex_count_(0) {
    }

    GraphBuilder(std::shared_ptr<IGraph> graph)
        : vertex_count_(graph->getVertexCount()), edges_(graph->getEdges()) {
    }

    void setVertexCount(int vertex_count) {
        vertex_count_ = vertex_count;
    }

    void connect(int vertex1, int vertex2, int length) {
        edges_.push_back({vertex1, vertex2, length});
    }

    int addVertex() {
        return vertex_count_++;
    }

    int getVertexCount() {
        return vertex_count_;
    }

    int getEdgesCount() {
        return edges_.size();
    }

    std::shared_ptr<IGraph> build() {
        return std::make_shared<SimpleGraph>(vertex_count_, edges_);
    }

private:
    int vertex_count_;
    std::vector<Edge> edges_;
};

#endif  // GRAPHS_GENERATORS_GRAPHBUILDER_H_
