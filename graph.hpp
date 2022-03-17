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
            node_num = n;
            for(int i=0; i<n; i++){
                add_node(i);
            }
        }

        bool add_node(int id);
        vector<int> add_edge(int idx, int dst, int w);
        vector<int> shortest_path(int src);
        int min_span_tree();
        string show_nodes();
};