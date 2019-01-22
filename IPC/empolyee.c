#include<stdio.h>

#include<string.h>

#include<stdlib.h>

#define MAX 10
typedef struct {
    char nume[MAX], prenume[MAX], studii[MAX];
    int varsta, experienta;
    float salariu;

}
angajati;
void citire(angajati * a, int * n) {
    ( * n) ++;
    printf("Nume:");

    getchar();
    gets((a + * n) -> nume);
    printf("Prenume:");
    fflush(stdin);
    gets((a + * n) -> prenume);
    printf("Varsta:");
    scanf("%d", & (a + * n) -> varsta);
    printf("Experienta:");
    scanf("%d", & (a + * n) -> experienta);
    if ((a + * n) -> experienta > 5) {
        printf("Salariu:");
        scanf("%f", & (a + * n) -> salariu);
    } else if ((a + * n) -> experienta <= 5) {
        printf("Studiile:");
        getchar();
        gets((a + * n) -> studii);
    }
}
void afisare(angajati * a, int n) {
    if ((a + n) -> experienta > 5) {
        printf( "%s %s %d %d %f\n", 
            (a + n) -> nume,
            (a + n) -> prenume,
            (a + n) -> varsta,
            (a + n) -> experienta,
            (a + n) -> salariu
        );
    }
    else if ((a + n) -> experienta <= 5) {
        printf( "%s %s %d %d %s\n",
            (a + n) -> nume,
            (a + n) -> prenume,
            (a + n) -> varsta,
            (a + n) -> experienta,
            (a + n) -> studii
        );
    }
        
}
int validare_varsta(int nr) {

    if (nr > 65)
        return 0;
    else
        return 1;
}
int validare_nume(char n[]) {
    int i;
    for (i = 0; i < strlen(n); i++) {
        if (n[i] >= 'A' && n[i] <= 'z') {
            return 1;
        }
        else {
            return 0;
        }
    }
}
void cautare_v(angajati * a, int * n, int v) {
    int i;
    for (i = 0; i <= * n; i++)
        if ((a + i) -> varsta == v)
            afisare(a, i);

}
void cautare_n(angajati * a, int * n, char nume[20]) {
    int i;
    for (i = 0; i <= * n; i++)
        if (strcmp((a + i) -> nume, nume) == 0)
            afisare(a, i);

}
void sortare(angajati * a, int * n) {
    int i, k;

    angajati aux;
    do {
        k = 1;
        for (i = 1; i <= * n; i++)
            if (strcmp((a + i - 1) -> nume, (a + i) -> nume) > 0) {
                aux = * (a + i - 1);
                *(a + i - 1) = * (a + i);
                *(a + i) = aux;
                k = 0;
            }
    } while (!k);
}
void stergere(angajati * a, int * n, char nume[20]) {
    int i, j, k = 0;
    for (i = 0; i <= * n - k; i++)

    {
        if (strcmp((a + i) -> nume, nume) == 0) {
            k++;
            for (j = i; j <= * n - k; j++)
                *
                (a + i) = * (a + i + 1);
            i--;
        }
    }
    * n = * n - k;
}
void vector_salariu(angajati * a, int * n)

{
    int i, k = 0;
    float vect[MAX];
    for (i = 0; i <= * n; i++)
        if ((a + i) -> salariu > 100)
            vect[k++] = (a + i) -> salariu;

    for (i = 0; i < k; i++)

        printf("%f \n", vect[i]);

}
int main() {
    angajati ang[MAX];
    int opt, n = -1, i, vrs, val1, val2;
    char num[30];
    do {

        printf("1.Citire\n");
        printf("2.Afisare\n");
        printf("3.Cautare dupa varsta\n");
        printf("4.Cautare dupa nume\n");
        printf("5.Sortare alfabetica dupa nume\n");
        printf("6.Stergere\n");
        printf("7.Vector salarii>100\n");
        printf("0.Iesire\n");
        printf("Optiunea dv este: ");
        scanf("%d", & opt);
        switch (opt) {
            case 1:
                citire( & ang[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++)

                    afisare(ang, i);
                break;
            case 3:
                printf("Dati varsta pe care doriti sa o cautati:");
                scanf("%d", & vrs);
                val1 = (validare_varsta(vrs));
                if (val1 == 1)
                    cautare_v(ang, & n, vrs);
                else
                    printf("Ati incercat sa cautati un pensionar!\n");
                break;
            case 4:
                printf("Dati numele pe care doriti sa il cautati:");
                scanf("%s", num);
                val2 = validare_nume(num);
                if (val2 == 1)
                    cautare_n(ang, & n, num);
                else
                    printf("Nu ati citit un nume valid!\n");
                break;
            case 5:
                sortare(ang, & n);
                for (i = 0; i <= n; i++)
                    afisare(ang, i);
                break;
            case 6:
                printf("Dati numele pe care doriti sa il cautati:");
                scanf("%s", num);
                stergere(ang, & n, num);
                for (i = 0; i <= n; i++)
                    afisare(ang, i);
                break;
            case 7:
                vector_salariu(ang, & n);
                break;
            case 0:
                exit(0);

                break;

            default:
                printf("Optiune gresita!\n");
                break;
        }
    } while (opt != 0);
    return 0;
}