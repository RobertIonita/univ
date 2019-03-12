#include <stdio.h>

void swap(int *xp, int *yp) {
    int clone = *xp;
    *xp = *yp;
    *yp = clone;
}

void shakerSort(int a[], int n) {
    int swapped = 1,
        start = 0,
        end = n - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped) break;
        swapped = 0;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(&a[i], &a[i + 1]);
                swapped = 1;
            }
        }
        ++start;
    }
}

void showOff(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {3 ,0 ,2 ,1 ,5 ,6},
        n = sizeof(arr) / sizeof(arr[0]);

    printf("\nInitial array: ");
    showOff(arr, n);
    shakerSort(arr, n);

    printf("\nSorted array: ");
    showOff(arr, n);
    return 0;
}