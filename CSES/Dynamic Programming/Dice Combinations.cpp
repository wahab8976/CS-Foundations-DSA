/*
Time limit: 1.00 s
Memory limit: 512 MB

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 <= n <= 10^6

Example
Input:
3

Output:
4
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Recursive Memoization
int solve(int n, vector<int>& dp) 
{
    // base case
    if (n == 0) return 1;   // one way to make sum 0
    if (n < 0) return 0;    // no way to make negative sum

    if (dp[n] != -1) return dp[n];

    long long ways = 0;
    for (int dice = 1; dice <= 6; dice++) 
        ways = (ways + solve(n - dice, dp)) % mod;
    
    return dp[n] = ways;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << solve(n, dp) << "\n";
    return 0;
}

// Tabulation
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<int> dp(n + 1, 0);
 
    dp[0] = 1; // base case
 
    for (int i = 1; i <= n; i++)  
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
 
    cout << dp[n] << "\n";
    return 0;
}