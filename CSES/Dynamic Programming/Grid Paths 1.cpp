/*
Time limit: 1.00 s
Memory limit: 512 MB

Consider an n \times n grid whose squares may have traps. It is not allowed to move to a square with a trap.
Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.
Input
The first input line has an integer n: the size of the grid.
After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.
Output
Print the number of paths modulo 10^9+7.
Constraints

1 <= n <= 1000

Example
Input:
4
....
.*..
...*
*...

Output:
3
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Recursive Memoization

int solve(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& dp) 
{
    // If out of bounds or blocked cell → no path
    if (row < 0 || col < 0 || grid[row][col] == '*') 
        return 0;

    // Base case: reached start (0,0)
    if (row == 0 && col == 0) 
        return 1;

    if (dp[row][col] != -1) 
        return dp[row][col];

    // Option 1: move from top
    int up = solve(row - 1, col, grid, dp);

    // Option 2: move from left
    int left = solve(row, col - 1, grid, dp);

    return dp[row][col] = (up + left) % mod;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];
    }

    // If start or end blocked → no path
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') 
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << solve(n - 1, n - 1, grid, dp) << "\n";
    return 0;
}
// Tabulation
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
 
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
            cin >> grid[i][j];
    }
 
    // If start or end blocked → no path
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') 
    {
        cout << 0 << "\n";
        return 0;
    }
 
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1; // base case
 
    for (int row = 0; row < n; row++) 
    {
        for (int col = 0; col < n; col++) 
        {
            if (grid[row][col] == '*') 
            {
                dp[row][col] = 0;
                continue;
            }
            if (row > 0) dp[row][col] = (dp[row][col] + dp[row - 1][col]) % mod;
            if (col > 0) dp[row][col] = (dp[row][col] + dp[row][col - 1]) % mod;
        }
    }
 
    cout << dp[n - 1][n - 1] << "\n";
    return 0;
}