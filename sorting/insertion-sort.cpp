#include <stdio.h>
#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j, swapper;
        j = i - 1;

        while (j >= 0 && arr[j] > arr[j + 1])
        {
            swapper = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = swapper;
            j--;
        }
    }
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int array[10] = {12, 11, 32, 55, 12, 12, 11, 32, 55, 12};
    insertionSort(array, 10);
    printArray(array, 10);
    return 0;
}