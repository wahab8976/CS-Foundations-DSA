#include<bits/stdc++.h>
using namespace std;
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    multiset<int> tickets;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tickets.insert(t);
    }

    for (int i = 0; i < m; i++) {
        int custBudget;
        cin >> custBudget;
        
        // Get Exact or Greater
        auto it = tickets.lower_bound(custBudget);
        if (it!= tickets.end() && *it == custBudget) {
            cout << custBudget << endl;
            tickets.erase(it);
        }
        else {  // We didnt't get exact, it must be a greater value than budget
            if (it == tickets.begin()) { // Nothing, can be more further smaller
                cout << -1 << endl;
            }
            else {  // We find, smaller than budget
                it--;
                cout << *it << endl;
                tickets.erase(it);
            }
        }
    }
    return 0;
}