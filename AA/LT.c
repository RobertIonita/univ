#include <stdio.h>
#define MAX 10

void afisare(int noduri[MAX], int parinti[MAX], int n)
{
    int i;
    for (i = 0; i <= n; i++)
        printf("nod: %d, parinte: %d\n", noduri[i], parinti[i]);
}

void inserare(int (*noduri)[MAX], int (*parinti)[MAX], int *n)
{
    int k = 0, i;
    printf("Cate noduri doriti: ");
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        (*n)++;
        printf("Inserati nodul: ");
        scanf("%d", &(*noduri)[*n]);
        printf("Inserati parintele: ");
        scanf("%d", &(*parinti)[*n]);
    }
}

void cautare_parinte(int noduri[MAX], int parinti[MAX], int n)
{
    int x, i;
    printf("\nParintele carui nod doriti sa-l gasiti?: ");
    scanf("%d", &x);
    for (i = 0; i <= n; i++)
    {
        if (noduri[i] == x)
        {
            printf("%d\n", parinti[i]);
            break;
        }
    }
}

void cautare_frate(int noduri[MAX], int parinti[MAX], int n)
{
    int x, i;
    printf("Fratele carui nod cautati?: ");
    scanf("%d", &x);
    for (i = 0; i <= n; i++)
        if (noduri[i] == x)
        {
            if (parinti[i] == parinti[i + 1])
                printf("%d\n", noduri[i + 1]);
            else
                printf("Nu exista frate drept!");
            break;
        }
}

void stergere_nod(int (*noduri)[MAX], int (*parinti)[MAX], int *n)
{
    int x, i, k, p = -1;
    printf("Ce nod doriti sa stergeti?: ");
    scanf("%d", &x);
    for (i = 0; i <= *n && (*noduri)[i] != x; i++)
        ;
    p = (*parinti)[i];
    k = i;
    for (i = 0; i <= *n; i++)
        if ((*parinti)[i] == x)
            (*parinti)[i] = p;
    for (i = k; i < *n; i++)
    {
        (*noduri)[i] = (*noduri)[i + 1];
        (*parinti)[i] = (*parinti)[i + 1];
    }
    if (p == -1)
        for (i = 0; i < *n; i++)
            if ((*parinti)[i] == -1 && (*noduri)[i] != (*noduri)[k])
                (*parinti)[i] = (*noduri)[k];
    (*n)--;
}

int main()
{

    int opt,
        noduri[MAX],
        parinti[MAX],
        n = -1;

    do
    {
        printf("1.Inserare noduri si parinti\n");
        printf("2.Afisare\n");
        printf("3.Cautare parinte\n");
        printf("4.Cautare frate drept\n");
        printf("5.Stergere nod\n");
        printf("0.Exit\n");
        printf("Optiunea dvs:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            inserare(&noduri, &parinti, &n);
            break;
        case 2:
            afisare(noduri, parinti, n);
            break;
        case 3:
            cautare_parinte(noduri, parinti, n);
            break;
        case 4:
            cautare_frate(noduri, parinti, n);
            break;
        case 5:
            stergere_nod(&noduri, &parinti, &n);
            break;
        case 0:
            printf("exit");
            break;
        }

    } while (opt != 0);

    return 0;
}