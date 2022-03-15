#include <string>

#include "graph.hpp"
#include "min_span_tree.hpp"

using namespace std;


bool Graph::add_node() {
    Graph_node *new_node = new Graph_node{};
    this->nodes.push_back(new_node);
    return true;
}

bool Graph::add_edge(int idx, int dst, int w) {
    this->nodes[idx]->add_edge(dst, w);
    return true;
}


// string Graph::shortest_path(){}

int Graph::min_span_tree(){
    int min_cost = 0;

    vector<vector<int>> all_edges;
    for(auto node: this->nodes){
        for(int i=0; i<node->edges.size(); i++){
            all_edges.push_back({node->edges[i][1], i, node->edges[i][0]});
        }
    }
    sort(all_edges.begin(), all_edges.end());
    MinSpanTree mst(this->node_num);

    for (int i=0; i < all_edges.size(); i++) {
        vector<int> edge = all_edges[i];
        if (mst.find(edge[1]) != mst.find(edge[2])) {
            min_cost += edge[0];
            mst.merge(edge[1], edge[2]);
        }
    }

    return min_cost;
}


string Graph::show_nodes() {
    string result = "";
    for(int i=0; i<this->nodes.size(); i++) {
        result += "▼ Node " + to_string(i);
        result += "\n";
        result += this->nodes[i]->show_edge();
    }
    return result;
}