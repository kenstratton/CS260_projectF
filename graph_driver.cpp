#include <iostream>
#include <string.h>

#include "graph_node.hpp"
#include "graph.hpp"

#define V 4

using namespace std;

/*******************************************
Test fuction :
 * 1. Test addition of nodes
 * 2. Test addition of edges
 * 3. Test calculation of the minimum spannning tree
 * 4. Test calculation of the shortest paths
********************************************/
void test_graph () {
    Graph g(V);
    vector<int> e;

    cout << "Tests start...\n" << endl;

    // * 1
    assert(g.get_node_size() == V);

    // * 2
    e = g.add_edge(0, 1, 12);
    vector<int> v1{12, 0, 1};
    assert(e == v1);

    e = g.add_edge(0, 2, 5);
    vector<int> v2{5, 0, 2};
    assert(e == v2);

    e = g.add_edge(0, 3, 6);
    vector<int> v3{6, 0, 3};
    assert(e == v3);

    e = g.add_edge(3, 2, 10);
    vector<int> v4{10, 3, 2};
    assert(e == v4);

    e = g.add_edge(1, 2, 2);
    vector<int> v5{2, 1, 2};
    assert(e == v5);

    cout << g.show_nodes() << endl;

    /*************
     ▼ Graph Image
          12
      [0]----[1]
    6 |  ＼ 5  | 2
      |    ＼  |
      [3]----[2]
          10
    *************/

    // * 3
    int m = g.min_span_tree();
    assert(m == 13);
    cout << "min_tree : " << m << "\n" <<endl;

    // * 4
    vector<int> dstV = g.shortest_path(1);
    assert(dstV[0] == 7);
    assert(dstV[1] == 0);
    assert(dstV[2] == 2);
    assert(dstV[3] == 12);

    cout << "\nTests done..." << endl;
}

int main () {
    test_graph();
}