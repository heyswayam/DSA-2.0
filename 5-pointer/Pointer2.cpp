#include <bits/stdc++.h>
using namespace std;

void func(int *arr)
{
    cout << arr << endl;
    cout << sizeof(arr);
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 7};
    // int(*ptr)[6] = &arr;
    // cout << arr + 3 << " " << &arr[3] << endl;
    // cout << ptr << endl;
    // cout << 3 [arr] << endl;
    // cout << arr[3] << endl;
    func(arr);
    return 0;
}