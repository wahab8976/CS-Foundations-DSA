#include "bits/stdc++.h"

void permutations(int n, vector<int>& current_perm, vector<bool>& choosen) {
    if (current_perm.size() == n) {
        // Process Permutations
        cout << "Permutations are \n";

        for (int i = 0; i < n; i++)  cout << current_perm[i] << " ";
        cout << "\n";
        return;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (choosen[i])  continue;
            
            current_perm.push_back(i);
            choosen[i] = true;
            permutations(n, current_perm, choosen);  // Choose Current Element (i)

            current_perm.pop_back();
            choosen[i] = false;
        }
    }
}


int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<int> current_perm;
    vector<bool> choosen(n + 1, false);
    
    permutations(n, current_perm, choosen);
    return 0;
}