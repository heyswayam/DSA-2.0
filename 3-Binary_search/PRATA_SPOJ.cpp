#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long int> &rank, long long int mid, long long int totalP)
{
    long long int parata = 0;

    for (long long int i = 0; i < rank.size(); i++)
    {
        long long int N = 0, time = 0;
        while (time <= mid)
        {
            N++;
            time += N * rank[i];
        }
        parata += (N - 1);

        if (parata >= totalP)
        {
            return true;
        }
    }


    return false;
}
int main()
{
    int T; cin>>T;
    while (T--)
    {
    long long int totalP, chef;
    cin >> totalP >> chef;
    vector<long long int> rank(chef);

    long long int i = 0;
    while (chef--)
    {
        cin >> rank[i++];
    }

    long long int s = 0;

    long long int lastRank = *max_element(rank.begin(), rank.end());
    long long int e = lastRank * totalP * (totalP + 1) / 2;

    long long int ans = -1;

    while (s <= e)
    {
        long long int mid = s + (e - s) / 2;
        if (check(rank, mid, totalP))
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
        }
    }

    cout << ans<<endl;
    }

    return 0;
}