#include <stdio.h>

#include <string.h>

typedef struct {
    char nume[20];
    int nr_matricol;
}
student;

void citire(student * st, int * nr) {

    ( * nr) ++;

    printf("Dati numele studentului: ");
    fflush(stdin);
    gets((st + * nr) -> nume);
    printf("Dati numarul matricol: ");
    scanf("%d", & st[ * nr].nr_matricol);

}

void afisare(student * st, int nr) {

    printf("%s \t %d\n",
        (st + nr) -> nume,
        st[nr].nr_matricol
    );
}

void sortare_nume(student * st, int * nr) {


    int i, ok;
    student aux;
    do {
        ok = 1;
        for (i = 0; i <= ( * nr - 1); i++)
            if (strcmp((st + i) -> nume, (st + i + 1) -> nume) > 0) {
                aux = * (st + i);
                *(st + i) = * (st + i + 1);
                *(st + i + 1) = aux;
                ok = 0;
            }
    } while (!ok);
}

void sortare_nr_matricol(student * st, int nr) {

    int i, ok;
    student aux;

    do {
        ok = 1;
        for (i = 0; i < nr; i++) {
            if (st[i].nr_matricol > st[i + 1].nr_matricol) {
                aux = st[i];
                st[i] = st[i + 1];
                st[i + 1] = aux;
                ok = 0;
            }
        }
    } while (!ok);
}

void cautare_nume(student * st, int * nr, char nu[20]) {

    int i;

    for (i = 0; i <= (*nr); i++) {
        if (strcmp(st[i].nume, nu) == 0)
            printf("Pozitia la care se afla in lista este: %d", i);

    }

}

void cautare_nr_matricol(student * st, int * nr, int nm) {

    int i;

    for (i = 0; i <= (*nr); i++) {
        if (st[i].nr_matricol == nm)
            printf("Pozitia la care se afla in lista este: %d", i);

    }
}



int main(void) {

    int n = -1, i, op, nm;
    char _nume[30];
    student stud[30];

    do {
        printf("\n0. Exit");
        printf("\n1. Adaugare");
        printf("\n2. Afisare");
        printf("\n3. Sortare alfabetica dupa nume");
        printf("\n4. Sortare alfabetica dupa numar matricol");
        printf("\n5. Cautare student dupa nume");
        printf("\n6. Cautare student dupa nr matricol");
        printf("\nOptiunea aleasa este: ");
        scanf("%d", & op);
        switch (op) {
            case 0:
                return 0;
            case 1:
                citire( & stud[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++)
                    afisare(stud, i);
                break;
            case 3:
                sortare_nume( & stud[0], & n);
                for (i = 0; i <= n; i++)
                    afisare( & stud[0], i);
                break;
            case 4:
                sortare_nr_matricol(stud, n);
                for (i = 0; i <= n; i++)
                    afisare(stud, i);
                break;
            case 5:
                sortare_nume( & stud[0], & n);
                getchar();
                printf("Ce nume cautati?\n");
                gets(_nume);
                cautare_nume(stud, &n, _nume);
                break;
            case 6:
                sortare_nr_matricol(stud, n);
                printf("Ce numar matricol cautati?\n");
                scanf("%d", & nm);
                cautare_nr_matricol(stud, &n, nm);
                break;
            default:
                printf("\n Optiune gresita\n");
                break;

        }

    } while (op != 0);

}