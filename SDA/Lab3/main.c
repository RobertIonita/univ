#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include<curses.h>

typedef enum {
    medii,
    superioare,
    doctorat
}
studii;

typedef enum {
    econominc,
    tehnic
}
profil;

typedef struct {
    float media_bac,
        media_liceu;
}
media;

typedef union a {
    media inf;
    float media_licenta;
    float media_doc;
}
general;



typedef struct pers {
    char nume[20];
    char prenume[20];
    int zi,
        luna,
        an;
    float salariu;
    general nota;
    studii tip;
}
pers;

pers tab[20];

int citire(pers tab[]) {
    FILE * f;
    int i = 0;
    if ((f = fopen("SDA/Lab3/file.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s %s %d %d %d %f %d",
                tab[i].nume,
                tab[i].prenume,
                &tab[i].zi,
                &tab[i].luna,
                &tab[i].an,
                &tab[i].salariu,
                &tab[i].tip);

            switch (tab[i].tip) {
                case 0:
                    fscanf(f, "%f %f", 
                        &tab[i].nota.inf.media_bac,
                        &tab[i].nota.inf.media_liceu
                    );
                    break;
                case 1:
                    fscanf(f, "%f",
                        &tab[i].nota.media_licenta
                    );
                    break;
                case 2:
                    fscanf(f, "%f", 
                        &tab[i].nota.media_doc
                    );
                    break;
                default:
                    break;
            }
            i++;
        }
        fclose(f);
    }
    return i;
}

void afisare(pers *tab, int u) {
    int i = 0;
    while (i < u) {
        printf("\n%s %s %d %d %d %d %f %f",
            tab[i].nume,
            tab[i].prenume,
            tab[i].zi,
            tab[i].luna,
            tab[i].an,
            tab[i].salariu,
            tab[i].tip);
        i++;
    }
}
int main() {
    int k;
    k = citire(tab);
    afisare(tab, k);

}