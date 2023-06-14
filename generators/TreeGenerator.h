#ifndef GRAPHS_GENERATORS_TREEGENERATOR_H_
#define GRAPHS_GENERATORS_TREEGENERATOR_H_

#include "GraphGenerator.h"
#include "GraphBuilder.h"

class TreeGenerator : public GraphGenerator {
public:
    std::shared_ptr<IGraph> generate(int vertex_count) override {
        GraphBuilder graph_builder;
        graph_builder.addVertex();
        for (int i = 0; i < vertex_count - 1; ++i) {
            int random_vertex = rand() % graph_builder.getVertexCount();
            int new_vertex = graph_builder.addVertex();
            graph_builder.connect(new_vertex, random_vertex, randomLength());
        }
        return graph_builder.build();
    }
};

#endif  // GRAPHS_GENERATORS_TREEGENERATOR_H_
