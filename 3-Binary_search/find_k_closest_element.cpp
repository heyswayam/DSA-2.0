#include <bits/stdc++.h>
using namespace std;

// method 1: Using comparator function
bool my_comp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
    {
        a.first < b.first;
    }
}
int main()
{
    
    int arr[] = {1, 2, 3, 4, 5}, k = 4, x = 3; // x = number to be subtracted //k= number of elements required in return
    int size = 5;
    vector<pair<int, int> > p(size);
    vector<int> ans(k);
    for (int i = 0; i < size; i++)
    {
        p[i].first = arr[i];
        p[i].second = abs(arr[i] - x);
    }
    sort(p.begin(), p.end(), my_comp);

    for (auto &&i : p)
    {
        cout << i.first << " " << i.second << endl;
    }

    for (int i = 0; i < k; i++)
    {
        ans[i] = p[i].first;
    }
    sort(ans.begin(), ans.end());

    for (auto &&i : ans)
    {
        cout<<i<<" ";
    }


    return 0;
}
