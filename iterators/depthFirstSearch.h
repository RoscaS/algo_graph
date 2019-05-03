#pragma once

#include "../graph/graph.h"
#include <set>
#include <iostream>

template<class VertexData>
class DepthFirstIterator {

   Graph<VertexData> graph;
   std::set<int> visited;

public:
   explicit DepthFirstIterator(const Graph<VertexData> &graph) : graph(graph) {}

   void explore() {
       for (auto const vertex : graph.vertices) {
           if (!isVisited(vertex->index)) {
                depthFirst(vertex);
           }
       }
   }

   void depthFirst(Vertex<VertexData> *vertex) {
       visited.insert(vertex->index);
       std::cout << vertex->data << "\n";
       for (auto const link : vertex->edges) {
           if (!isVisited(link->target->index)) {
               depthFirst(link->target);
           }
       }
   }

   bool isVisited(int index) {
       return visited.count(index) > 0;
   }
};
