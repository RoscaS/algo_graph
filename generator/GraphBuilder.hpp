
#pragma once
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include "ManageFile.hpp"
#include "../graph/graph.h"

using namespace std;
class GraphBuilder {
public:
    GraphBuilder(Graph<string>* graph);
    void buildFromFile(string path);
private:
    Graph<string> *graph;
    ManageFile *file;
    unordered_map<string,int>* vertex;

    vector<string> split(string text, char split);
    void createEdge(vector<string> tab, int index);
};
