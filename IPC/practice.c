#include <stdio.h>

#include <curses.h>

#include <string.h>

typedef struct {
    char make[20],
        model[20];
    int price;
}
stock;

void exitExecution() {
    printf("\nquiting..");
}
void populate(stock * Darwin, int * counter) {
    ( * counter) ++;
    printf("\nAdd values\n");
    fflush(stdin);
    while (getchar() != '\n')
    ;
    printf("Make: ");
    gets((Darwin + * counter) -> make);
    printf("Model: ");
    gets((Darwin + * counter) -> model);
    printf("Price: ");
    scanf("%d", & (Darwin + * counter) -> price);
}

void showOff(stock * Darwin, int counter) {
    printf("\n%5s\t %5s\t %d",
        (Darwin + counter) -> make,
        (Darwin + counter) -> model,
        Darwin[counter].price
    );
}

void sort(stock * Darwin, int * counter) {
    int i, sorted;
    stock clone;
    do {
        sorted = 1;
        for (i = 0; i <= ( * counter - 1); i++) {
            if (strcmp((Darwin + i) -> model, (Darwin + i + 1) -> model) > 0) {
                clone = * (Darwin + i);
                *(Darwin + i) = * (Darwin + i + 1);
                *(Darwin + i + 1) = clone;
                sorted = 0;
            }
        }
    } while (!sorted);
}

void search(stock * Darwin, int * counter, char _model[20]) {
    int i;
    for (i = 0; i <= ( * counter); i++) {
        if (strcmp(Darwin[i].model, _model) == 0) {
            showOff(Darwin, i);
        }
    }
}
void delete(stock * Darwin, int * counter, char _model[20]) {
    int k = 0, j, i;
    for (i = 0; i <= ( * counter - k); i++) {
        if (strcmp(Darwin[i].model, _model) == 0) {
            k++;
            for (j = i; j <= ( * counter - k); j++) {
                Darwin[j] = Darwin[j + 1];
            }
            i--;
        }
        * counter = * counter - k;
    }
}

void compare(stock * Darwin, int * counter, int _price) {
    int i, exists = 0;
    for (i = 0; i <= * (counter); i++) {
        if (Darwin[i].price < _price) {
            showOff( & Darwin[0], i);
            exists = 1;
        }
    }
    if (!exists) {
        printf("There are no items cheaper than %d unit(s)", _price);
    }
}
int main(void) {

    stock Darwin[10];
    int option, n = -1, _price, i, j;
    char _make[20], _model[20];

    printf("You have some available options: \n");

    do {
        printf("\n\n0. Quit execution");
        printf("\n1. Add new records");
        printf("\n2. Display all records");
        printf("\n3. Sort products based on their model");
        printf("\n4. Search products based on their model");
        printf("\n5. Delete products based on their model");
        printf("\n6. Display all products cheaper than a given number");
        printf("\nInsert option: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                exitExecution();
                break;
            case 1:
                populate( & Darwin[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    showOff(Darwin, i);
                }
                break;
            case 3:
                sort( & Darwin[0], & n);
                for (i = 0; i <= n; i++) {
                    showOff( & Darwin[0], i);
                }
                break;
            case 4:
                printf("\nInsert desired model: ");
                while (getchar() != '\n')
                ;
                gets(_model);
                search(Darwin, & n, _model);
                break;
            case 5:
                printf("\nInsert model to deletes: ");
                while (getchar() != '\n')
                ;
                gets(_model);
                delete(Darwin, & n, _model);
                break;
            case 6:
                printf("\nInsert product price: ");
                scanf("%d", & _price);
                compare(Darwin, & n, _price);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option != 0);

    return 0;
}