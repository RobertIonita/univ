#include <stdio.h>
#include <stdlib.h>

int init(int *N, int count)
{
    N = (int *)malloc(count * sizeof(int));
    if (!N)
    {
        printf("\nUnable to alloc\n");
        exit(EXIT_FAILURE);
    }
    return *N;
}

void read(int *arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        printf("\nArr[%zu]: ", i);
        scanf("%d", &arr[i]);
    }
}
void showOff(int *arr, int count, int mode)
{
    int i;
    if (mode)
    {
        for (i = 0; i < count; i++)
            printf("\nN[%d]: %d", i, arr[i]);
    }
    else
    {
        for (i = count - 1; i >=0; i--)
            printf("\nN[%d]: %d", i, arr[i]);
    }
}
int main()
{
    int N, n;
    printf("Nr of records: ");
    scanf("%d", &n);
    N = init(&N, n);
    read(&N, n);
    showOff(&N, n, 1);
    showOff(&N, n, 0);
    return 0;
}