cmake_minimum_required(VERSION 3.14)
project(Graph2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Graph2 main.cpp
        graph/graph.h
        graph/vertex.h
        graphviz/basegraphviz.h
        iterators/depthFirstSearch.h
        iterators/vertexIterator.h
        generator/ManageFile.hpp
        generator/ManageFile.cpp
        generator/GraphBuilder.h
        generator/GenerateData.cpp
        generator/GenerateData.hpp
        utils/helpers.h
)
