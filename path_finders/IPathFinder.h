#ifndef GRAPHS__PATHFINDER_H_
#define GRAPHS__PATHFINDER_H_

#include <memory>
#include "../graphs/IGraph.h"

class IPathFinder {
public:
    virtual int findPath(int vertex1, int vertex2, std::shared_ptr<IGraph> graph) const = 0;
};

#endif//GRAPHS__PATHFINDER_H_
