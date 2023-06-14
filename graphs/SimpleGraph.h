#ifndef GRAPHS_GRAPHS_SIMPLEGRAPH_H_
#define GRAPHS_GRAPHS_SIMPLEGRAPH_H_

#include <vector>
#include "IGraph.h"

class SimpleGraph : public virtual IGraph {
public:
    SimpleGraph(int vertex_count, std::vector<Edge> edges)
        : vertex_count_(vertex_count), edges_(edges) {
    }

    int getVertexCount() const override {
        return vertex_count_;
    }

    std::vector<Edge> getEdges() const override {
        return edges_;
    }

private:
    int vertex_count_;
    std::vector<Edge> edges_;
};

#endif  // GRAPHS_GRAPHS_SIMPLEGRAPH_H_
