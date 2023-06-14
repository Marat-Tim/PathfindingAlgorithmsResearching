#ifndef GRAPHS__DIJKSTRAPATHFINDER_H_
#define GRAPHS__DIJKSTRAPATHFINDER_H_

#include "IPathFinder.h"

class DijkstraPathFinder : public IPathFinder {
    int findPath(int vertex1, int vertex2, std::shared_ptr<IGraph> graph) const override {

    }
};

#endif//GRAPHS__DIJKSTRAPATHFINDER_H_
