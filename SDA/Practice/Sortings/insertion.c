#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 100000
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

void generateArray(int (*arr)[])
{
    for (size_t i = 0; i < MAX; i++)
        (*arr)[i] = rand() % 1000000 + 1;
}

int main()
{
   int arr[MAX], n;
    generateArray(&arr);
    n = sizeof(arr) / sizeof(arr[0]);

    clock_t start = clock();
    for (size_t i = 0; i < 10; i++)
        insertionSort(arr, n);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[10000] took 1.1311852s (avg from 10 tests)

    return 0;
}