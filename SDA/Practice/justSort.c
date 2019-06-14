#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

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

    for (size_t i = 0; i <= max; i++)
        if (token[i] > 0)
            (*arr)[k++] = i;
}

void generateArray(int (*arr)[])
{
    for (size_t i = 0; i < MAX; i++)
        (*arr)[i] = rand() % 1000000 + 1;
}

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (size_t i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main()
{
    int arr[MAX], n;
    generateArray(&arr);
    n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    justSort(getMax(arr, n), &arr, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[1000000] took 0.0324989s (avg of 10 tests)
    return 0;
}