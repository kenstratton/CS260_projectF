#pragma once

#include <string>
#include <vector>

#include "graph_node.hpp"

using namespace std;

// Graph class to draw a graph and give behaviors
class Graph {
    vector<Graph_node *> nodes;

    public:
        Graph (int n) { for (int i=0; i<n; i++) add_node(i); }

        bool add_node (int id);
        int get_node_size ();
        vector<int> add_edge (int idx, int dst, int w);
        vector<int> shortest_path (int src);
        int min_span_tree ();
        string show_nodes ();
};