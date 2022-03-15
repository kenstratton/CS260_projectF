#pragma once

#include <string>
#include <vector>

using namespace std;

struct Graph_node {
    vector <vector<int>> edges;

    void add_edge(int dst, int w) {
        vector<int> edge;
        edge.push_back(dst);
        edge.push_back(w);
        this->edges.push_back(edge);
    }

    string show_edge() {
        string result = "";
        for(auto edge: this->edges) {
            result += "destination: " + to_string(edge[0]);
            result += " weight: " + to_string(edge[1]);
            result += "\n";
        }

        return result;
    }
};