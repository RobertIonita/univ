#include <stdio.h>
#include <stdio.h>

int interpolation(int x, int n, int (*arr)[n], int * count)
{
    int s = 0,
        e = n - 1,
        m;
    (*count) = 0;
    while ((*arr)[e] >= x && (*arr)[s] < x)
    {
        (*count)++;
        m = (e - s) / ((*arr)[e] - (*arr)[s]) * (x - (*arr)[s]) + s;

        if (x < (*arr)[m])
            e = m - 1;
        else if (x > (*arr)[m])
            s = m + 1;
        else
        {
            s = m;
        }
    }

    return (x == (*arr)[s]) ? s : -1;
}


int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8},
        n = sizeof(arr)/sizeof(int),
        iterations = 0;
    printf("\nindex: %2d, iter: %d", interpolation(6, n, &arr, &iterations), iterations);

    return 0;
}