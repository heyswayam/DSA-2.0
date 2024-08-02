#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, pair<int, int>> mp;
    mp.insert({4, {2, 3}});
    // mp.insert({3,2});
    // mp.insert({2,2});
    // mp.insert({1,2});
    for (auto &i : mp)
    {
        cout << "first: " << i.first; // uses
        cout << " second: " << i.second.first;
        cout << endl;
    }

    // cout << mp.begin()->first<<endl;
    return 0;
}