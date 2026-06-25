#include<bits/stdc++.h>
using namespace std;
/*
    Greedy approach Combined with 2 pointers
*/
int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<int> applicants(n);
    vector<int> apartments(m);


    for (int i = 0; i < n; i++)  cin >> applicants[i];
    for (int i = 0; i < m; i++)  cin >> apartments[i];

    
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0;
    int satisf = 0;
    while (i < n && j < m) {
        // Apartment Alloted
        if (apartments[j] >= applicants[i] - k && apartments[j] <= applicants[i] + k) {
            i++;
            j++;
            satisf++;
        }
        else if (apartments[j] < applicants[i] - k) {   // Apartment is too small
            j++;
        }
        else {  // Apartment is too large
            i++;
        }
    }

    cout<< satisf;
}