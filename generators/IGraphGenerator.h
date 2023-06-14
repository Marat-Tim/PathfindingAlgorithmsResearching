#ifndef GRAPHS_GENERATORS_IGRAPHGENERATOR_H_
#define GRAPHS_GENERATORS_IGRAPHGENERATOR_H_

#include <memory>
#include "../graphs/IGraph.h"
#include "../config.h"
#include "../random.h"

class IGraphGenerator {
protected:
    int randomLength() {
        return randomInt(kMinLength, kMaxLength);
    }
public:
    virtual std::shared_ptr<IGraph> generate(int vertex_count) = 0;
};

#endif  // GRAPHS_GENERATORS_IGRAPHGENERATOR_H_
