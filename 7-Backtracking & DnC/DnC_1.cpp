#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int e)
{
    cout<<"inside"<<endl;
    int mid = (s + e) / 2;
    
    int leftLen = mid - s + 1;
    int rightLen = e - (mid + 1) + 1;
    
    int leftArr[leftLen];
    int rightArr[rightLen];
    
    // int size = e - s + 1;

    int k = s;
    for (int i = 0; i < leftLen; i++)
    {
        leftArr[i] = arr[k++];
    }

    k=mid+1;
    for (int i = 0; i < rightLen; i++)
    {
        rightArr[i] = arr[k++];
    }

    int leftIndex = 0;
    int rightIndex =0;
    int mainArrIndex = s;

    while (leftIndex < leftLen && rightIndex < rightLen)
    {
        if (leftArr[leftIndex] < rightArr[rightIndex])
        {
            arr[mainArrIndex] = leftArr[leftIndex];
            leftIndex++;
            mainArrIndex++;
        }
        else
        {
            arr[mainArrIndex] = rightArr[rightIndex];
            rightIndex++;
            mainArrIndex++;
        }
    }

    while (rightIndex < rightLen)
    {
        arr[mainArrIndex] = rightArr[rightIndex];
        rightIndex++;
        mainArrIndex++;
    }

    while (leftIndex < leftLen)
    {
            arr[mainArrIndex] = leftArr[leftIndex];
            leftIndex++;
            mainArrIndex++;
    }
}
void mergeSort(int arr[], int s, int e)
{
    // base case
    if (s == e)
        return; // single element
    if (s > e)
        return; // invalid array

    int mid = (s + e) / 2;

    mergeSort(arr, s, mid);

    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {7, 6, 1, 2, 8, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // vector<int> arr{7, 6, 1, 2, 8, 4, 5};
    // vector<int> leftArr, rightIndex;

    int s = 0;
    int e = size - 1;

    mergeSort(arr, s, e);

    for (auto &&i : arr)
    {
        cout<<i<<" ";
    }
    
    
    return 0;
}