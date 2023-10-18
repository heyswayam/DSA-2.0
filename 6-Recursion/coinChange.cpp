#include <bits/stdc++.h>
using namespace std;

// method 1
// int coinChange(vector<int> coins, int amount)
// {
//     if (amount == 0)
//     {
//         return 0;
//     }
//     int mini = INT_MAX;

//     for (int i = 0; i < coins.size(); i++)
//     {
//         if (coins[i] <= amount)
//         {
//             int recAns = coinChange(coins, amount - coins[i]);
//             if (recAns != INT_MAX)
//             {
//                 int ans = 1 + recAns;
//                 mini = min(mini, ans);
//             }
//         }
//     }

//     return mini;
// }

// method 2
// int coinChange(vector<int> coins, int amount)
// {
//     if (amount == 0)
//     {
//         return 0;
//     }

//     // if (amount < 0)
//     // {
//     //     return INT_MAX;
//     // }
//     int mini = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         if (coins[i] <= amount)
//         {

//             int recAns = coinChange(coins, amount - coins[i]);
//             if (recAns != INT_MAX)
//             {
//                 int ans = 1 + recAns;
//                 mini = min(ans, mini);
//             }
//         }
//     }

//     return mini;
// }

int solve(vector<int> &coins, int amount)
{
    // base case
    if (amount == 0)
    {
        return 0;
    }

    // if (amount < 0)
    //     return INT_MAX;

    int mini = INT_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        // current coin ko sir tabhi use krenge
        // jab uski value <= amount hogi
        if (coin <= amount)
        {
            int recAns = solve(coins, amount - coin);
            if (recAns != INT_MAX)
            {
                int ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}
int main()
{
    vector<int> coins{4, 5};
    int amount = 2;
    cout << solve(coins, amount);
    return 0;
}