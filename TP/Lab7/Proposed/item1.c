#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *nume;
    int varsta;
} persoana;

int n;
persoana *tab;

void citire(void)
{
    int i;
    char buf[80];
    printf("Introduceti numarul de persoane: ");
    scanf("%d", &n);
    if (!(tab = (persoana *)malloc(n * sizeof(persoana))))
    {
        printf("Eroare alocare dinamica de memorie \n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        printf("Introduceti numele persoanei: ");
        scanf("%s", buf);
        if (!(tab[i].nume = (char *)malloc(strlen(buf) + 1)))
        {
            printf("Eroare alocare dinamica de memorie\n");
            exit(1);
        }
        strcpy(tab[i].nume, buf);
        printf("Introduceti varsta persoanei: ");
        scanf("%d", &tab[i].varsta);
    }
}
void afisare(persoana *p, int nr)
{

    printf("%s \t %d\n",
           p[nr].nume,
           p[nr].varsta);
}

int main()
{
    int i;
    citire();
    for (i = 0; i < n; i++)
        afisare(tab, i);
    return 0;
}