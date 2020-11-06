// Heap using Array DS
#include <stdio.h>
#include <iostream>
using namespace std;

void maxheapify(int arr[], int i, int size)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int swapper;
    int lowestIndex = i;
    if (l < size && arr[i] < arr[l])
    {
        swapper = arr[i];
        arr[i] = arr[l];
        arr[l] = swapper;
        lowestIndex = l;
    }
    if (r < size && arr[i] < arr[r])
    {
        swapper = arr[i];
        arr[i] = arr[r];
        arr[r] = swapper;
        lowestIndex = r;
    }

    if (lowestIndex != i)
        maxheapify(arr, lowestIndex, size);
}

void buildMaxHeap(int arr[], int size)
{
    for (int i = size / 2; i >= 1; i--)
        maxheapify(arr, i, size);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
}
int main()
{
    int arr[] = {12, 1, 11, 3, 5, 6, 7};

    buildMaxHeap(arr, 7);
    printArray(arr, 7);
    return 0;
}