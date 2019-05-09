#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>

typedef struct{ 
    char *nume; 
    int nr; 
} student;

#define SIZE sizeof(student)

typedef student *pstud;

void eroare(void){
    puts("\n **** eroare alocare dinamica de memorie ****");
    exit(1);
}

void citeste(int *n, pstud *tab){
    pstud t;
    char sir[40];
    int i;
    printf("\n dati numarul studentilor: ");
    scanf("%d",n);
    if(!(t=(pstud)malloc((*n)*SIZE))) eroare(); 
    *tab = t;
    for (i=0; i<*n; i++, t++) {
         printf("\n nume: "); 
         scanf("%s", sir); /* aloca dinamic spatiu pentrunumele studentului*/
        if (!(t->nume=(char *) malloc(strlen(sir)+1))) eroare(); 
        strcpy(t->nume, sir); 
        printf("\n numar matricol: "); 
        scanf("%d", &t-> nr); 
        }
}

void afiseaza (int n, pstud tab){
    int i;
    puts("\n tabelul cu studenti");
    for (i=0; i<n; i++, tab++) 
    printf("\n%-30s %4d", tab->nume, tab->nr);

}

void elibereaza(pstud tabel, int n){
     int i;
     for (i=0; i<n; i++) 
        free(tabel[ i ].nume); 
        free(tabel);
}

void meniu(void){ 
    puts("\n c, C ---citeste tabel studenti"); 
    puts("\n a, A ---afiseaza tabel studenti");
    puts("\n n, N ---ordoneaza dupa nume");
    puts("\n r, R ---ordoneaza dupa numar matricol");
    puts("\n f, F ---cauta dupa nume");
    puts("\n l, L ---cauta dupa numar matricol");
    puts("\n x, X ---iesire din program"); 
    }

void main(void){
    char opt;
    int n; //numarul de studenti
    char nume[30];
    student s;
    pstud tabel = NULL; //adresa tabloului cu studenti

    while(1){
        meniu();
        opt = tolower(getchar());
        switch(opt){

            case 'c':
            if(tabel) //daca a existat anterior un alt tablou in memorie
            elibereaza(tabel, n);
            citeste(&n, &tabel); 
            break;
            
            case 'a':
            afiseaza(n, tabel); 
            break;

            case 'n':
            sorteaza_alfabetic(tabel,n); 
            break;

            case 'r':
            sorteaza_dupa_nr_matricol(tabel,n);
            break;

            case 'f': 
            printf("\n dati numele: ");
            scanf("%s", nume);
            if(!(s.nume = (char*) malloc(strlen(nume)+1))) eroare();
            strcpy(s.nume,nume);
            cauta_dupa_nume(&s, tabel, n);
            free(s.nume); 
            break;

            case 'l':
            printf("\n dati numarul matricol: ");
            scanf("%d", &s.nr);
            cauta_dupa_nr_matricol(&s, tabel, n);
            break;

            case 'x':
            exit(0);
            
            default:
            puts("Comanda gresita");
        }
    }
}