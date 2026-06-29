#include<bits/stdc++.h>
using namespace std;
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    // {val, index}
    map<int, int> mp;
    vector<int> vals(n);

    for (int i = 0; i < n; i++) cin >> vals[i];

    for (int i = 0; i < n; i++) {
        /*
            x + y = target
            y = target - x
        */ 

        int reqVal = x - vals[i];
        auto it = mp.find(reqVal);  // if x found
        
        if (it != mp.end()) {
            int a = it->second + 1;
            int b = i + 1;
            cout << a << " " << b << endl;
            return 0;
        }
        mp[vals[i]] = i;    // If x is not found, store the value and index in map for future reference
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}