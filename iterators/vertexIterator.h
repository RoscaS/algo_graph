#pragma once

#include "../graph/graph.h"

template<class VertexData>
class VertexIterator {

public:
   int position;
   Graph<VertexData> graph;

   explicit VertexIterator(Graph<VertexData> &graph)
           : graph(graph), position(-1) {}

   bool has_next() {
       return graph.vertices.size() - (position - 1) > 0;
   }

   Vertex<VertexData> *next() {
       if (has_next()) position++;
       return graph.vertices[position];
   }

   void display() {
       while (has_next()) {
           auto vertex = next();
           std::cout << "Vertex: " << vertex->data << "\t links: [";
           for (auto const link : vertex->edges) {
               std::cout << link->target->data << " ";
           }
           std::cout << "]\n";
       }
   }
};
