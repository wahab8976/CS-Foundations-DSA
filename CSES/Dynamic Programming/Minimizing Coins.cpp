/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= c_i <= 10^6

Example
Input:
3 11
1 5 7

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int INF = 1e9; 
// Recursive Memoization
int solve(int index, int target, vector<int>& coins, vector<vector<int>>& dp) 
{
    // Base case: only first coin available
    if (index == 0) 
    {
        if (target % coins[0] == 0) 
            return target / coins[0];
        else 
            return INF;
    }

    if (dp[index][target] != -1) 
        return dp[index][target];

    // Option 1: do not pick this coin
    int doNotPick = solve(index - 1, target, coins, dp);

    // Option 2: pick this coin (infinite supply allowed)
    int pick = INF;
    if (coins[index] <= target) 
        pick = 1 + solve(index, target - coins[index], coins, dp);
    
    return dp[index][target] = min(doNotPick, pick);
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

    int ans = solve(n - 1, x, coins, dp);

    if (ans >= INF) cout << -1 << "\n";
    else cout << ans << "\n";

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
    vector<vector<int>> dp(n, vector<int>(x+1, 1e9));
 
    // Base Case
    for (int target = 0; target <= x; target++)
    {
        if (target % coins[0] == 0)
            dp[0][target] = target / coins[0];
        else
            dp[0][target] = 1e9;
    }
 
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= x; target++)
        {
            int doNotPick = dp[index-1][ target];
            int pick = 1e9;
 
            if (target >= coins[index])
                pick = 1 + dp[index][ target - coins[index]];
 
            dp[index][target] = min(doNotPick, pick);
        }
    }
 
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}