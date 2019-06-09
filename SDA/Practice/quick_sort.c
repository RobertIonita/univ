#include <stdio.h>
#include <time.h>
#define MAX 10000000

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
        for (i = low; arr[i] <= pivot; i++)
            ;
        for (j = high; arr[j] > pivot; j--)
            ;
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
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void showOff(int arr[], int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void test()
{
    int arr[] = {9, 3, 1, 5, 6, 4, 7, 0},
        n = sizeof(arr) / sizeof(arr[0]);

    showOff(arr, n);

    clock_t start = clock();
    for (size_t i = 0; i < MAX; i++)
        quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    showOff(arr, n);
    printf("\ntook: %f", time);
}
int main()
{
    test();
    return 0;
}