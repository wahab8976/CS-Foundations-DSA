#include "bits/stdc++.h"


void generateSubsets(int k, int n, vector<int>& subsets) {
    // Base Case: If we have made a decision for all elements from 1 to n
    if (k == n + 1) {
        // Process Subset: Print it out
        cout << "{ ";
        for (int x : subsets) {
            cout << x << " ";
        }
        cout << "}\n";
        return;
    }

    // Include element 'k' in the current subset
    subsets.push_back(k);
    generateSubsets(k + 1, n, subsets); 

    // Exclude element 'k' (Backtrack step)
    subsets.pop_back();
    generateSubsets(k + 1, n, subsets); 
}


int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<int> current_subset;

    cout << "Generating all subsets for elements 1 to " << n << ":\n";
    // Start processing from element 1 up to n
    generateSubsets(1, n, current_subset);

    return 0;
}