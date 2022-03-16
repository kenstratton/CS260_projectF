#include <iostream>

#include "graph_node.hpp"
#include "graph.hpp"

#define V 4

using namespace std;

int main() {
    Graph g(V);
    g.add_edge(0, 1, 12);
    g.add_edge(0, 2, 5);
    g.add_edge(0, 3, 6);
    g.add_edge(3, 2, 10);
    g.add_edge(1, 2, 2);
    cout << g.show_nodes() << endl;
    cout << "min_tree : " << g.min_span_tree() << "\n" <<endl;
    g.shortest_path(1,2);
}