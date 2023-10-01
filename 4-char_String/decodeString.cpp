#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>

using namespace std;
void repeatString(string &str, int val)
{
    string result = str;
    while (val--)
    {
        for (auto x : str)
        {
            result.push_back(x);
        }
    }

    str = result;
}

int main()
{
    string s = "ha22";

    string tape;

    for (auto x : s)
    {

        if (x >= 48 && x <= 57)
        {
            int value = x - '0';
            value = value - 1; // given in question to repeat value-1 times
            cout << endl
                 << endl
                 << endl
                 << " value: " << value << endl
                 << endl;

            repeatString(tape, value);
        }
        else
        {
            tape.push_back(x);
        }
    }
    int k=5;
    string a(1,tape[k-1]);

    cout<< a;

    return 0;
}
