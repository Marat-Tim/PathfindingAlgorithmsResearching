#ifndef GRAPHS_GENERATORS_GRAPHGENERATOR_H_
#define GRAPHS_GENERATORS_GRAPHGENERATOR_H_

#include <memory>
#include "../graphs/IGraph.h"
#include "../config.h"

class GraphGenerator {
protected:
    int randomLength() {
        return kMinLength + rand() % (kMaxLength - kMinLength + 1);
    }
public:
    virtual std::shared_ptr<IGraph> generate(int vertex_count) = 0;
};

#endif  // GRAPHS_GENERATORS_GRAPHGENERATOR_H_
