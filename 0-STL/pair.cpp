#include <bits/stdc++.h>

using namespace std;

int main()
{
    // pair<int,string> p[]={{1,"car"},{3,"bus"}};  gives error
    pair<int, string> p[5]; // need to give size

    p[0] = make_pair(3, "hello");
    p[1] = make_pair(3, "hello");
    cout << p[0].first << " " << p[0].second << endl;
    cout << p[1].first << " " << p[1].second << endl;

    return 0;
}