#include <stdio.h>

#define MAX 9

void showOff(int a[MAX], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void shellSort2(int (*a)[MAX], int n)
{
    for (size_t gap = n / 2; gap > 0; gap /= 2)
    {
        for (size_t i = gap; i < n; i++)
        {
            int temp = (*a)[i],
                j;
            for (j = i; j >= gap && (*a)[j - gap] > temp; j -= gap)
            {
                (*a)[j] = (*a)[j - gap];
            }
            (*a)[j] = temp;
            printf("\n"); showOff(*a, n); //optional, show steps
        }
    }
}
int main()
{
    int arr[MAX] = {3, 2, 8, 5, 7, 6, 10, 9, 1},
        n = sizeof(int) / sizeof(arr[0]);

    printf("\nInitial: ");
    showOff(arr, MAX);
    shellSort2(&arr, MAX);
    printf("\nSorted: ");
    showOff(arr, MAX);
    return 0;
}