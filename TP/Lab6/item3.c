#include <stdio.h>

typedef struct {
    unsigned int 
        legs: 11,
        weight: 3,
        dangerous: 1,
        lifetime: 11;
    char abbr[8];
}
animal;

void populate(animal *kind, int *count) {
    (*count)++;
    unsigned int value;
    printf("\nLegs: ");
    scanf("%u", & value); kind[*count].legs = value;
    printf("\nWeight (kg): ");
    scanf("%u", & value); kind[*count].weight = value;
    printf("\nDangerous? ");
    scanf("%u", & value); kind[*count].dangerous = value;
    printf("\nAbbreviation: ");
    scanf("%s", kind[*count].abbr);
    printf("\nLifetime (ages): ");
    scanf("%u", & value); kind[*count].lifetime = value;
}

void showOff(animal *kind, int count) {
    printf("\nRecord %d:\nlegs: %3u\nweight: %2u\ndangerous: %u\nabbreviation: %s\nlifetime:%u\n---------------------",
        count+1,
        kind[count].legs,
        kind[count].weight,
        kind[count].dangerous,
        kind[count].abbr,
        kind[count].lifetime
    );
}

int main() {
    int option,
        i, count = -1;
        animal kind[10];
    
    while (1) {
        printf("\n\nAvailable options:");
        printf("\n0. exit");
        printf("\n1. read");
        printf("\n2. display records");
        printf("\nYour choice: ");
        scanf("%d", & option);

        switch (option) {
            case 0:
                return 0;
                break;
            case 1:
                populate(kind, &count);
                printf("\nRecords occupies: %ld bytes", sizeof(kind));
                break;
            case 2:
                for(i = 0; i <= count; i++) {
                    showOff(kind, i);
                }
                break;
            default:
                printf("\nInvalid oprion");
                break;
        }
    }
    return 0;
}