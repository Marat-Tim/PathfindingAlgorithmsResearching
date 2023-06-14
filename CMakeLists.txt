cmake_minimum_required(VERSION 3.25)
project(graphs)

set(CMAKE_CXX_STANDARD 17)

add_executable(graphs main.cpp graphs/IGraph.h path_finders/IPathFinder.h path_finders/DijkstraPathFinder.h generators/GraphGenerator.h config.h CSV.h NamedObject.h PathFinderTester.h graphs/Edge.h graphs/SimpleGraph.h generators/GraphBuilder.h graphs/AdjacencyMatrixGraph.h generators/FullGraphGenerator.h generators/TreeGenerator.h path_finders/FloydWarshallFinder.h)
