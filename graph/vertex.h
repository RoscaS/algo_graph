#pragma once

template<class VertexData> class Vertex;


template<class VertexData>
struct Edge {

   Vertex<VertexData> *source;
   Vertex<VertexData> *target;
   int weight;

   Edge(Vertex<VertexData> *source, Vertex<VertexData> *target)
           : source(source), target(target) {}
};

template<class VertexData>
struct Vertex {
   VertexData data;
   int index;

   std::vector<Edge<VertexData> *> edges;
   explicit Vertex(VertexData &data, int index) : data(data), index(index) {}
};
