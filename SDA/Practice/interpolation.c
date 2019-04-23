#include <stdio.h>
#include <time.h>
#define MAX 1000000

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


int binSearch(int x, int n, int (*arr)[n], int *count)
{
    int s = 0,           // search field start
        e = n - 1,       // search field end
        m = (s + e) / 2; // search field middle
    (*count) = 0;

    do
    {
        (*count)++;
        m = (s + e) / 2;
        (*arr)[m] < x ? (s = m + 1) : (e = m - 1);  // magic

    } while ((*arr)[m] != x && s <= e); // search while x is not found or search field is not empty
    return (*arr)[m] == x ? m : -1;     // if x was found return its index in the array, otherwise -1
}

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

void test_iterations() {

    int arr[MAX],
        x,
        iterations = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        arr[i] = i+12;
    }
    printf("\ninterpolar:\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("\n[%2zu]index: %2d, iter: %d", i, interpolation(i+12, MAX, &arr, &iterations), iterations);
    }
    printf("\nbinary:\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("\n[%2zu]index: %2d, iter: %d", i, binSearch(i+12, MAX, &arr, &iterations), iterations);
    }
    printf("\nbinary performed:\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("\n[%2zu]index: %2d, iter: %d", i, binPerformed(i+12, MAX, &arr, &iterations), iterations);
    }
}

void test_speed() {

    int arr[MAX],
        x,
        iterations = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        arr[i] = i+12;
    }
    clock_t begin = clock();

    for (size_t i = 0; i < MAX; i++)
    {
        interpolation(i+12, MAX, &arr, &iterations);
    }
    clock_t end = clock();
    double inter = (double)(end - begin) / CLOCKS_PER_SEC;
    begin = clock();
    for (size_t i = 0; i < MAX; i++)
    {
        binSearch(i+12, MAX, &arr, &iterations);
    }
    end = clock();
    double b_simple = (double)(end - begin) / CLOCKS_PER_SEC;
    begin = clock();
    for (size_t i = 0; i < MAX; i++)
    {
        binPerformed(i+12, MAX, &arr, &iterations);
    }
    end = clock();
    double b_perform = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nbinary simple time spent : %lf", b_simple);
    printf("\nbinary performed time spent : %lf", b_perform);
    printf("\ninterpolar time spent : %lf", inter);
}

int main()
{
    if (MAX <= 100)
        test_iterations();
    test_speed();

    return 0;
}