#ifndef GRAPHS_GENERATORS_TREEGRAPHGENERATOR_H_
#define GRAPHS_GENERATORS_TREEGRAPHGENERATOR_H_

#include "IGraphGenerator.h"
#include "GraphBuilder.h"
#include "../random.h"

class TreeGraphGenerator : public virtual IGraphGenerator {
public:
    std::shared_ptr<IGraph> generate(int vertex_count) override {
        GraphBuilder graph_builder;
        graph_builder.addVertex();
        for (int i = 0; i < vertex_count - 1; ++i) {
            int random_vertex = randomInt(0, graph_builder.getVertexCount());
            int new_vertex = graph_builder.addVertex();
            graph_builder.connect(new_vertex, random_vertex, randomLength());
        }
        return graph_builder.build();
    }
};

#endif  // GRAPHS_GENERATORS_TREEGRAPHGENERATOR_H_
