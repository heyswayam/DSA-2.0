#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &coins, int amount, vector<int> &value)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return -1;
    }
    int ans=-1;
    for (int i = 0; i < coins.size(); i++)
    {
        if (coins[i] <= amount)
        {
            int recAns = recursion(coins, amount - coins[i], value);
            if (recAns != -1)
            {
                ans = 1 + recAns;
            }
            value[0]=ans;
        }
    }
    return ans;
}
void coinChange(vector<int> &coins, int amount)
{
    vector<int> value(1);

cout<<endl<<"before function"<<endl<<endl;
    int a = recursion(coins, amount, value);
    for (auto &&i : value)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> coins{4,5};
    int amount = 11;
    coinChange(coins, amount);
    return 0;
}