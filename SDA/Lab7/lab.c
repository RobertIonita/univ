#include <stdio.h>

#include <string.h>

#include <memory.h>

#include <curses.h>

#include <stdlib.h>

typedef struct capitol {
    char * titlu_capitol;
    int nr_pagini;
    struct capitol * urm1;
}
cap;

typedef struct carte {
    char * titlu;
    struct capitol * sl1;
    struct carte *urm2;
}
car;


typedef struct autor {
    char * nume;
    struct carte * sl2;
    struct autor *urm3;
}
aut;

aut *prim=NULL;

cap * cauta1(cap * lista, char * tcap) {
    cap * q;
    for (q = lista; q != NULL && strcmp(q -> titlu_capitol, tcap) < 0; q = q -> urm1);
    if (q != NULL && strcmp(q -> titlu_capitol, tcap) == 0)

        return q;
    return NULL;
}


car * cauta2(car * lista, char * tc) {
    car * q;
    for (q = lista; q != NULL && strcmp(q -> titlu, tc) < 0; q = q -> urm2);
    if (q != NULL && strcmp(q -> titlu, tc) == 0)

        return q;
    return NULL;
}


aut * cauta3(aut * lista, char * num) {
    aut * q;
    for (q = lista; q != NULL && strcmp(q -> nume, num) < 0; q = q -> urm3);
    if (q != NULL && strcmp(q -> nume, num) == 0)

        return q;
    return NULL;
}

cap * intr1(cap * lista, cap * p) {
    cap * q1, * q2;
    for (q1 = q2 = lista; q1 != NULL && strcmp(q1 -> titlu_capitol, p -> titlu_capitol) < 0; q2 = q1, q1 = q1 -> urm1);
    p -> urm1 = q1;

    if (q1 == q2)
        return p;

    q2 -> urm1 = p;
    return lista;
}


car * intr2(car * lista, car * p) {
    car * q1, * q2;
    for (q1 = q2 = lista; q1 != NULL && strcmp(q1 -> titlu, p -> titlu) < 0; q2 = q1, q1 = q1 -> urm2);
    p -> urm2 = q1;

    if (q1 == q2)
        return p;

    q2 -> urm2 = p;
    return lista;
}


aut * intr3(aut * lista, aut * p) {
    aut * q1, * q2;
    for (q1 = q2 = lista; q1 != NULL && strcmp(q1 -> nume, p -> nume) < 0; q2 = q1, q1 = q1 -> urm3);
    p -> urm3 = q1;

    if (q1 == q2)
        return p;

    q2 -> urm3 = p;
    return lista;
}




