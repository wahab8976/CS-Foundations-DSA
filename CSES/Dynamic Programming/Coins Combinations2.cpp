/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= c_i <= 10^6

Example
Input:
3 9
2 3 5

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Recursive Memoization
int solve(int index, int target, vector<int>& coins, vector<vector<int>>& dp) 
{
    // Base case: only coin[0] available
    if (index == 0) 
    {
        if (target % coins[0] == 0) return 1;
            return 0;
    }

    if (dp[index][target] != -1) 
        return dp[index][target];

    // Choice 1: Do not pick this coin
    int doNotPick = solve(index - 1, target, coins, dp);

    // Choice 2: Pick this coin (stay at same index, because infinite supply)
    int pick = 0;
    if (target >= coins[index])
        pick = solve(index, target - coins[index], coins, dp);

    return dp[index][target] = (pick + doNotPick) % mod;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    cout << solve(n - 1, x, coins, dp) << "\n";
    return 0;
}

// Tabulation
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
 
    for (int i = 0; i < n; i++)   cin >> coins[i];
    
    vector<vector<int>> dp(n, vector<int>(x + 1, 0));
 
 
    // Base Case
    for (int i = 0; i <= x; i++)
        if ((i % coins[0]) == 0)
            dp[0][i] = 1;
 
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= x; target++)
        {
            int doNotPick = dp[index - 1][target];
            int pick = 0;
            if (target >= coins[index])
                pick = (dp[index][target - coins[index]]) % mod;
            dp[index][target] = (pick + doNotPick) % mod;
        }
    }
    cout << dp[n-1][x];
    return 0;
}