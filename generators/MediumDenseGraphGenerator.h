#ifndef GRAPHS_GENERATORS_MEDIUMDENSEGRAPHGENERATOR_H_
#define GRAPHS_GENERATORS_MEDIUMDENSEGRAPHGENERATOR_H_

#include "IGraphGenerator.h"
#include "TreeGraphGenerator.h"
#include "../random.h"
#include "../config.h"

class MediumDenseGraphGenerator : public virtual IGraphGenerator {
public:
    std::shared_ptr<IGraph> generate(int vertex_count) override {
        TreeGraphGenerator tree_graph_generator;
        std::shared_ptr<IGraph> graph = tree_graph_generator.generate(vertex_count);
        GraphBuilder graph_builder(graph);
        if (getDensityCoefficient(graph_builder.getVertexCount(), graph_builder.getEdgesCount()) >
            kMaxDensityCoefficientForMediumDenseGraph) {
            throw std::logic_error("Коэффициент плотности у дерева изначально больше " +
                                   std::to_string(kMaxDensityCoefficientForMediumDenseGraph));
        }
        while (
            getDensityCoefficient(graph_builder.getVertexCount(), graph_builder.getEdgesCount()) <
            kMinDensityCoefficientForMediumDenseGraph) {
            std::pair<int, int> random_vertices = twoRandomDifferentInts(0, vertex_count - 1);
            graph_builder.connect(random_vertices.first, random_vertices.second, randomLength());
        }
        if (getDensityCoefficient(graph_builder.getVertexCount(), graph_builder.getEdgesCount()) >
            kMaxDensityCoefficientForMediumDenseGraph) {
            throw std::logic_error("Коэффициент плотности у графа получился больше " +
                                   std::to_string(kMaxDensityCoefficientForMediumDenseGraph));
        }
        return graph_builder.build();
    }

private:
    double getDensityCoefficient(int vertex_count, int edges_count) {
        return static_cast<double>(2 * edges_count) / (vertex_count * (vertex_count - 1));
    }
};

#endif  // GRAPHS_GENERATORS_MEDIUMDENSEGRAPHGENERATOR_H_
