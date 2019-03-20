#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    float price;
} product;


void quit() {
    printf("\nquiting");
}
void populate(product * grocery, int *counter) {
    ( *counter) ++;
    printf("\nGive values\n");
    while (getchar() != '\n')
    ;
    printf("Name: ");
    gets(grocery[*counter].name);
    printf("Price: ");
    scanf("%f", & grocery[*counter].price);
}
void showOff(product * grocery, int counter) {
    printf("\n%10s \t %5.2f",
        grocery[counter].name,
        grocery[counter].price
    );
}
void search(product * grocery, int counter, char _name[20]) {
    int i, k = 0;
    for (i = 0; i <= (counter); i++) {
        if (strcmp(grocery[i].name, _name) == 0) {
            k++;
            showOff(grocery, i);
        }
    }
    if(!k) {
        printf("\nNu exista");
    }
}

void sort(product * grocery, int counter) {
    int i, sorted;
    product clone;
    do {
        sorted = 1;
        for (i = 0; i < (counter); i++) {
            if (grocery[i].price < grocery[i + 1].price) {
                sorted = 0;
                clone = grocery[i];
                grocery[i] = grocery[i + 1];
                grocery[i + 1] = clone;
            }
        }
    } while (!sorted);

    for (i = 0; i <= counter; i++) {
        showOff(grocery, i);
    }
}

void delete(product *grocery, int *counter, char desired[]) {
    int i, j;
    for (i = 0; i <= *counter; i++) {
        if (strcmp(grocery[i].name, desired) == 0) {
            (*counter)--;
            for (j = i++; j <= *counter; j++) {
                grocery[j] = grocery[j + 1];
            }
            i--;
        }
    }
}

int main(void) {

    int option = !0,
        n = -1, i, j,
        _price;
    char _name[20];
    product grocery[10];


    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\n3. search");
        printf("\n4. sort");
        printf("\n5. delete");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                populate( & grocery[0], & n);
                break;
            case 2:
                for (i = 0; i <= n; i++) {
                    showOff(grocery, i);
                }
                break;
            case 3:
                printf("\nDesired name: ");
                while (getchar() != '\n')
                ;
                gets(_name);
                search(grocery, n, _name);
                break;
            case 4:
                sort(grocery, n);
                break;
            case 5:
                printf("\nDesired name to be deleted: ");
                while (getchar() != '\n')
                ;
                gets(_name);
                delete(grocery, &n, _name);
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option);
}