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
    for (int i = (size / 2) - 1; i >= 0; i--)
        maxheapify(arr, i, size);
}

void heapSort(int arr[], int size)
{
    int swapper;
    buildMaxHeap(arr, size);

    for (int i = size - 1; i >= 0; i--)
    {
        swapper = arr[0];
        arr[0] = arr[i];
        arr[i] = swapper;
        maxheapify(arr, 0, i);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 18, 19};

    heapSort(arr, 8);
    printArray(arr, 8);
    return 0;
}