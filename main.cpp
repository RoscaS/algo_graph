#include <graphviz/gvc.h>
#include <iostream>
#include <set>

#include "graph/graph.h"
#include "iterators/vertexIterator.h"
#include "iterators/depthFirstSearch.h"
#include "iterators/GraphvizIterator.h"
#include "generator/GraphBuilder.h"
#include "utils/helpers.h"


void ranking() {
    auto graph = new Graph<std::string>();
    Helpers<std::string>::importRankingData(graph);
    Helpers<std::string>::print(graph);
    GraphvizIterator<std::string> it(*graph);
    VertexIterator<std::string> itV(*graph);
    itV.display();

    it.explore();
    it.displayGraphviz();
}

void dummyGraph() {
    auto graph = new Graph<char>();
    Helpers<char>::buildDummyGraph(graph);
    DepthFirstIterator<char> it(*graph);
    it.explore();
    it.displayGraphviz();
}


int main() {
    // ranking();
    ranking();

    return 0;
}

