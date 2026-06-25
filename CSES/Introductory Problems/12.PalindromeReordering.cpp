#include<bits/stdc++.h>
using namespace std;

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);
    int n = str.size();

    vector<int> freq(26, 0);
    // Count Occurences of characters
    for (int i = 0; i < n; i++) {
        char ch = str[i];
        freq[ch - 'A']++;
    }

    // Track Odd occurences of characters
    int oddCount = 0;
    int oddIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            oddCount++;
            oddIndex = i;
        }
    }


    if (oddCount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string strLeft = "";
    // Build left side
    for (int i = 0; i < 26; i++) {
        int buildCount = freq[i] / 2;
        for (int j = 0; j < buildCount; j++) {
            strLeft += char('A' + i);
        }
    }

    string strRight = strLeft;
    reverse(strRight.begin(), strRight.end());

    // Place Odd Characters
    if (oddIndex != -1) {
        strLeft += char('A' + oddIndex);
    }

    cout << strLeft << strRight << " ";
    return 0;
}