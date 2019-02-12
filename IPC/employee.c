#include <stdio.h>

#include <conio.h>

#include <string.h>

typedef struct {
    char name[20],
        surname[20];
    int XP;
}
employee;

void quit() {
    printf("\nquiting..");
}

void populate(employee * prey, int *count) {
    (*count)++;
    printf("\nFulfil data:\n");
    while(getchar() != '\n'){
    };
    printf("Name: ");
    gets(prey[*count].name);
    printf("Surname: ");
    gets(prey[*count].surname);
    printf("Experience: ");
    scanf("%d", &prey[*count].XP);
}

void showOff(employee * prey, int count, int limit) {
    if(!limit || prey[count].XP < limit) {
        printf("\n%s \t %s \t %d",
            prey[count].name,
            prey[count].surname,
            prey[count].XP
        );
    }
}

void sortInverted(employee * prey, int count, int check) {
    int i, sorted = 0;
    employee clone;
    do {
        sorted = 1;
        for(i=0; i<count; i++) {
            if(strcmp(prey[i].surname, prey[i+1].surname) < 0) {
                clone = prey[i+1];
                prey[i+1] = prey[i];
                prey[i] = clone;
                sorted = 1;
            }
        }
    } while (!sorted);
    for(i = 0; i <= count; i++) {
        showOff(prey, i, check);
    }
    
}

void search(employee * prey, int count, char prey_name[20], char prey_surname[20]) {
    int i, found = 0;
    for(i = 0; i <= count; i++) {
        if(strcmp(prey[i].name, prey_name) == 0 && strcmp(prey[i].surname, prey_surname) == 0) {
            showOff(prey, i, 0);
            found = 1;
        }
    }
    if(!found) {
        printf("\nNothing found");
    }
}

void matrix(employee * prey, int count) {
    int i, j;
    for (i=0; i<=count; i++) {
        for(j=0; j<=count; j++) {
            if(i==j) {
                printf("%d ", strlen(prey[i].surname));
            } else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {

    int option, i, j, n = -1,
        exp;
    char guy_name[20], guy_surname[20];

    employee guys[10];

    do {
        printf("\n0. Exit\n");
        printf("1. Add employee\n");
        printf("2. Show employees data alphabetically inversed\n");
        printf("3. Search employees by name and surname\n");
        printf("4. Display alphabetically inversed employees which experience is < 10\n");
        printf("5. Create a matrix that contains on the main diagonal length of surmames\n   Remaining cells should be 0's\n");
        printf("Your choice is: ");
        scanf("%d", & option);

        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                populate(&guys[0], & n);
                break;
            case 2:
                sortInverted(guys, n, 0);
                break;
            case 3:
                while(getchar() != '\n'){
                };
                printf("\nEmployee name: ");
                gets(guy_name);
                printf("\nEmployee surname: ");
                gets(guy_surname);
                search(guys, n, guy_name, guy_surname);
                break;
            case 4: 
                sortInverted(guys, n, 10);
                break;
            case 5:
                matrix(guys, n);
                break;
            default:
                printf("\nPlease insert a valid option: \n\n");
                break;
        }

    } while (option != 0);

    return 0;
}