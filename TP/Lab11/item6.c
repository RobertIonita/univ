#include <stdio.h>
#include <stdlib.h>

int read(char *path, float (*arr)[])
{
    FILE *f;
    int i = 0;
    if ((f = fopen(path, "rt")) == NULL)
    {
        printf("error");
    }
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%f", &(*arr)[i]);
            if ((*arr)[i] < 1000)
                (*arr)[i] += (*arr)[i] * 0.15;
            i++;
        }
        fclose(f);
    }
    return i;
}
void write(char *path, float (*arr)[], int n)
{
    FILE *f;
    if ((f = fopen(path, "wt")) == NULL)
    {
        printf("error");
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            fprintf(f, "%7.2f\n", (*arr)[i]);
        }
        fclose(f);
    }
}
int main()
{
    float arr[10];
    int records = 0,
        n = 0;
    records = read("TP/Lab11/assets/input6.txt", &arr);
    write("TP/Lab11/assets/output6.txt", &arr, records);
    return 0;
}