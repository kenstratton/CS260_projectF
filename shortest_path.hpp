#include <iostream>
#include <climits>

using namespace std;


struct ShortestPath {
    // Return a minimum distance for a specified node
    int min_dst (int v, int dst[], bool mrk[]) {
        int min = INT_MAX,idx;

        for (int i=0; i<v; i++) {
            // Check if the node isnt marked as unpassed
            if (mrk[i]==false && dst[i]<=min) {
                min=dst[i];
                idx=i;
            }
        }

        return idx;
    }

    // Get minimum distances for each node
    vector<int> calc_path (int v, vector<vector<int>> matrix, int src) {
        int dst[v]; // Minimum distance between source and each node
        bool mrk[v]; // Passed or not

        for (int i = 0; i<v; i++) {
            dst[i] = INT_MAX; // Infinite distance
            mrk[i] = false;	// Unpassed
        }
        dst[src] = 0;

        // Update path info of each node once per recurrence (a number of nodes)
        for (int i = 0; i<v; i++) {
            int min = min_dst(v, dst, mrk);
            mrk[min] = true; // Passed
            for (int i = 0; i<v; i++) {
                if (!mrk[i] &&
                matrix[min][i] &&
                dst[min]!=INT_MAX &&
                dst[min]+matrix[min][i]<dst[i])
                    // Update the path distance to a particular node
                    dst[i] = dst[min] + matrix[min][i];
            }
        }

        vector<int> dstV;
        for (auto d: dst) dstV.push_back(d);

        return dstV;
    }
};