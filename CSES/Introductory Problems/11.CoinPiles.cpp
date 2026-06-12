#include<bits/stdc++.h>
using namespace std;

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        int res = ((a + b) % 3);
        // Piles sum must be divisble by 3
        // One pile should not be double than other
        if (res == 0 && min(a, b) * 2 >= max(a,b)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}