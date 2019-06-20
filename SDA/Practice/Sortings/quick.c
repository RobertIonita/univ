#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1,
        j;

   for (int j = low; j <= high - 1; j++)  
        if (arr[j] <= pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
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
        quickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time = (double)(end - start) / CLOCKS_PER_SEC;
    // showOff(arr, n); //do not uncomment if MAX is greather than 100
    printf("\ntook: %f", time); //arr[1000000] took 0.32s (avg from 10 tests)

    return 0;
}