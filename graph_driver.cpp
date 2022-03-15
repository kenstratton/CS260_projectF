/******************************************
 * tests

 * add a new vertex to the graph (perhaps add_vertex(vertex_name))
 * add a new edge between two vertices of the graph (perhaps add_edge(source, destination) or source.add_edge(destination))
 * a function for a shortest path algorithm (perhaps shortest_path(source, destination))
 * a function for a minimum spanning tree algorithm (example min_span_tree()).

 * Analyze the complexity of all of your graph behaviors
******************************************/

#include <iostream>
#include <string.h>
#include <vector>

#include "graph_node.hpp"
#include "graph.hpp"

using namespace std;

int main() {
    Graph g(4);
    g.add_edge(0, 1, 12);
    g.add_edge(0, 2, 5);
    g.add_edge(0, 3, 6);
    g.add_edge(3, 2, 10);
    g.add_edge(1, 2, 2);

    cout << g.min_span_tree() << endl;
}