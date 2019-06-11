#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void write(char *path, float (*arr)[], int n)
{
    FILE *f;
    float nr[n];
    f = fopen(path, "wb");
    if (!f)
    {
        printf("\nerror");
        exit(EXIT_FAILURE);
    }
    fwrite(*arr, sizeof(float), n, f);
    
    fclose(f);
}
void read(char *path, float (*arr)[], int n)
{
    FILE *f;
    f = fopen(path, "rb");
    for (size_t i = 0; i < n; i++)
    {
        fread(*arr, sizeof(float), n, f);
        printf("%.2f ", (*arr)[i]);
    }
    fclose(f);
}

double f(float x) { return pow(x, 3) * (1 + x); }
double g(float x) { return x - pow(x, 2); }
float h(float x) { return (x + 1) / (x - 1); }
double t(float x) { return x * x / 2; }

void show(float (*arr)[], int n) {
    double (*pf) (float x); pf = &f;
    double (*pg) (float x); pg = &g;
    float  (*ph) (float x); ph = &h;
    double (*pt) (float x); pt = &t;
    printf("\n pointeri la functie:");
    for (size_t i = 0; i < n; i++)
    {
        printf("\nx = %5.2f, f(x)=%10.2f, g(x)=%10.2f, h(x)=%10.2f, ft(x)=%10.2f",
        (*arr)[i],
        (*pf)((*arr)[i]),
        (*pg)((*arr)[i]),
        (*ph)((*arr)[i]),
        (*pt)((*arr)[i]));
    }
}

int main()
{
    float arr[] = {1, 2.1, 10, 7};
    int n = sizeof(arr) / sizeof(float);
    write("TP/Teo_cries/EXAMEN/assets/ex1_2.dat", &arr, n);
    read("TP/Teo_cries/EXAMEN/assets/ex1_2.dat", &arr, n);
    show(&arr, n);
    return 0;
}