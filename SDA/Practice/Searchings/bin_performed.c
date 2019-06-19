#include <stdio.h>


int binPerformed(int x, int n, int (*arr)[n], int *count)
{
    int s = 0,           // search field start
        e = n - 1,       // search field end
        m; // search field middle
    (*count) = 0;
    do
    {   
        (*count)++;
        m = (s + e) / 2;
        (*arr)[m] < x ? (s = m + 1) : (e = m);  // magic

    } while (s < e); // while search field is not empty
    return (*arr)[e] == x ? e : -1;     // if x was found return its index in the array, otherwise -1
}

int main () {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8},
        n = sizeof(arr)/sizeof(int),
        iterations = 0;
    printf("\nindex: %2d, iter: %d", binPerformed(6, n, &arr, &iterations), iterations);
    return 0;
}