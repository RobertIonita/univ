#include <stdio.h>
#include <math.h>

void insertionSort(int arr[], int n)
{
    int i, j,
        clone;
    for (i = 1; i < n; i++)
    {
        clone = arr[i];
        for (j = i; j > 0 && clone < arr[j - 1]; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = clone;
    }
}

void showOff(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {3, 0, 2, 1, 5, 6},
        n = sizeof(arr) / sizeof(arr[0]);

    printf("\nInitial array: ");
    showOff(arr, n);
    insertionSort(arr, n);

    printf("\nSorted array: ");
    showOff(arr, n);

    return 0;
}