#pragma once

#include "../graph/graph.h"
#include "../graphviz/basegraphviz.h"
#include <set>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


template<class VertexData>
class GraphvizIterator : public BaseGraphviz<VertexData>{

   Graph<VertexData> graph;
   std::set<int> visited;

public:
   explicit GraphvizIterator(const Graph<VertexData> &graph) : graph(graph) {}

   void explore() {
       for (auto const vertex : graph.vertices) {
           if (!isVisited(vertex->index)) {
                depthFirst(vertex);
           }
       }
   }

   void depthFirst(Vertex<VertexData> *vertex) {
       visited.insert(vertex->index);

       this->addVertexToGraphviz(vertex);

       for (auto const link : vertex->edges) {
           if (!isVisited(link->target->index)) {
               depthFirst(link->target);

               this->addLinkToGraphviz(vertex, link->target);
           }
       }
   }

   bool isVisited(int index) {
       return visited.count(index) > 0;
   }
};
