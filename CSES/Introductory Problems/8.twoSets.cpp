#include<bits/stdc++.h>
using namespace std;


int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // Sum of first n Natural Numbers
    long long total = ((long long)n * (n + 1)) / 2;
    if (total % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    // Divide into 2 subsets and fill them greedily
    vector<int> set1;
    vector<int> set2;

    long long val = n;
    
    long long target = total / 2;

    while (val > 0) {
        if (val <= target) {
            set1.push_back(val);
            target -= val;
        }
        else {
            set2.push_back(val);
        }
        val--;
    }
    
    cout << "YES\n";
    cout << "\n" << set2.size() << "\n";
    for (int i : set2)   cout << i << " ";
    cout << "\n" << set1.size() << "\n";
    for (int i : set1)   cout << i << " ";

    return 0;
}