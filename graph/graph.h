#pragma once
#include <vector>
#include "vertex.h"

template<class VertexData>
class Graph {

public:
   std::vector<Vertex<VertexData> *> vertices;
   std::vector<Edge<VertexData> *> edges;

   void add_vertex(VertexData value) {
       vertices.push_back(new Vertex<VertexData>(value, vertices.size()));
   }

   void add_edge(int sourceId, int targetId) {

       Vertex<VertexData> *source = vertices[sourceId];
       Vertex<VertexData> *target = vertices[targetId];

       auto edge = new Edge<VertexData>(vertices[sourceId], vertices[targetId]);

       source->edges.push_back(edge);
       edges.push_back(edge);
   }

   int edges_count() const {
       return edges.size();
   }

   Vertex<VertexData> *vertex(int idx) {
       return vertices[idx];
   }
};
