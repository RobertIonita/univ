#include <stdio.h>

typedef struct {
    unsigned int 
        period: 4,
        kids: 3,
        lifetime: 11;
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
        depth: 9,
        speed: 7,
        water: 1;
}
fish;
typedef struct {
    unsigned int
        wingspan: 9,
        altitude: 11,
        speed: 9;
}
bird;

typedef struct {
    unsigned int
        kind:3;
}
data;

typedef union {
    mammal mammals;
    bug bugs;
    fish fishes;
    bird birds;
    data records;
}
type;

void read(type *animals, data *record, int *count, unsigned int opt) {
    (*count)++;
    record[*count].kind = opt;
    unsigned int value;
    switch (opt) {
        case 0:
            printf("\nPeriod (months): ");
            scanf("%u", & value); animals[*count].mammals.period = value;
            printf("\nPuppets: ");
            scanf("%u", & value); animals[*count].mammals.kids = value;
            printf("\nLifetime (ages): ");
            scanf("%u", & value); animals[*count].mammals.lifetime = value;
        break;
        case 1:
            printf("\nLegs: ");
            scanf("%u", & value); animals[*count].bugs.legs = value;
            printf("\nCan fly? ");
            scanf("%u", & value); animals[*count].bugs.flies = value;
            printf("\nDangerous? ");
            scanf("%u", & value); animals[*count].bugs.dangerous = value;
        break;
        case 2:
            printf("\nDepth (meters): ");
            scanf("%u", & value); animals[*count].fishes.depth = value;
            printf("\nSpeed (km/h): ");
            scanf("%u", & value); animals[*count].fishes.speed = value;
            printf("\nSalt water? ");
            scanf("%u", & value); animals[*count].fishes.water = value;
        break;
        case 3:
            printf("\nWingspan (cm): ");
            scanf("%u", & value); animals[*count].birds.wingspan = value;
            printf("\nAltitude (meters): ");
            scanf("%u", & value); animals[*count].birds.altitude = value;
            printf("\nSpeed (km/h): ");
            scanf("%u", & value); animals[*count].birds.speed = value;
        break;
    }
}

void showOff(type *animals, data *record, int count) {
    printf("\n\nRecord %d is a ", count+1);
    switch (record[count].kind) {
        case 0:
            printf("mammal\nperiod: %3u\npuppets: %2u\nlifetime: %u",
                animals[count].mammals.period,
                animals[count].mammals.kids,
                animals[count].mammals.lifetime
            );
        break;
        case 1:
            printf("bug\nlegs: %6u\nflies: %5u\ndangerous: %u",
                animals[count].bugs.legs,
                animals[count].bugs.flies,
                animals[count].bugs.dangerous
            );
        break;
        case 2:
            printf("fish\ndepth: %0u\nspeed: %0u\nsalt: %2u",
                animals[count].fishes.depth,
                animals[count].fishes.speed,
                animals[count].fishes.water
            );
        break;
        case 3:
            printf("bird\nwingspan: %u\naltitude: %u\nspeed: %5u",
                animals[count].birds.wingspan,
                animals[count].birds.altitude,
                animals[count].birds.speed
            );
        break;
    }
}

int main() {

    int option,
        i, count = -1;
        type animals[10];
        data record[10];
    
    while (1) {
        printf("\n\nAvailable options:");
        printf("\n0. exit");
        printf("\n1. mammal");
        printf("\n2. bug");
        printf("\n3. fish");
        printf("\n4. bird");
        printf("\n5. display records");
        printf("\nYour choice: ");
        scanf("%d", & option);

        switch (option) {
            case 0:
                return 0;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
                read(animals, record, &count, option-1);
                break;
            case 5:
                for(i = 0; i <= count; i++) {
                    showOff(animals, record, i);
                }
                break;
            default:
                printf("\nInvalid oprion");
                break;
        }
    }
    return 0;
}