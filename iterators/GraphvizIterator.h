#pragma once

#include "../graph/graph.h"
#include <set>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#define FNAME "../output/graph.dot"

template<class VertexData>
class GraphvizIterator {

   Graph<VertexData> graph;
   std::set<int> visited;
   std::string graphStr;

public:
   explicit GraphvizIterator(const Graph<VertexData> &graph) : graph(graph) {
       graphStr += "graph G {\n";
   }

   void explore() {
       for (auto const vertex : graph.vertices) {
           if (!isVisited(vertex->index)) {
                depthFirst(vertex);
           }
       }
       graphStr += "\n}";
   }

   void depthFirst(Vertex<VertexData> *vertex) {
       visited.insert(vertex->index);
       addVertex(vertex);
       for (auto const link : vertex->edges) {
           if (!isVisited(link->target->index)) {
               depthFirst(link->target);
               addLink(vertex, link->target);
           }
       }
   }

   bool isVisited(int index) {
       return visited.count(index) > 0;
   }

   void addVertex(Vertex<VertexData> *vertex) {
       graphStr += "\t";
       graphStr += vertex->data;
       graphStr += ";\n";
   }

   void addLink(Vertex<VertexData> *source, Vertex<VertexData> *target) {
       graphStr += "\t";
       graphStr += source->data;
       graphStr += " -- ";
       graphStr += target->data;
       graphStr += ";\n";
   }

   void writeFile() {
       explore();

       std::ofstream outfile;
       outfile.open(FNAME, std::ios::out);
       outfile << graphStr << std::endl;
       outfile.close();
   }

   void display() {
       writeFile();
       system("cd ../output; xdot graph.dot");
   }
};
