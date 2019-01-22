#include <stdio.h>

#include <curses.h>

#include <string.h>

typedef struct {
    char make[20],
        model[20];
    int price;
}
stock;

void quit() {
    printf("\nquiting..");
}

void populate(stock * Darwin, int * counter) {
    ( * counter) ++;
    fflush(stdin);
    printf("\nGive values:\n");
    while (getchar() != ('\n'))
    ;
    printf("Make: ");
    gets(Darwin[ * counter].make);
    printf("Model: ");
    gets(Darwin[ * counter].model);
    printf("Price: ");
    scanf("%d", & Darwin[ * counter].price);
}

void showOff(stock * Darwin, int counter) {
    printf("\n %10s \t %10s \t %10d",
        Darwin[counter].make,
        Darwin[counter].model,
        Darwin[counter].price
    );
}
void search(stock * Darwin, char _make[20], int * counter) {
    int i;
    for (i = 0; i <= ( * counter); i++) {
        if (strcmp(Darwin[i].make, _make) == 0) {
            showOff(Darwin, i);
        }
    }
}

void compare(stock * Darwin, int _price, int * counter) {
    int i;
    for (i = 0; i <= * counter; i++) {
        if (Darwin[i].price == _price) {
            showOff(Darwin, i);
        }
    }
}
void sort(stock * Darwin, int * counter) {
    int i, sorted;
    stock clone;
    do {
        sorted = 1;
        for (i = 0; i < ( * counter); i++) {
            if (strcmp(Darwin[i].make, Darwin[i + 1].make) > 0) {
                clone = Darwin[i];
                Darwin[i] = Darwin[i + 1];
                Darwin[i + 1] = clone;
                sorted = 0;
            }
        }
    } while (!sorted);
    printf("\nSorted");
}
void delete(stock * Darwin, int * counter, char _model[20]) {
    int i, j, deleted;
    for (i = 0; i <= ( * counter - deleted); i++) {
        if (strcmp(Darwin[j].make, _model) == 0) {
            deleted++;
            for (j = i; j <= ( * counter - deleted); j++) {
                Darwin[j] = Darwin[j + 1];
            }
            i--;
        }
        * counter = * counter - deleted;
    }
}
int main(void) {
    int option = !0,
        n = -1, i, j,
        _price;
    char _model[20], _make[20],
        property;

    stock Darwin[10];
    do {

        printf("\n\n0. exit\n");
        printf("1. Populate\n");
        printf("2. Show off\n");
        printf("3. Search\n");
        printf("4. Compare\n");
        printf("5. Sort\n");
        printf("6. Delete\n");
        printf("Option: ");

        scanf("%d", & option);

        switch (option) {
            case 0:
                quit();
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
                printf("\n Make is:");
                while (getchar() != '\n')
                ;
                gets(_make);
                search(Darwin, _make, & n);
                break;
            case 4:
                printf("\n Value is:");
                scanf("%d", & _price);
                compare(Darwin, _price, & n);
                break;
            case 5:
                sort(Darwin, & n);
                break;
            case 6:
                printf("\n Model is:");
                while (getchar() != '\n')
                ;
                gets(_model);
                delete(Darwin, & n, _model);
                break;
            default:
                printf("\nInvalid case");
                break;
        }

    } while (option);
}