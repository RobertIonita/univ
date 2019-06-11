#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int prim(int n)
{
    int j, k = 0;

    for (j = 2; j < n / 2 + 1; j++)
    {
        if (n % j == 0)
            k++;
    }
    if (k == 0)
        return 1;
    return 0;
}

void citire(int (*vect)[], int n)
{
    int a, b, i, k;
    printf("\nInserati 2 numere ");
    scanf("%d", &a);
    scanf("%d", &b);

    FILE *f, *g;
    f = fopen("TP/Teo_cries/EXAMEN/assets/intrare.dat", "rb");
    g = fopen("TP/Teo_cries/EXAMEN/assets/iesire.dat", "wb");

    if (!f || !g)
    {
        printf("\neroare");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < n; i++)
    {
        fread(&k, sizeof(int), 1, f);
        if (k >= a && k <= b)
            fwrite(&k, sizeof(int), 1, g);
    }
    fclose(f);
    fclose(g);

}

void adaugare(int (*vect)[], int n)
{
    int i, nr, j, k = 0;
    FILE *f;
    f = fopen("TP/Teo_cries/EXAMEN/assets/intrare.dat", "wb");
    if (!f)
    {
        printf("\neroare");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++)
    {
        nr = (*vect)[i];
        fwrite(&nr, sizeof(int), 1, f);
        while (!prim(++nr))
            ;
        fwrite(&nr, sizeof(int), 1, f);
    }
    fclose(f);
}
int main()
{
    int vect[MAX], i = 0, n;
    do
    {
        scanf("%d", &vect[i]);

    } while (vect[i++] != 0);
    n = i - 1;
    for (i = 0; i < n; i++)
    {
        printf("\n%d", vect[i]);
    }
    adaugare(&vect, n);
    citire(&vect, n * 2);

    return 0;
}