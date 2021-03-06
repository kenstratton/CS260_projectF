#pragma once

#include <string>
#include <vector>

using namespace std;

struct Graph_node {
    vector <vector<int>> edges; // destination
    int id; // identification for each node

public:
    Graph_node(int id){ this->id=id; }

    vector<int> add_edge (int dst, int w) {
        vector<int> edge;

        edge.push_back(dst);
        edge.push_back(w);
        edges.push_back(edge);

        vector<int> v{w, id , dst};

        return v;
    }

    // Erase edge data (a stored destination)
    void erase_edge (int dst) {
        for (int i=0; i<edges.size(); i++) {
            if (edges[i][0] == dst) edges.erase(edges.begin()+i);
        }
    }

    // Print node info1 (stored destinations and their costs)
    string show_edge () {
        string result = "";

        for (auto edge: edges) {
            result += "destination: " + to_string(edge[0]);
            result += " weight: " + to_string(edge[1]);
            result += "\n";
        }

        return result;
    }
};