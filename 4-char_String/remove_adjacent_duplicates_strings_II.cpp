#include <iostream>
#include <vector>
using namespace std;

string removeDuplicates(string s, int k)
{
    string temp;
    int count = 0;
    for (auto ch : s)
    {
        if (temp.size() > 0 && count == k - 1)
        {

            int a = k;
            while (a--)
            {
                temp.pop_back();
            }
            temp.push_back(ch);
            count=0;
        }

        else
        {
            if (temp.size() > 0)
            {
                if (temp[temp.size() - 1] == ch)
                {
                    count++;
                }
                else count=0;
            }
                temp.push_back(ch);
        }
    }

    return temp;
}

int main()
{
    string s = "abbbcd";
    int k = 2;
    cout << "New string: " << removeDuplicates(s, k);
    return 0;
}