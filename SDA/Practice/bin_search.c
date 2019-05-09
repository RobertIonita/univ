#include <stdio.h>
#define MAX 9

int binPerformed(int x, int n, int (*arr)[n])
{
    int s = 0,           // search field start
        e = n - 1,       // search field end
        m; // search field middle
    do
    {
        m = (s + e) / 2;
        (*arr)[m] < x ? (s = m + 1) : (e = m);  // magic

    } while (s < e); // while search field is not empty
    return (*arr)[e] == x ? e : -1;     // if x was found return its index in the array, otherwise -1
}

int binSearch(int x, int n, int (*arr)[n])
{
    int s = 0,           // search field start
        e = n - 1,       // search field end
        m = (s + e) / 2; // search field middle
    do
    {
        m = (s + e) / 2;
        (*arr)[m] < x ? (s = m + 1) : (e = m - 1);  // magic

    } while ((*arr)[m] != x && s <= e); // search while x is not found or search field is not empty
    return (*arr)[m] == x ? m : -1;     // if x was found return its index in the array, otherwise -1
}

int main()
{
    int arr[MAX] = {0, 1, 2, 3, 4, 5, 6, 7, 8},
        x;
    do {
        printf("\nsearch: ");
        scanf("%d", &x);
        printf("\nindex: %d", binSearch(x, MAX, &arr));
        printf("\nindex: %d", binPerformed(x, MAX, &arr));
    } while (x != -1);
    
    return 0;
}