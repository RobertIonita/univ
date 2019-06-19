#include <stdio.h>

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
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8},
        n = sizeof(arr)/sizeof(int);
        printf("\nindex: %d", binSearch(6, n, &arr));
    
    return 0;
}