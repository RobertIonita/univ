#include <stdio.h>

void swap(int *a, int *b)
{
    int token = *a;
    *a = *b;
    *b = token;
}

void printIntArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void printFloatArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

void printCharArray(char arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
}

void insertion(int arr[], int n)
{
    int i, j,
        clone;
    for (i = 1; i < n; i++)
        for (j = i; j > 0 && arr[j] < arr[j - 1]; j--)
        {
            clone = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = clone;
        }
}

int binSearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binSearch(a, item, mid + 1, high);
    return binSearch(a, item, low, mid - 1);
}

void binInsertion(int a[], int n)
{
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];

        loc = binSearch(a, selected, 0, j);
        while (j >= loc)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void bubble(int a[], int n)
{
}