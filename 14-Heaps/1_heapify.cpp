#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    int *arr;
    int capacity;
    int currSize;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->currSize = 0;
    }
    void insert(int val)
    {
        if (currSize == capacity)
        {
            cout << "overflowError" << endl;
            return;
        }
        else
        {
            currSize++;
            int index = currSize;
            arr[index] = val;
            // moving the element towards correct location
            while (index > 1)
            {
                int parentIndex = index / 2; // this line gives wrong answers if outside while loop
                if (arr[index] > arr[parentIndex])
                {
                    swap(arr[index], arr[parentIndex]);
                    index = parentIndex;
                }
                else
                    break;
            }
        }
    }

    void deleteFromHeap()
    {
        int ans = arr[1];
        arr[1] = arr[currSize]; // replacing root node by the last element of the heap
        currSize--;
        int index = 1;
        while (index < currSize) // moving root to the correct location
        {
            int leftIndex = index * 2;
            int rightIndex = (index * 2) + 1;
            int largestKaIndex = index;

            // finding teeno mein largest kaun h?
            if (leftIndex <= currSize && arr[leftIndex] > arr[largestKaIndex])
            {
                largestKaIndex = leftIndex;
            }
            if (rightIndex <= currSize && arr[rightIndex] > arr[largestKaIndex])
            {
                largestKaIndex = rightIndex;
            }
            // if(largestKaIndex == index) break;
            if (largestKaIndex != index)
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
                deleteFromHeap();
            }
        }
    }
};
void heapify(int *arr, int size, int index)
{
    while (index < size)
    {
        int leftIndex = index * 2;
        int rightIndex = (index * 2) + 1;
        int largestKaIndex = index;

        // finding teeno mein largest kaun h?
        if (leftIndex <= size && arr[leftIndex] > arr[largestKaIndex])
        {
            largestKaIndex = leftIndex;
        }
        if (rightIndex <= size && arr[rightIndex] > arr[largestKaIndex])
        {
            largestKaIndex = rightIndex;
        }
        if (largestKaIndex == index)
            break;
        if (index != largestKaIndex)
        {
            swap(arr[index], arr[largestKaIndex]);
            index = largestKaIndex;
            heapify(arr, size, index);
        }
    }
}
int main()
{
    Heap *h1 = new Heap(5);

    h1->insert(1);
    h1->insert(2);
    h1->insert(3);
    h1->insert(4);
    h1->insert(5);
    for (int i = 1; i <= 5; i++)
    {
        cout << h1->arr[i] << " ";
    }
    cout << endl
         << "Deleting root from heap" << endl;
    h1->deleteFromHeap();
    h1->deleteFromHeap();
    for (int i = 1; i <= 5; i++)
    {
        cout << h1->arr[i] << " ";
    }
    // for (int i = 1; i <= 5; i++)
    // {
    //     cout << h1->arr[i] << " ";
    // }
    return 0;
}