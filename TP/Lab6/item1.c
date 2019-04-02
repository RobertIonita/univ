#include <stdio.h>

typedef struct {
    unsigned int 
        period: 3,
        kids: 3;
}
mammal;

typedef struct {
    unsigned int
        legs: 10,
        flies: 1,
        dangerous: 1;
}
bug;
typedef struct {
    unsigned int
        water: 1,
        depth: 9,
        speed: 7;
}
fish;
typedef struct {
    unsigned int
        wings: 9,
        height: 8,
        speed: 9;
}
bird;

typedef struct {
    unsigned int
        lifetime: 11,
        kind:3;
}
data;

typedef union {
    mammal mammals;
    bug bugs;
    fish fishes;
    bird birds;
}
type;

void read_mammal(type *animals, data *record, int *count) {
    (*count)++;
    record[*count].kind = 0;
    unsigned int value;
    printf("\nPeriod: ");
    scanf("%u", & value); animals[*count].mammals.period = value;
    printf("\nPuppets: ");
    scanf("%u", & value); animals[*count].mammals.kids = value;
    printf("\nLifetime: ");
    scanf("%u", & value); record[*count].lifetime = value;
}
void read_bug(type *animals, int *count) {
    (*count)++;
    unsigned int value;
    printf("\nLegs: ");
    scanf("%u", & value); animals[*count].bugs.legs = value;
    printf("\nCan fly?: ");
    scanf("%u", & value); animals[*count].bugs.flies = value;
    printf("\nDangerous?: ");
    scanf("%u", & value); animals[*count].bugs.dangerous = value;
}

void showOff(type *animals, data *record, int count) {
    printf("\nRecord %d is a ", count+1);
    switch (record[count].kind) {
        case 0:
            printf("mammal\nperiod puppets lifetime");
            break;
    }
    printf("\n%5u %5u %5u",
        animals[count].mammals.period,
        animals[count].mammals.kids,
        record[count].lifetime
    );
}


int main() {

    int option,
        i, count = -1;
        type animals[10];
        data record[10];
    
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
                    showOff(animals, record, i);
                }
                break;
            case 2:
                read_mammal(animals, record, &count);
                break;
            // case 3:
            //     read_bug(animals, &count);
            //     break;
            // case 4:
            //     read_fish(animals, &count);
            //     break;
            // case 5:
            //     read_bird(animals, &count);
            //     break;
            default:
                printf("\nInvalid oprion");
                break;
        }
    }




    return 0;
}