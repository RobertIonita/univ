#include <stdio.h>
#define MAX 20

int arr[] = {3, 9, 5, 1, 3},
    n = sizeof(arr) / sizeof(arr[0]);

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void showOff(int n);
void quickSort(int low, int high)
{
    int i = low, ci = 0,
        j = high, cj = 0,
        pivot = (low + high) / 2,
        val = arr[pivot];
    while (i < j)
    {
        while (arr[i] <= val && i <= high-cj)
        {
            if (arr[i] == val)
                if (i-low != ci++)
                    swap(&arr[low+ci - 1], &arr[i]);
            if (i + 1 <= high)
                i++;
            else
                break;
        }
        while (arr[j] >= val && j >= low+ci)
        {
            if (arr[j] == val)
                if (high - j != cj++)
                    swap(&arr[high - cj + 1], &arr[j]);
            if (j - 1 >= low)
                j--;
            else
                break;
        }
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    showOff(n);
    for (int k = 0; k < ci; k++)
        swap(&arr[low+k], &arr[i - k]);
    for (int k = 0; k < cj; k++)
        swap(&arr[high - k], &arr[j + k]);

    if (low < j - ci)
        quickSort(low, j - ci);
    if (i + cj < high)
        quickSort(i + cj, high);
}

void showOff(int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    quickSort(0, n - 1);

    // showOff(n); //do not uncomment if MAX is greather than 100

    return 0;
}