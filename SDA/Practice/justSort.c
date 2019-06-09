#include <stdio.h>
#include <time.h>
#define MAX 10000000
void showOff(int arr[], int size)
{
    int i;
    printf("\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void cleanUp(int (*arr)[], int n)
{
    for (size_t i = 0; i < n; i++)
        (*arr)[i] = 0;
}

void justSort(int max, int (*arr)[], int n)
{
    int token[max],
        k = 0;
    cleanUp(&token, max);
    for (size_t i = 0; i < n; i++)
        token[(*arr)[i]]++;

    for (size_t i = 0; i < max; i++)
        if (token[i] > 0)
            (*arr)[k++] = i;
}

int main()
{
    int arr[] = {9, 3, 1, 5, 6, 4, 7, 0},
        n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    showOff(arr, n);

    clock_t start = clock();
    for (size_t i = 0; i < MAX; i++)
        justSort(max, &arr, n - 1);

    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    showOff(arr, n);
    printf("\ntook: %f", time);
    return 0;
}