#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low,
        j = high;

    while (i < j)
    {
        for (i = low; arr[i] <= pivot; i++);
        for (j = high; arr[j] > pivot; j--);
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);

    return j;
}

int partition2(int *arr, int low, int high) {
    int pivot = arr[low],
        i = low,
        j = high;
    while (i < j) {
        for (i = low; arr[i] <= pivot; i++);
        for (j = high; arr[j] > pivot; j--);
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);

    return j;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition2(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}


void showOff(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void test()
{
    int arr[] = {9, 3, 1, 5, 6, 4, 7, 0},
        n = sizeof(arr) / sizeof(arr[0]);
    printf("\nInitial: ");
    showOff(arr, n);
    quickSort(arr, 0, n - 1);
    printf("\nSorted: ");
    showOff(arr, n);
}
int main()
{
    test();
    return 0;
}