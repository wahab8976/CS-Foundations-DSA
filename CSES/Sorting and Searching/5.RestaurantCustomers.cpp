#include<bits/stdc++.h>
using namespace std;
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n)) return 0;
    map<int, int> intervals;

    while (n--) {
        int s = 0;
        int e = 0;
        cin >> s >> e;
        // Build the intervals
        intervals[s] = 1;
        intervals[e] = -1;
    }

    int sum = 0;
    int maxSum = 0;
    // Sweep the line
    for (auto it : intervals) {
        sum += it.second;
        maxSum = max(maxSum, sum);
    }
    
    cout << maxSum << endl;
    return 0;
}