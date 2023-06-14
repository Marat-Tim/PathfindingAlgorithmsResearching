#ifndef GRAPHS_PATH_FINDERS_FLOYDWARSHALLFINDER_H_
#define GRAPHS_PATH_FINDERS_FLOYDWARSHALLFINDER_H_

#include "IPathFinder.h"
#include "../graphs/AdjacencyMatrixGraph.h"

class FloydWarshallFinder : public virtual IPathFinder {
public:
    int findPath(int vertex1, int vertex2, std::shared_ptr<IGraph> graph) const override {
        AdjacencyMatrixGraph graph1(graph);
        int n = graph1.getVertexCount();
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    std::optional<int> len_i_j = graph1.lengthBetween(i, j);
                    std::optional<int> len_i_k = graph1.lengthBetween(i, k);
                    std::optional<int> len_k_j = graph1.lengthBetween(k, j);
                    if (len_i_k.has_value() && len_k_j.has_value()) {
                        if (len_i_j.has_value()) {
                            if (len_i_j.value() > len_i_k.value() + len_k_j.value()) {
                                graph1.setLength(i, j, len_i_k.value() + len_k_j.value());
                            }
                        } else {
                            graph1.setLength(i, j, len_i_k.value() + len_k_j.value());
                        }
                    }
                }
            }
        }
        int a = 1;
        return graph1.lengthBetween(vertex1, vertex2).value();
    }
};

#endif  // GRAPHS_PATH_FINDERS_FLOYDWARSHALLFINDER_H_
