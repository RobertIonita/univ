#include <stdio.h>

void addValues(int value) {
    printf("%d", value);
}

int main() {
    int option = 1;
    do {
        printf("Hello world");
        scanf("%d", & option);

        switch (option) {
            case 1:
                addValues();
                break;
            case 0: 
                quitExecution();
                break;
            default:
                printf("Please insert a valid value");
        }
    } while (option != 0);

    return 0;
}