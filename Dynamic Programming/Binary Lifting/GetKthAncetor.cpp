#include "bits/stdc++.h"

/*
    This technique is useful to find ancestor a node in Efficient Way
    1) Builds a mapped table using Dynamic Programming.
    2) Queries by jumping in power of 2 to get the Ancestor of a given Node. E.g: 5 -> 2 pow 2 + 2 pow 0
*/

class TreeAncestor {
public:
    vector<vector<int>> ancestor; 
    int rows;
    int cols;

    TreeAncestor(int n, vector<int>& parent) {
        rows = n;
        cols = log2(n) + 1;
        ancestor.resize(rows, vector<int> (cols, -1));

        // Fill the first column
        for(int i = 0; i < n; i++){
            ancestor[i][0] = parent[i];
        }

        // Fill the remaining Table, using Binary Lifting
        for(int j = 1; j < cols; j++){
            for(int node = 0; node < n; node++){
                if(ancestor[node][j -1] != -1){
                    ancestor[node][j] = ancestor[ancestor[node][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < cols; i++){
            if(k & (1 << i)){   // If ith bit is set, we can take a jump to that bit
                node = ancestor[node][i];

                if(node == -1)  return -1;  // We have gone beyond the ultimate parent
            }
        }
        return node;
    }
};
