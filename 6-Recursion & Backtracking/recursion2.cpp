#include <bits/stdc++.h>
using namespace std;

int steps(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    return steps(n - 1) + steps(n - 2);
}

void printArr(int *arr, int size, int index)
{
    if (index == size)
        return;

    cout << arr[index] << " ";
    printArr(arr, size, index + 1);
}

bool search(int *arr, int size, int index, int target)
{
    if (index == size)
        return 0;

    if (arr[index] == target)
        return 1;

    search(arr, size, index + 1, target);
}


void minNum(int *arr, int size, int index, int &mini){
    if(index==size) return;

    mini=min(arr[index],mini);

    minNum(arr,size,index+1,mini);
}

void maxNum(int *arr, int size, int index, int* maxi){
    if(index==size) return;

   *maxi=max(arr[index],*maxi);

    maxNum(arr,size,index+1,maxi);
}
int main()
{
    // cout << steps(4);

    int arr[] = {2, 3, 4, 5, 6};
    // printArr(arr,5,0);
    // cout << search(arr, 5, 0, 4);

    // int mini=INT_MAX;
    // minNum(arr,5,0,mini);
    // cout<<mini<<endl;

    int maxi=INT_MIN;
    maxNum(arr,5,0,&maxi);
    cout<<maxi<<endl;
    return 0;
}