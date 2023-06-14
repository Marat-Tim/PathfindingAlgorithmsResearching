#include "CSV.h"
#include "config.h"
#include "generators/IGraphGenerator.h"
#include "path_finders/IPathFinder.h"
#include "path_finders/DijkstraFinder.h"
#include "path_finders/BellmanFordFinder.h"
#include "path_finders/FloydWarshallFinder.h"
#include "NamedObject.h"
#include "PathFinderTester.h"
#include "generators/FullGraphGenerator.h"
#include "generators/TreeGraphGenerator.h"
#include "generators/MediumDenseGraphGenerator.h"

#include <memory>
#include <vector>

const std::string kIndexName = "index";


int main() {
    std::vector<NamedObject<std::shared_ptr<IGraphGenerator>>> generators{
        {std::make_shared<FullGraphGenerator>(), "полный граф"},
        {std::make_shared<TreeGraphGenerator>(), "дерево"},
        {std::make_shared<MediumDenseGraphGenerator>(), "средне-связный граф"},
    };
    std::vector<NamedObject<std::shared_ptr<IPathFinder>>> path_finders{
        {std::make_shared<FloydWarshallFinder>(), "Флойд-Уоршелл"},
        {std::make_shared<DijkstraFinder>(), "Дейкстра"},
        {std::make_shared<BellmanFordFinder>(), "Беллман-Форд"},
    };
    CSV csv_vertices;
    csv_vertices.addColumn(kIndexName);
    for (const auto& path_finder : path_finders) {
        for (const auto& generator : generators) {
            csv_vertices.addColumn(path_finder.getName() + " + " + generator.getName());
        }
    }
    PathFinderTester path_finder_tester;
    for (int i = 0, vertex_count = kMinVertexCount; vertex_count <= kMaxVertexCount;
         ++i, vertex_count += kStep) {
        csv_vertices.set(kIndexName, i, vertex_count);
        for (const auto& generator : generators) {
            std::shared_ptr<IGraph> graph = generator->generate(vertex_count);
            for (const auto& path_finder : path_finders) {
                uint64_t time =
                    path_finder_tester.getAverageExecutionTime(path_finder.getObject(), graph);
                csv_vertices.set(path_finder.getName() + " + " + generator.getName(), i, time);
            }
        }
    }
    csv_vertices.writeToFile("../vertices.csv");
    return 0;
}