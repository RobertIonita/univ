#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct {
    char nume[30];
    char prenume[30];
    char achizitie[30];
} student;

typedef student tab[30];

int citire(tab t) {
    FILE * f;
    int i = 0;
    if ((f = fopen("SDA/Lab1/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %s %s", t[i].nume, t[i].prenume, t[i].achizitie);
            i++;
        }
        fclose(f);
    }
    return i;
}

void salvare(tab t, int n, char a[3]) {
    FILE * f;
    int i;
    if ((f = fopen("SDA/Lab1/file2.txt", "wt")) == NULL) {
        printf("error");
    } else {
        for (i = 0; i < n; i++) {
            if (strcmp(t[i].achizitie, a) == 0) {
                fprintf(f, "%s %s %s\n", t[i].nume, t[i].prenume, t[i].achizitie);
            }
        }
        fclose(f);
    }
}

void afisare(tab t, int n) {
    printf("\n%s %s %s",
        t[n].nume,
        t[n].prenume,
        t[n].achizitie
    );
}

int main(void) {
    student main_tab[30];

    int nr, i,
    opt;
    char purchaise[30];

    do {
        printf("\n0. exit");
        printf("\n1. read");
        printf("\n2. save");
        printf("\n3. show");
        printf("\nUr choice: ");
        scanf("%d", & opt);

        switch (opt) {
            case 0:
                printf("\nquiting..");
                break;
            case 1:
                nr = citire(main_tab);
                break;
            case 2:
                printf("\ninsert purchaise: ");
                scanf("%s", purchaise);
                salvare(main_tab, nr, purchaise);
                break;
            case 3:
                for (i = 0; i < nr; i++) {
                    afisare(main_tab, i);
                }
                break;
            default:
                printf("\ninvalid option");
                break;
        }

    } while (opt != 0);
}