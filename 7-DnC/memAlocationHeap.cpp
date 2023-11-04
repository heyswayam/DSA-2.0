#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int *num1 = new int(5);
    // cout << num1 << endl;
    // int *num2 = (int *)malloc(4);
    // *num2 = 4;
    // cout << *num2 << endl;

    // using malloc
    int *arrmalloc = (int *)malloc(5 * sizeof(int));

    // for (int i = 0; i < 5; i++)
    // {
    //     int d;
    //     cin >> d;
    //     arrmalloc[i] = d;
    // }
    arrmalloc[0] = 1;
    arrmalloc[1] = 4;
    arrmalloc[2] = 9;
    arrmalloc[3] = 7;
    arrmalloc[4] = 5;

    // for (int i = 0; i < 5; i++)
    // {
    //     cout <<arrmalloc[i] << endl;
    // }
    free(arrmalloc);
    cout << *(arrmalloc + 3);
    return 0;
}