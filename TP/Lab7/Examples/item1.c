#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char * nume;
    int varsta;
} persoana;

int n;
persoana * tab;

int citire(void){
    int i, n;
    char buf[80];
    printf("Introduceti numarul de persoane: ");
    scanf("%d", &n);
    tab = (persoana *) malloc (n * sizeof(persoana));
    if(!tab){
        printf("Eroare alocare dinamica de memorie \n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < n; i++){
        printf("Introduceti numele persoanei %d: ", i+1);
        scanf("%s", buf);
        tab[i].nume = (char *) malloc (strlen(buf) + 1);
        if (!tab[i].nume) {
            printf("Eroare alocare dinamica de memorie\n");
            exit(EXIT_FAILURE);
        }

        strcpy(tab[i].nume, buf);
        printf("Introduceti varsta persoanei %d: ", i+1);
        scanf("%d", &tab[i].varsta);
    }
    return i;
}
void afisare(persoana *p, int nr){
    printf("\n%10s %d", 
        p[nr].nume,
        p[nr].varsta
    );
}

int main(){
    int i,
        n;
    n = citire();
    for (i = 0; i < n; i++) {
        afisare(tab, i);
    }
    return 0;
}