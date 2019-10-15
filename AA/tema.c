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

void gasire_parinte(int noduri[MAX], int parinti[MAX], int n)
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

void gasire_frate(int noduri[MAX], int parinti[MAX], int n)
{
    int x, i;
    printf("\nFratele carui nod doriti sa-l gasiti?: ");
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

void stergere(int (*noduri)[MAX], int (*parinti)[MAX], int *n)
{
    int x, i, k, p = -1;
    printf("Ce nod doriti sa stergeti?: ");
    scanf("%d", &x);
    for (i = 0; i <= *n; i++)
    {
        if ((*noduri)[i] == x)
        {
            p = (*parinti)[i];
            k = i;
            break;
        }
    }
    for (i = 0; i <= *n; i++)
    {
        if ((*parinti)[i] == x)
            (*parinti)[i] = p;
    }
    for (i = k; i < *n; i++)
    {
        (*noduri)[i] = (*noduri)[i + 1];
        (*parinti)[i] = (*parinti)[i + 1];
    }
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
        printf("1.Inserare\n");
        printf("2.Afisare\n");
        printf("3.Gasire parinte\n");
        printf("4.Gasire frate drept\n");
        printf("5.Stergere nod\n");
        printf("0.Iesire\n");
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
            gasire_parinte(noduri, parinti, n);
            break;
        case 4:
            gasire_frate(noduri, parinti, n);
            break;
        case 5:
            stergere(&noduri, &parinti, &n);
            break;
        case 0:
            printf("executie terminata");
            break;
        }

    } while (opt != 0);

    return 0;
}