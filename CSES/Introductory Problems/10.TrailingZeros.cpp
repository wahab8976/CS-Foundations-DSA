#include<bits/stdc++.h>
using namespace std;

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long zeroCount = 0;
    
    // Legenders Formula
    while (n >= 5) {
        zeroCount += n / 5;
        n /= 5;
    }
    cout << zeroCount << endl;
    return 0;
}