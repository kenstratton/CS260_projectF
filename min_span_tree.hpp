#include <iostream>
#include <vector>

using namespace std;

struct MinSpanTree {
    vector<int> parent;
    vector<int> data_sizes;

    MinSpanTree (int n)
        : parent(n), data_sizes(n, 1)
        { for (int i=0; i < n; i++) parent[i] = i;}

    int find (int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }

    void merge (int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;
        if (data_sizes[x] < data_sizes[y]) swap(x, y);

        parent[y] = x;
        data_sizes[x] += data_sizes[y];
    }
};