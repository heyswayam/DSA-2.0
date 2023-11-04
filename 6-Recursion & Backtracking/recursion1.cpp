#include <bits/stdc++.h>
using namespace std;

// fibonacci
int fibo(int n)
{
    if (n == 1) // base cases
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    return fibo(n - 1) + fibo(n - 2); // recursive relation
}

int exp(int base, int n)
{
    if (n == 0)
    { // base case
        return 1;
    }

    return base * exp(base, n - 1); // recursive relation
}

int main()
{
    // cout << fibo(7);
    cout << exp(2, 0);
    return 0;
}