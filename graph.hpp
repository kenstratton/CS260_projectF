#pragma once

#include <string>
#include <vector>

#include "graph_node.hpp"

using namespace std;

class Graph {
    vector<Graph_node *> nodes;
    int node_num;

    public:
        Graph(int n) {
            this->node_num = n;
            for(int i=0; i<n; i++){
                add_node();
            }
        }

        bool add_node();
        bool add_edge(int idx, int dst, int w);
        string shortest_path();
        int min_span_tree();
        string show_nodes();
};