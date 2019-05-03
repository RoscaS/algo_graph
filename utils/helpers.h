#pragma once

#include <iostream>
#include "../graph/graph.h"
#include "../generator/GraphBuilder.hpp"


template<class VertexData>
class Helpers {

public:

   static void buildDummyGraph(Graph<VertexData> *graph){
       std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVW";
       for (int i = 0; i <= 8; i++) {
           graph->add_vertex(alphabet[i]);
           if (i){
               graph->add_edge(i - 1, i);
           }
       }
   }

   static void print(Graph<VertexData> *graph) {
       for (auto const vertex : graph->vertices) {
           std::cout << vertex->data << ":\t [";
           for (auto const link : vertex->edges) {
               std::cout << link->target->data << " ";
           }
           std::cout << "]\n";
       }
   }

   static void importRankingData(Graph<VertexData> *graph) {
       auto builder = new GraphBuilder(graph);
       builder->buildFromFile("../generator/rawdata");
   }
};