void introd(char * n) {
    aut * a;
    car * c;
    cap * p;
    char d, tit[30];

    if ( (a = cauta3(prim, n)) ) {
        printf("\nAutorul exista!!!\n");

        while (printf("\nDoriti introducerea unei carti d/n:"), (d = getchar() ) != 'n') {
            printf("\nTitltu cartii:");
            while(getchar() != '\n')
            ;
            gets(tit);

            if ( (c = cauta2(a -> sl2, tit)) ) {
                printf("\nCartea exista!!!");

                while (printf("\nDoriti sa introduceti capitolele cartii d/n:"), (d = getchar() ) != 'n') {
                    printf("\nIntroduceti capitolul cartii:");
                    while(getchar() != '\n')
                    ;
                    gets(tit);
                    if ((p = cauta1(c -> sl1, tit))) {
                        printf("Titlul capitolului exista!!!");
                        continue;
                    }
                    if ((p = (cap * ) malloc(sizeof(cap))) == NULL || (p -> titlu_capitol = (char * ) malloc(strlen(tit) + 1)) == NULL)
                        printf("Nu este suficienta memorie");
                    strcpy(p -> titlu_capitol, tit);
                    c -> sl1 = intr1(c -> sl1, p);
                }
                continue;
            }

            if ((c = (car * ) malloc(sizeof(car))) == NULL || (c -> titlu = (char * ) malloc(strlen(tit) + 1)) == NULL)
                printf("Nu este suficienta memorie");
            strcpy(c -> titlu, tit);
            c -> sl1 = NULL;

            a -> sl2 = intr2(a -> sl2, c);
            while (printf("\nDoriti sa introduceti capitolele cartii d/n:"), (d = getchar() ) != 'n') {
                printf("\nIntroduceti capitolul cartii:");
                while(getchar() != '\n')
                ;
                gets(tit);

                if ((p = cauta1(c -> sl1, tit))) {
                    printf("Titlul capitolului exista!!!");
                    continue;
                }
                if ((p = (cap * ) malloc(sizeof(cap))) == NULL || (p -> titlu_capitol = (char * ) malloc(strlen(tit) + 1)) == NULL)
                    printf("Nu este suficienta memorie");
                strcpy(p -> titlu_capitol, tit);
                c -> sl1 = intr1(c -> sl1, p);
            }
        }
    } else {
        if ((a = (aut * ) malloc(sizeof(aut))) == NULL ||
            (a -> nume = (char * ) malloc(strlen(n) + 1)) == NULL)
            printf("Nu este suficienta memorie");
        strcpy(a -> nume, n);

        prim = intr3(prim, a);
        printf("Doriti introducerea unei carti d/n:");
        if ((d = getchar() ) == 'n')
            return;
        else {
            printf("\nTitlul cartii este:");
            while(getchar() != '\n')
            ;
            gets(tit);

            if ((c = (car * ) malloc(sizeof(car))) == NULL || (c -> titlu = (char * ) malloc(strlen(tit) + 1)) == NULL)
                printf("Nu este suficienta memorie");
            strcpy(c -> titlu, tit);
            c -> sl1 = NULL;

            a -> sl2 = intr2(a -> sl2, c);

            while (printf("\nDoriti sa introduceti capitolele cartii d/n:"), (d = getchar() ) != 'n') {
                printf("\nIntroduceti capitolul cartii:");
                while(getchar() != '\n')
                ;
                gets(tit);

                if ((p = cauta1(c -> sl1, tit))) {
                    printf("Titlul capitolului exista!!!");
                    continue;
                }


                if ((p = (cap * ) malloc(sizeof(cap))) == NULL || (p -> titlu_capitol = (char * ) malloc(strlen(tit) + 1)) == NULL)
                    printf("Nu este suficienta memorie");
                strcpy(p -> titlu_capitol, tit);
                c -> sl1 = intr1(c -> sl1, p);
            }
        }
    }
}


void afisare() {
    aut * a;
    car * c;
    cap * cc;
    printf("\nAutor           | Carte           | Capitole");
    printf("\n--------------------------------------------------------------------");
    for (a=prim;a!=NULL;a=a->urm3){
        printf("\n%15s",a->nume);
        if (a -> sl2 != NULL) {
            for (c = a -> sl2; c != NULL; c = c -> urm2) {
                printf("\n%30s", c -> titlu);
                if (c -> sl1 != NULL) {
                    for (cc = c -> sl1; cc != NULL; cc = cc -> urm1) 
                        printf("\n%60s ", cc -> titlu_capitol);
                } else
                    continue;
            }
        } else {
            continue;
            printf("\n--------------------------------------------------------------------");
        }
    }
}
void meniu() {
    printf("\na-adaugare in lista a unui autor\n");
    printf("p-afisarea evidentei\n");
    printf("t-terminare\n");
}


int main() {
    char c, n1[10];
    while (1) {
        meniu();
        printf("Introduceti optiunea:");
        scanf(" %c", &c);
        switch (c) {
            case 'a':
                printf("\nAutorul:");
                while(getchar() != '\n')
                ;
                gets(n1);
                introd(n1);
                break;
            case 'p':
                afisare();
                break;
            case 't':
                exit(1);
        }
    }
    return 0;
}