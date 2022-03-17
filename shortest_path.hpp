#include <iostream>
#include <climits>

using namespace std;

struct ShortestPath {
    int min_dst (int v, int dst[], bool mrk[]) {
        int min = INT_MAX,idx;
        for (int i=0; i<v; i++) {
            if (mrk[i]==false && dst[i]<=min) {
                min=dst[i];
                idx=i;
            }
        }
        return idx;
    }

    vector<int> calc_path (int v, vector<vector<int>> matrix, int src) {
        int dst[v];
        bool mrk[v];

        for (int i = 0; i<v; i++) {
            dst[i] = INT_MAX;
            mrk[i] = false;	
        }

        dst[src] = 0;
        for (int i = 0; i<v; i++) {
            int min = min_dst(v, dst, mrk);
            mrk[min] = true;
            for (int i = 0; i<v; i++) {
                if (!mrk[i] &&
                matrix[min][i] &&
                dst[min]!=INT_MAX &&
                dst[min]+matrix[min][i]<dst[i])
                    dst[i] = dst[min] + matrix[min][i];
            }
        }

        vector<int> dstV;
        for (auto d: dst) dstV.push_back(d);
        return dstV;
    }
};