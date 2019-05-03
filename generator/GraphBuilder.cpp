//
// Created by nath on 02.05.19.
//

#include "GraphBuilder.hpp"
#include <iostream>

GraphBuilder::GraphBuilder(Graph<std::string> *graph) {
    this->graph = graph;
    file = new ManageFile();
    vertex = new unordered_map<string,int>();
}

void GraphBuilder::buildFromFile(string path){
    file->setFile(path);
    vector<string> tab = file->readFile();
    for(int i = 0; i < tab.size(); i++) {
        vector<string> line = split(tab.at(i), ' ');
        string header = line.at(0);
        vertex->insert(pair<string,int>(header,i));
        graph->add_vertex(header);
    }
    int i = 0;
    for(auto const v: graph->vertices) {
        vector<string> line = split(tab.at(i++), ' ');
        createEdge(line, vertex->at(v->data));
    }
}

void GraphBuilder::createEdge(vector<string> tab, int index){
    for(int i = 1; i < tab.size(); i++){
        graph->add_edge(index, vertex->at(tab.at(i)));
    }

}

vector<string> GraphBuilder::split(string text, char split){
    vector<string> elems;
    stringstream ss(text);
    string item;
    while(getline(ss, item, split)) {
        elems.push_back(item);
    }
    return elems;
}

