#include <stdio.h>

#include <conio.h>

#include <string.h>

typedef struct {
    char nume[50], facultate[50];
    int grupa;
}
student;
void citire(student * st, int * nr) {
    ( * nr) ++;
    printf("Dati numele studentului: ");
    fflush(stdin);
    gets((st + * nr) -> nume);
    printf("Dati facultatea: ");
    gets((st + * nr) -> facultate);
    printf("Dati grupa: ");
    scanf("%d", & ((st + * nr) -> grupa));
}
void afisare(student * st, int nr) {
    printf("\n%5s \t %5s \t %5d", (st + nr) -> nume, (st + nr) -> facultate,
        st[nr].grupa);
}
void cautare_facultate(student * st, int * nr, char fac[50]) {
    int i;
    for (i = 0; i <= ( * nr); i++)
        if (strcmp((st + i) -> facultate, fac) == 0)

    afisare(st, i);

}
void cautare_grupa(student * st, int * nr, int gr) {
    int i;
    for (i = 0; i <= ( * nr); i++)
        if ((st + i) -> grupa == gr) afisare(st, i);
}
void cautare_nume(student * st, int * nr, char nu[50]) {
    int i;
    for (i = 0; i <= ( * nr); i++)
        if (strcmp((st + i) -> nume, nu) == 0)
            afisare(st, i);

}
void stergere(student * st, int * nr, char nu[50]) {
    int k = 0, i, j;
    for (i = 0; i <= ( * nr - k); i++)
        if (strcmp((st + i) -> nume, nu) == 0) {
            k++;
            for (j = i; j <= ( * nr - k); j++) * (st + j) = st[j + 1];
            i--;
        }
        * nr = * nr - k;
}
void sortare(student * st, int * nr) {
    int i, k;
    student aux;
    do {
        k = 1;
        for (i = 0; i <= ( * nr - 1); i++)
            if (strcmp((st + i) -> nume, (st + i + 1) -> nume) > 0) {
                aux = * (st + i);
                *(st + i) = * (st + i + 1);*(st + i + 1) = aux;
                k = 0;
            }
    } while (!k);
}
int main() {
    student st[50];
    int opt, n = -1, i, j, gr;
    char nu[50], fac[50];
    do {
        printf("\n1. Adaugarea unui student\n");
        printf("2. Afisarea tuturor studentilor\n");
        printf("3. Afisarea tuturor studentilor de la o anumita facultate\n");
        printf("4. Afisarea tuturor studentilor dintr-o anumita grupa\n");
        printf("5. Cautarea unui student dupa nume\n");
        printf("6. Stergerea unui student dupa nume\n");
        printf("7. Sortarea studentilor dupa nume\n");
        printf("0. Exit \n");
        printf("Dati optiunea \n");
        scanf("%d", & opt);
        switch (opt) {
            case 1:
                citire( & st[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++)
                    afisare(st, i);
                break;
            case 3:
                printf("\nFacultate: ");

                scanf("%s", fac);
                cautare_facultate(st, & n, fac);
                break;
            case 4:
                printf("Dati grupa dorita: ");
                scanf("%d", & gr);
                cautare_grupa( & st[0], & n, gr);
                break;
            case 5:
                printf("Dati numele dorit: ");
                scanf("%s", nu);
                cautare_nume( & st[0], & n, nu);
                break;
            case 6:
                printf("Dati numele pe care doriti sa il stergeti: ");
                scanf("%s", nu);
                stergere( & st[0], & n, nu);
                break;
            case 7:
                sortare( & st[0], & n);
                for (i = 0; i <= n; i++)
                    afisare( & st[0], i);
                break;
            case 0:
                break;
        }
    } while (opt != 0);
    return 0;
}