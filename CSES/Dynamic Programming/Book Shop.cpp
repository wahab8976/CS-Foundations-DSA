/*
Time limit: 1.00 s
Memory limit: 512 MB

You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x. What is the maximum number of pages you can buy? You can buy each book at most once.
Input
The first input line contains two integers n and x: the number of books and the maximum total price.
The next line contains n integers h_1,h_2,\ldots,h_n: the price of each book.
The last line contains n integers s_1,s_2,\ldots,s_n: the number of pages of each book.
Output
Print one integer: the maximum number of pages.
Constraints

1 <= n <= 1000
1 <= x <= 10^5
1 <= h_i, s_i <= 1000

Example
Input:
4 10
4 8 5 3
5 12 8 1

Output:
13

Explanation: You can buy books 1 and 3. Their price is 4+5=9 and the number of pages is 5+8=13.
*/

#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// Recursive Memoization
int solve(int index, int budget, vector<int>& prices, vector<int>& pages, vector<vector<int>>& dp) {
    // Base case: first book
    if (index == 0) 
    {
        if (budget >= prices[0]) 
            return pages[0];
        else
            return 0;
    }

    if (dp[index][budget] != -1) 
        return dp[index][budget];

    // Option 1: don't take this book
    int doNotPick = solve(index - 1, budget, prices, pages, dp);

    // Option 2: take this book (if budget allows)
    int pick = -1e9;
    if (budget >= prices[index]) 
        pick = pages[index] + solve(index - 1, budget - prices[index], prices, pages, dp);

    return dp[index][budget] = max(doNotPick, pick);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n), pages(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    cout << solve(n - 1, x, prices, pages, dp) << "\n";
    return 0;
}

// Tabulation
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, x;
    cin >> n >> x;
 
    vector<int> prices(n);
    vector<int> pages(n);
 
    for (int i = 0; i < n; i++)   cin >> prices[i];
    for (int i = 0; i < n; i++)   cin >> pages[i];
 
    vector<vector<int>> dp(n, vector<int>(x + 1, -1));
 
    
    for (int budget = 0; budget <= x; budget++)
    {
        if (budget >= prices[0])
            dp[0][budget] = pages[0];
        else
            dp[0][budget] = 0;
    }
    
    for (int index = 1; index < n; index++)
    {
        for (int budget = 0; budget <= x; budget++)
        {
            int doNotPick = dp[index - 1][budget];
            int pick = -1e9;
            if (budget >= prices[index])
                pick = pages[index] + dp[ index - 1][ budget - prices[index]];
 
            dp[index][budget] = max(doNotPick, pick);
        }
    }
    cout << dp[n - 1][x];
    return 0;
}