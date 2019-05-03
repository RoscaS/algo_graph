#pragma once

#include "../graph/graph.h"
#include <iostream>
#include <fstream>

#define FNAME "../output/graph.dot"


template<class VertexData>
class BaseGraphviz {

public:
   std::string graphStr;

   BaseGraphviz() {
       graphStr += "graph G {\n";
   }

   void addVertexToGraphviz(Vertex<VertexData> *vertex) {
       graphStr += "\t";
       graphStr += vertex->data;
       graphStr += ";\n";
   }

   void addLinkToGraphviz(Vertex<VertexData> *source, Vertex<VertexData> *target) {
       graphStr += "\t";
       graphStr += source->data;
       graphStr += " -- ";
       graphStr += target->data;
       graphStr += ";\n";
   }

   void writeGraphvizFile() {
       std::ofstream outfile;
       outfile.open(FNAME, std::ios::out);
       outfile << graphStr << std::endl;
       outfile.close();
   }

   void displayGraphviz() {
       graphStr += "\n}";
       writeGraphvizFile();
       system("cd ../output; xdot graph.dot");
   }

};
