#include <iostream>
#include <string>

#include "graph.hpp"
#include "min_span_tree.hpp"
#include "shortest_path.hpp"

using namespace std;


bool Graph::add_node (int id) {
    Graph_node *new_node = new Graph_node{id};
    nodes.push_back(new_node);
    return true;
}

int Graph::get_node_size () {
    return nodes.size();
}

vector<int> Graph::add_edge (int idx, int dst, int w) {
    bool exst = false;
    for (auto edge: nodes[idx]->edges) {
        if (edge[0]==dst){
            exst = true;
            break;
        }
    }
    if (exst) {
        nodes[idx]->erase_edge(dst);
        nodes[dst]->erase_edge(idx);
    }
    vector<int> e = nodes[idx]->add_edge(dst, w);
    nodes[dst]->add_edge(idx, w);
    return e;
}

vector<int> Graph::shortest_path (int src) {
    vector<vector<int>> matrix;
    vector<int> edges;
    bool is_inf;
    int inf = 0;

    for (auto node: nodes) {
        edges.clear();
        for (int i=0; i<get_node_size(); i++) {
            is_inf = true;
            for (auto edge: node->edges) {
                if (edge[0]==i) {
                    edges.push_back(edge[1]);
                    is_inf = false;
                    break;
                }
            }
            if (is_inf) edges.push_back(inf);
        }
        matrix.push_back(edges);
    }

    ShortestPath sp;
    vector<int> dstV = sp.calc_path(get_node_size(), matrix, src);
    cout << "▼ Source : " << src << endl;
    cout << "Goal - Distance" << endl;
    for (int i = 0; i<get_node_size(); i++) cout << "[" << i << "]" << " - " << dstV[i] <<endl;

    return dstV;
}

int Graph::min_span_tree () {
    int min_cost = 0;

    vector<vector<int>> all_edges;
    vector<vector<int>> all_dst;
    for (int i=0; i<get_node_size(); i++) {
        all_dst.push_back({});
    }

    for (auto node: nodes) {
        for (auto edge: node->edges) {
            all_edges.push_back({edge[1], node->id, edge[0]});
        }
    }
    sort(all_edges.begin(), all_edges.end());
    MinSpanTree mst(get_node_size());

    for (int i=0; i < all_edges.size(); i++) {
        vector<int> edge = all_edges[i];
        if (mst.find(edge[1]) != mst.find(edge[2])) {
            min_cost += edge[0];
            mst.merge(edge[1], edge[2]);
        }
    }

    return min_cost;
}


string Graph::show_nodes () {
    string result = "";
    for (auto node: nodes) {
        result += "▼ Node " + to_string(node->id);
        result += "\n";
        result += node->show_edge();
    }
    return result;
}