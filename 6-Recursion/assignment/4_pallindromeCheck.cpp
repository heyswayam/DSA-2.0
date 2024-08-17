#include <bits/stdc++.h>
using namespace std;
bool isPallindrome(string &str, int s, int e)
{
    if (s > e)
    {
        return 1;
    }
    bool ans = 0;
    if (str[s] == str[e])
    {
        ans = isPallindrome(str, s + 1, e - 1);
    }

    return ans;
}
int main()
{
    string str = "racecarr";
    int s = 0;
    int e = str.size() - 1;
    cout << isPallindrome(str, s, e);
    return 0;
}