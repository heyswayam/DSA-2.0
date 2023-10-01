#include <iostream>
#include <vector>
using namespace std;
int peakIndex(int arr[], int size)
{
    int s = 0, e = size - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m + 1] < arr[m])
            return m;

        else if (arr[m - 1] > arr[m])
            return m - 1;

        else if (arr[m] >= arr[0])
            s = m + 1;
        
        else if (s==e) return m;
        
        else
            e = m - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {11,12,13,3,4,5,6,7};
    int size = 8;
    cout << "Peakindex at: " << peakIndex(arr, size);
    return 0;
}