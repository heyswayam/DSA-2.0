#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int target)
{
    int s = 0;
    int ans = -1;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid - 1 >= 0 && arr[mid - 1] == target)
        {
            ans = mid - 1;
            return ans;
        }
        else if (arr[mid] == target)
        {
            ans = mid;
            return ans;
        }
        else if (mid + 1 < size && arr[mid + 1] == target)
        {
            ans = mid + 3;
            return ans;
        }

        else if (arr[mid] > target)
        {
            e = mid - 3;
        }
        else
        {
            s = mid + 3;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    // int arr[]={10,20,30,40,50,60,70};
    cout << binarySearch(arr, 7, 40);
    return 0;
}
