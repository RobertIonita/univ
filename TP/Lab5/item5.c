#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    int idnp;
} student;


void quit() {
    printf("\nquiting");
}
void populate(student * dumb, int *counter) {
    ( *counter) ++;
    printf("\nGive values\n");
    while (getchar() != '\n')
    ;
    printf("Name: ");
    gets(dumb[*counter].name);
    printf("Matricol: ");
    scanf("%d", & dumb[*counter].idnp);
}
void showOff(student * dumb, int counter) {
    printf("\n%10s \t %5d",
        dumb[counter].name,
        dumb[counter].idnp
    );
}
void search(student * dumb, int counter) {
    int i,
        st_idnp;
    char method,
        st_name[20];
    
    printf("\nInsert search method ('0' for idnp, 'whatever' for name): ");
    scanf(" %c", &method);
    if (method == '0') {
        printf("\nIDNP: ");
        scanf("%d", &st_idnp);
        for (i = 0; i <= (counter); i++) {
            if (dumb[i].idnp == st_idnp) {
                showOff(dumb, i);
            }
        }
    } else {
        printf("\nName: ");
        while (getchar() != '\n');
        gets(st_name);
        for (i = 0; i <= (counter); i++) {
            if ( strcmp(dumb[i].name, st_name) == 0) {
                showOff(dumb, i);
            }
        }
    }
}

void sort(student * dumb, int counter) {
    int i, sorted;
    char method;
    student clone;
    printf("\nInsert sort method ('0' for idnp, 'whatever' for name): ");
    scanf(" %c", &method);
    do {
        sorted = 1;
        for (i = 0; i < (counter); i++) {
            if ( 
                (method != '0' && strcmp(dumb[i].name,  dumb[i + 1].name ) > 0) ||
                (method == '0' &&        dumb[i].idnp > dumb[i + 1].idnp)
            ) {
                sorted = 0;
                clone = dumb[i];
                dumb[i] = dumb[i + 1];
                dumb[i + 1] = clone;
            }
            
        }
    } while (!sorted);
}

int main(void) {

    int option = !0,
        n = -1, i, j,
        st_idnp;
    char st_name[20];
    student dumb[10];


    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. search");
        printf("\n4. sort");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                populate( & dumb[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    showOff(dumb, i);
                }
                break;
            case 3:
                search(dumb, n);
                break;
            case 4:
                sort(dumb, n);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option);
}