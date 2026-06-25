#include<bits/stdc++.h>
using namespace std;
/*
    Greedy approach Combined with 2 pointers
*/
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    if (!(cin >> n >> x)) return 0;
    
    vector<int> children(n);
    for (int i = 0; i < n; i++)  cin >> children[i];

    sort(children.begin(), children.end());

    int i = 0;             
    int j = n - 1;      
    int gondolaCnt = 0;

    while (i <= j) {
        if (i == j) {
            gondolaCnt++;
            break; 
        }
        // If the lightest child (i) and heaviest child (j) can share
        if (children[i] + children[j] <= x) {
            i++;
            j--; 
        } 
        else {
            j--; // Heaviest child gets in alone, move to the next heaviest
        }
        gondolaCnt++; 
    }
    cout << gondolaCnt << "\n";
    return 0;
}