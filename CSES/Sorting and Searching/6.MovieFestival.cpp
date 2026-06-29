#include<bits/stdc++.h>
using namespace std;
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n)) return 0;
    vector<pair<int, int>> movies(n);

    for (int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }

    // Sort according to finishing time
    sort(movies.begin(), movies.end());
    int maxMovies = 0;
    int lastEndTime = -1;

    for (int i = 0; i < n; i++) {
        int start = movies[i].second;
        int end = movies[i].first;

        // This problem is not related to overlapping of intervals. We need non overlapping intervals. 
        // We Can only watch movie, once we finished one. Because we can only watch one movie at a time. So, we can only watch the next movie if it starts after or when the last movie ends.
        if (start >= lastEndTime) {
            maxMovies++;
            lastEndTime = end;
        }
    }

    cout << maxMovies << endl;
    return 0;
}