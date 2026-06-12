#include<bits/stdc++.h>
using namespace std;

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        long long totalCombos = ((i * i) * ((i * i) - 1)) / 2;
        long long attackCombos = 4 * (i - 1) * (i - 2);
        cout << totalCombos - attackCombos << "\n";
    }

    return 0;
}