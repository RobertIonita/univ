#include <stdio.h>
#include <string.h>

typedef struct {
    int day,
        month,
        year;
} time;

typedef struct {
    char name[20];
    time date;
} student;



void populate(student * dumb, int *counter) {
    ( *counter) ++;
    printf("\nGive values\n");
    while (getchar() != '\n')
    ;
    printf("Name: ");
    gets(dumb[*counter].name);
    printf("Day: ");
    scanf("%d", & dumb[*counter].date.day);
    printf("Month: ");
    scanf("%d", & dumb[*counter].date.month);
    printf("Year: ");
    scanf("%d", & dumb[*counter].date.year);
}
void showOff(student * dumb, int counter) {
    printf("\n%s \t %d \t %d \t %d",
        dumb[counter].name,
        dumb[counter].date.day,
        dumb[counter].date.month,
        dumb[counter].date.year
    );
}
void sort(student * dumb, int counter) {
    int i, sorted;
    student clone;
    do {
        sorted = 1;
        for (i = 0; i < (counter); i++) {
            if ( strcmp(dumb[i].name, dumb[i + 1].name) > 0) {
                sorted = 0;
                clone = dumb[i];
                dumb[i] = dumb[i + 1];
                dumb[i + 1] = clone;
            }
        }
    } while (!sorted);

    for (i = 0; i <= counter; i++) {
        showOff(dumb, i);
    }
}

int main(void) {

    int option = !0,
        n = -1, i, j,
        _date;
    char _name[20];
    student dumb[10];


    while(1) {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. sort");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                return 0;
            case 1:
                populate( & dumb[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    showOff(dumb, i);
                }
                break;
            case 3:
                sort(dumb, n);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    }
}