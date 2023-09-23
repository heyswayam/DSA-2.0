#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> arr)
{
     int size= arr.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (s == e)
        {
            return mid;
        }
        else if (arr[mid] > arr[mid + 1] && mid + 1 < size)
        {
            return mid;
        }
        else if (arr[mid] < arr[mid - 1] && mid - 1 >= 0)
        {
            return mid;
        }
        else if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int binarySearch(vector<int> arr,int target){
     int size= arr.size();
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s<=e)
    {
        if (arr[mid]==target)
        {
            return mid;
        }
        
        else if (arr[mid]>target)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid = s + (e - s) / 2;
        
    }
}

int searchRotated(vector<int> arr,int target){
int a;
}
void printArr(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " | ";
    }
}
int main()
{
    cout << "Hello World" << endl;
    vector<int> arr;

    arr.push_back(11);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);

    cout<<3/2;
    return 0;
}