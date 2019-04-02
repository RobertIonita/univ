#include <stdio.h>

typedef struct {
    unsigned int period: 3;
    unsigned int kids: 3;
}
mammal;

typedef struct {
    unsigned int legs: 10;
    unsigned int flies: 1;
    unsigned int dangerous: 1;
}
bug;
typedef struct {
    unsigned int water: 1;
    unsigned int depth: 9;
    unsigned int speed: 7;
}
fish;
typedef struct {
    unsigned int wings: 9;
    unsigned int height: 8;
    unsigned int speed: 9;
}
bird;

typedef struct {
    unsigned int age: 11;
}
lifetime;

typedef union {
    mammal mammals;
    bug bugs;
    fish fishes;
    bird birds;
    lifetime lifetimes;
}
type;

void read_mammal(type *animals, int *count) {
    (*count)++;
    unsigned int value;
    printf("\nPerioada: ");
    scanf("%d", & value); animals[*count].mammals.period = value;

    // printf("\nNr pui: ");
    // scanf("%d", & value); animals[*count].mammals.kids = value;

    // printf("\nVarsta medie: ");
    // scanf("%d", & value); animals[*count].lifetimes.age = value;
}

void showOff(type *animals, int count) {
    printf("\n%d",
        animals[count].mammals.period
        // animals[count].mammals.kids,
        // animals[count].lifetimes.age
    );
}


int main() {

    int option,
        i, count = -1;
        type animals[10];
    
    while (1) {
        printf("\nAvailable options:");
        printf("\n0. exit");
        printf("\n1. display records");
        printf("\n2. mammal");
        printf("\n3. bug");
        printf("\n4. fish");
        printf("\n5. bird");
        printf("\nYour choice: ");
        scanf("%d", & option);

        switch (option) {
            case 0:
                return 0;
                break;
            case 1:
                for(i = 0; i <= count; i++) {
                    showOff(animals, count);
                }
                break;
            case 2:
                read_mammal(animals, &count);
                break;
            default:
                printf("\nInvalid oprion");
                break;
        }
    }




    return 0;
}