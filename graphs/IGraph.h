#ifndef GRAPHS__IGRAPH_H_
#define GRAPHS__IGRAPH_H_

#include "Edge.h"

class IGraph {
public:
    virtual int getVertexCount() const = 0;

    virtual std::vector<Edge> getEdges() const = 0;
};

#endif  // GRAPHS__IGRAPH_H_
