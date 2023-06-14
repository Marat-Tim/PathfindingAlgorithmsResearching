#ifndef GRAPHS_GENERATORS_FULLGRAPHGENERATOR_H_
#define GRAPHS_GENERATORS_FULLGRAPHGENERATOR_H_

#include "GraphGenerator.h"
#include "GraphBuilder.h"

class FullGraphGenerator : public GraphGenerator {
public:
    std::shared_ptr<IGraph> generate(int vertex_count) override {
        GraphBuilder graph_builder;
        graph_builder.setVertexCount(vertex_count);
        for (int i = 0; i < vertex_count; ++i) {
            for (int j = i + 1; j < vertex_count; ++j) {
                graph_builder.connect(i, j, randomLength());
            }
        }
        return graph_builder.build();
    }
};

#endif  // GRAPHS_GENERATORS_FULLGRAPHGENERATOR_H_
