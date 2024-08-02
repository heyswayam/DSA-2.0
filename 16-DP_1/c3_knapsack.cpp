#include <bits/stdc++.h>
using namespace std;

int usingRecursion(int capacity, vector<int> wt, vector<int> profit, int n, int index)
{
    if (index == n)
    {
        return 0;
    }

    int inc = 0;
    if (wt[index] <= capacity)
    {
        inc = profit[index] + usingRecursion(capacity - wt[index], wt, profit, n, index + 1);
    }
    int exc = 0 + usingRecursion(capacity, wt, profit, n, index + 1);

    return max(inc, exc);
}

int usingMemo(int capacity, vector<int> wt, vector<int> profit, int n, int index, vector<vector<int>> dp)
{
    if (index == n)
    {
        return 0;
    }

    if (dp[capacity][index] != -1)
        return dp[capacity][index];

    int inc = 0;
    if (wt[index] <= capacity)
    {
        inc = profit[index] + usingRecursion(capacity - wt[index], wt, profit, n, index + 1);
    }
    int exc = 0 + usingRecursion(capacity, wt, profit, n, index + 1);

    return dp[capacity][index] = max(inc, exc);
}

int solveUsingTabulation(int capacity, vector<int> wt, vector<int> profit, int n)
{
    vector<vector<int>> dp(capacity + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= capacity; i++)     //starting from i = 0, becoz in memo we had capacity-wt[0], so it was decreasing to 0 from capacity and here we took its reverse
    {
        for (int j = n-1; j >= 0; j--)  //j = n-1
        {
            int inc = 0;
            if (wt[j] <= i)
            {
                inc = profit[j] + dp[i - wt[j]][j + 1];
            }
            int exc = 0 + dp[i][j + 1];

            dp[i][j] = max(inc, exc);
        }
        
    }
    return dp[capacity][0]; //becoz the loops ends at capacity and index = 0
                            // hum usse return krte h, which we have passed into recursion i.e capacity, 0
}

int main()
{

    int capacity = 6;
    vector<int> wt{1, 2, 3};
    vector<int> profit{10, 15, 40};
    int n = 3;

    int ans = 0;
    // ans = usingRecursion(capacity,wt, profit, n,0);
    // vector<vector<int>> dp(capacity + 1, vector<int>(n, -1)); // for playing safe u can give size+1 or size+10
    // ans = usingMemo(capacity, wt, profit, n, 0, dp);
    ans = solveUsingTabulation(capacity, wt, profit, n);
    cout << "max Profit: " << ans << endl;

    return 0;
}