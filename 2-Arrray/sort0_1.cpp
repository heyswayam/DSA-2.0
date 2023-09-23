#include <iostream>
#include <vector>
using namespace std;
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " |";
    }
}

void sort(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    
    while (!arr[s])
    {
        s++;
    }
    while (arr[e])
    {
        e--;
    }
    while (s < e)
    {
        swap(arr[s++], arr[e--]);
        while (!arr[s])
        {
            s++;
        }
        while (arr[e])
        {
            e--;
        }
    }
}

int main()
{
    int arr[] = {1,1,1,1,0,0,0};
    sort(arr, 7);
    printArr(arr,7);
    return 0;
}