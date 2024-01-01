#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["a"] = 2;
    for (auto &i : mp)
    {
        cout<<"first: "<<i.first;       //uses
        cout<<" second: "<<i.second;
        cout<<endl;
    }

    cout << mp.begin()->first<<endl;
    return 0;
}