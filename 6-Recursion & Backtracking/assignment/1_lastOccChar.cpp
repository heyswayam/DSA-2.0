#include <bits/stdc++.h>
using namespace std;

int lastOcc(string &s, char &ch, int index)
{
    if (index == s.size()) // B.C
    {
        return -1;
    }
    int ans = -1;
    if (s[index] == ch) // Processing
    {
        ans = index;
    }
    int temp = lastOcc(s, ch, index + 1); // Recursive call
    if (temp != -1)
    {
        ans = temp;
    }
    return ans;
}

void lastOccLtoR(string &s, char &ch, int index, int &ans)
{
    if (index == s.size())
    {
        return;
    }

    if (s[index] == ch)
    {
        ans = index;
    }
    lastOccLtoR(s, ch, index + 1, ans);
}

void lastOccRtoL(string &s, char &ch, int index, int &ans)
{
    if (index < 0)
    {
        return;
    }

    if (s[index] == ch)
    {
        ans = index;
        return;
    }

    lastOccRtoL(s, ch, index - 1, ans);
}

int main()
{
    string s = "wee";
    char ch = 'd';
    // method 1
    // cout << lastOcc(s, ch, 0);

    // method 2
    // int ans = -1;
    // lastOccLtoR(s,ch,0,ans);
    // cout<<ans<<endl;

    int ans = -1;
    lastOccRtoL(s, ch, s.size() - 1, ans);
    cout << ans << endl;
    return 0;
}