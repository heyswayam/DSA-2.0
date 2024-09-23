#include <bits/stdc++.h>
using namespace std;
void getSubsequences(string str)
{
    int n = str.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        // number is ready
        // use num, to create subsequences

        // num -> set bit -> index -> char -> incl
        string temp = "";
        for (int i = 0; i < n; i++)
        {
            // i -> represent index
            char ch = str[i];
            // agar i index pr num k andar set bit present hai
            // toh character ko include krdlo
            int mask = (1 << i);
            if (num & mask)
            {
                temp.push_back(ch);
            }
        }
        ans.push_back(temp);
    }

    cout << "printing the subsequences: " << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
}
int main()
{
    // getSubsequences("abc");
    cout << ((1 << 1));
    return 0;
}