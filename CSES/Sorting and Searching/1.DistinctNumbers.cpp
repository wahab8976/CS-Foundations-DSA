#include<bits/stdc++.h>
using namespace std;
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> st;

    int n = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x = 0; 
        cin >> x;
        st.insert(x);
    }
        
    cout << st.size();

    return 0;
}