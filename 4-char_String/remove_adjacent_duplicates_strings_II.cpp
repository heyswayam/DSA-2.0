#include <iostream>
#include <vector>
using namespace std;

string removeDuplicates(string s, int k)
{
    string ans = "";
    int count = 0;
    int times = k;

    for (int i = 0; i < s.length(); i++)
    {
        if (ans.length() - 1 >= k - 1)
        {
            for (int j = ans.length() - 1; j >= k; i--)
            {
                if (ans[j] != s[i])
                {
                    ans.push_back(s[i]);
                    break;
                }
                count++;
            }
        }

        else if (ans.length() - 1 < k - 1)
        {
            ans.push_back(s[i]);
        }

        else if (count == k - 1)
        {
            while (times - 1)
            {
                ans.pop_back();
                times--;
            }
        }
    }
    return ans;
}

int main()
{
    string s="deeedbbcccbdaa";
    int k=2;
    cout<<"New string: "<<removeDuplicates(s,k);
    return 0;
}