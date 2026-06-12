/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

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
8
*/

#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Recursive Memoization
long long solve(int target, vector<int>& coins, vector<long long>& dp) 
{
    if (target == 0) 
        return 1; // one way: choose nothing
    if (dp[target] != -1) 
        return dp[target];

    long long ways = 0;
    for (int coin : coins) 
    {
        if (target - coin >= 0) 
            ways = (ways + solve(target - coin, coins, dp)) % mod;
        
    }
    return dp[target] = ways;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<long long> dp(x + 1, -1);

    cout << solve(x, coins, dp) << "\n";
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
    vector<long long> dp(x + 1,0);
 
    dp[0] = 1;
    int ans = 0;
    for (int target = 1; target <= x;target++)
    {
        for (int coin = 0; coin < n; coin++)
        {
            if(target >= coins[coin])
                dp[target] = (dp[target] + dp[target - coins[coin]]) % mod;
        }
    }
    
    cout << dp[x];
 
    return 0;
}