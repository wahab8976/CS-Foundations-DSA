/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an integer n. On each step, you may subtract one of the digits from the number.
How many steps are required to make the number equal to 0?
Input
The only input line has an integer n.
Output
Print one integer: the minimum number of steps.
Constraints

1 \le n \le 10^6

Example
Input:
27

Output:
5

Explanation: An optimal solution is 27 -> 20 -> 18 -> 10 -> 9 -> 0.
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

// Recursive Memoization
int solve(int x,vector<int>& dp)
{
    if (x == 0)    
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int best = INT_MAX;
    int num = x;

    while (x > 0)
    {
        int digit = x % 10;
        x /= 10;

        if (digit == 0)  continue;

        int ans = solve(num - digit,dp);

        if (ans != INT_MAX)
            best = min(best, ans + 1);
        
    }
    return dp[num] = best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int num;
        cin >> num;
        vector<int> dp(num + 1, -1);
        cout << solve(num, dp) << endl;
    }
}

// Tabulation
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int num;
    cin >> num;
 
    vector<int> dp(num + 1, 1e9);
    dp[0] = 0;   // base case
 
    for (int x = 1; x <= num; x++)
    {
        int temp = x;  // keeping copy
        while (temp > 0)
        {
            int digit = temp % 10;
            temp /= 10;
 
            if (digit == 0) continue;
 
            dp[x] = min(dp[x], dp[x - digit] + 1);
        }
    }
 
    cout << dp[num] << "\n";
}