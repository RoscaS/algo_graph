#include <graphviz/gvc.h>
#include <iostream>
#include <set>

#include "graph/graph.h"
#include "iterators/vertexIterator.h"
#include "iterators/depthFirstSearch.h"
#include "iterators/GraphvizIterator.h"
#include "generator/GraphBuilder.hpp"
#include "utils/helpers.h"

int main() {
    auto graph = new Graph<std::string>();
    // build_dummy_graph(graph);
    // VertexIterator<std::string> vit(*graph);
    // DepthFirstIterator<std::string> dit(*graph);

    // display(graph);
    // vit.display();
    // dit.explore();

    Helpers::import_data(graph);
    GraphvizIterator<std::string> gvzit(*graph);
    gvzit.display();


    return 0;
}

