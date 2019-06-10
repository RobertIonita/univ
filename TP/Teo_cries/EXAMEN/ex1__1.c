#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void read(float **less, float **more, int *k, int *q, char *path)
{
    *less = (float *)malloc(sizeof(float));
    *more = (float *)malloc(sizeof(float));
    float n;
    FILE *f;
    f = fopen(path, "rt");
    if (f == NULL)
        exit(EXIT_FAILURE);
    while (!feof(f))
    {
        fscanf(f, "%f", &n);
        if (n < 10) {
            (*less)[(*k)++] = n;
            *less = realloc(*less, sizeof(float *) * (*k));
        }
        else {
            (*more)[(*q)++] = n;
            *less = realloc(*less, sizeof(float *) * (*q));
        }
    }
    fclose(f);
}

void show(int k, int q, float (**less), float (**more))
{
    for (size_t i = 0; i < k; i++)
        printf("\n%5.2f", (*less)[i]);
    for (size_t i = 0; i < q; i++)
        printf("\n%5.2f", (*more)[i]);
}

int main(int argc, char *argv[])
{
    float *less, *more;
    int k = 0, q = 0;
    read(&less, &more, &k, &q, argv[1]);
    show(k, q, &less, &more);
    return 0;
}