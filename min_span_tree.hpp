#include <iostream>
#include <vector>

using namespace std;

/*******************************************
Minimum spanning tree fuction :
 * 1. Generate edge matrix (node id is stored as destination, 0->no link)
 * 2. Execute the shortest path algorithm with the matrix (*1)
********************************************/
struct MinSpanTree {
    vector<int> parent;
    vector<int> data_sizes;

    MinSpanTree (int n)
        : parent(n), data_sizes(n, 1)
        { for (int i=0; i < n; i++) parent[i] = i;}

    // Search a source node
    int find (int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    // Mearge a tree (x and y belong to)
    void merge (int x, int y) {
        x = find(x);
        y = find(y);

        // Stop merging if they are already related
        if (x == y) return;

        if (data_sizes[x] < data_sizes[y]) swap(x, y);
        parent[y] = x;
        data_sizes[x] += data_sizes[y];
    }
};
