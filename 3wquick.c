#include <stdio.h>
#define MAX 20

int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int low, int high)
{
    int i = low, ci = 0,
        j = high, cj = 0,
        pivot = (low + high) / 2,
        val = arr[pivot];
    while (i < j)
    {
        while (arr[i] <= val  && i <= high)
        {
            if (arr[i] == val)
                if (i != ci++)
                    swap(&arr[ci-1], &arr[i]);
            if(++i > high) break;
        }
        while (arr[j] >= val && j >= low)
        {
            if (arr[j] == val)
                if (high - j != cj++)
                    swap(&arr[high - cj+1], &arr[j]);
            if(--j < low) break;
        }
        if(i < j) swap(&arr[i], &arr[j]);
    }
    for (int k = 0; k < ci; k++)
        swap(&arr[k], &arr[i-k-1]);
    for (int k = 0; k < cj; k++)
        swap(&arr[high-k], &arr[j+k+1]);
    
    quickSort(low, j-ci);
    // quickSort(i+cj, high);

    printf("\ni: %d, j: %d, ci: %d, cj: %d", i, j, ci, cj);

}

void showOff(int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n;
    n = sizeof(arr) / sizeof(arr[0]);
    quickSort(0, n - 1);

    showOff(n); //do not uncomment if MAX is greather than 100

    return 0;
}