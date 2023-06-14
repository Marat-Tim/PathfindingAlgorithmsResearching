#ifndef GRAPHS__IGRAPH_H_
#define GRAPHS__IGRAPH_H_

#include "Edge.h"

class IGraph {
public:
    virtual int getVertexCount() const = 0;

    virtual std::vector<Edge> getEdges() const = 0;

    friend std::ostream& operator<<(std::ostream& out, std::shared_ptr<IGraph> graph) {
        out << graph->getVertexCount() << "\n";
        auto edges = graph->getEdges();
        for (const auto& edge : edges) {
            out << edge.vertex1 << " " << edge.vertex2 << " " << edge.weight << "\n";
        }
        return out;
    }
};

#endif  // GRAPHS__IGRAPH_H_
