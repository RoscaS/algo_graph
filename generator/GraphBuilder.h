//
// Created by nath on 02.05.19.
//
#pragma once
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include "ManageFile.hpp"
#include "../graph/graph.h"
#include "graph/vertex.h"
#include <iostream>

template<class VertexData>
class GraphBuilder {
    Graph<VertexData> *graph;
    unordered_map<VertexData,int>* vertex;

public:
    GraphBuilder(Graph<VertexData>* graph){
        this->graph = graph;
        vertex = new unordered_map<VertexData, int>();
    }
    void buildFromFile(std::string path) {
        ManageFile file(path);
        vector<std::string> tab = file.readFile();

        createVertex(tab);

        int idx = 0;
        for(auto const v: graph->vertices) {
            vector<std::string> line = split(tab.at(idx++), ' ');
            createEdge(line, vertex->at(v->data));
        }
    }

private:
    void createVertex(vector<std::string> tab){
        for(int i = 0; i < tab.size(); i++) {
            vector<std::string> line = split(tab.at(i), ' ');
            vertex->insert(pair<std::string,int>(line.at(0),i));
            graph->add_vertex(line.at(0));
        }
    }

    void createEdge(vector<std::string> tab, int index){
        for(int i = 1; i < tab.size(); i++){
            graph->add_edge(index, vertex->at(tab.at(i)));
        }
    }

    vector<std::string> split(std::string text, char split){
        vector<std::string> elems;
        std::stringstream ss(text);
        std::string item;
        while(getline(ss, item, split)) {
            elems.push_back(item);
        }
        return elems;
    }
};
