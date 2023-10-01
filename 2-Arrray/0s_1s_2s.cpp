#include <iostream>
#include <vector>
using namespace std;
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " |";
    }
    cout << endl;
}
void sort(int arr[], int size)
{
    int s = 0, e = size - 1;

    for (int middle=0 ; middle <= e; middle++ )
    {
        if (arr[middle] == 0)
        {
            swap(arr[middle], arr[s++]);
            while (arr[s] == 0)
            {
                s++;
            }
        }
        if (arr[middle] == 2)
        {
            swap(arr[middle], arr[e--]);
            while (arr[e] == 2)
            {
                e--;
            }
        }
    }
}

int main()
{
    int arr[] = {2,0,2,1,1,0};
    printArr(arr, 6);
    sort(arr, 6);
    printArr(arr, 6);

    return 0;
}