#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *ar1 = (int *)malloc(n1 * sizeof(int));
    int *ar2 = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        ar1[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        ar2[j] = arr[m + j + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (ar1[i] <= ar2[j])
        {
            arr[k] = ar1[i];
            i++;
        }
        else
        {
            arr[k] = ar2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = ar1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = ar2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};

    mergeSort(arr, 0, 5);
    printArray(arr, 6);
    return 0;
}