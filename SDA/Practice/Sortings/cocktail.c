#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void CocktailSort(int a[], int n)
{
    int swapped = 1,
        start = 0,
        end = n - 1;

    while (swapped)
    {
        swapped = 0;
        for (int i = start; i < end; ++i)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1])
            {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
        ++start;
    }
}

void showOff(int a[], int n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8, 0, 2},
        n = sizeof(arr) / sizeof(arr[0]);
    CocktailSort(arr, n);
    printf("Sorted array :\n");
    showOff(arr, n);
    return 0;
}
