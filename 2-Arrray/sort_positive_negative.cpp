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
    
    while (arr[s] < 0)
    {
        s++;
    }
    while (arr[e] >= 0)
    {
        e--;
    }
    while (s < e)
    {
        swap(arr[s++], arr[e--]);
        while (arr[s] < 0)
        {
            s++;
        }
        while (arr[e] >= 0)
        {
            e--;
        }
    }
}

int main()
{
    int arr[] = {23, -7, 12, -10, -1, -40, 60};
    sort(arr, 7);
    printArr(arr,7);
    return 0;
}