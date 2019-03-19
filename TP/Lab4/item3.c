#include <stdio.h>
#include <string.h>

typedef struct {
    int height,
        width;
} shape;


void quit() {
    printf("\nquiting");
}
void populate(shape * rectangle, int *counter) {
    ( *counter) ++;
    printf("\nGive values\n");
    while (getchar() != '\n')
    ;
    printf("Height: ");
    scanf("%d", & rectangle[*counter].height);
    printf("Width: ");
    scanf("%d", & rectangle[*counter].width);
}
void showOff(shape * rectangle, int counter) {
    printf("\nRectangle %d: height = %d width = %d",
        counter+1,
        rectangle[counter].height,
        rectangle[counter].width
    );
}
int max (shape *rectangle, int counter) {
    int i = 0,
        k = 0,
        area = rectangle[i].height * rectangle[i].width,
        max = area;
    for(i = 1; i <= counter; i++) {
        area = rectangle[i].height * rectangle[i].width;
        if (area > max) {
            k++;
            max = area;
        }
    }
    
    return k;
}

int main(void) {

    int option = !0,
        n = -1,
        i, j;
    shape rectangle[10];


    do {
        printf("\nAvailable options are:");
        printf("\n0. quit");
        printf("\n1. add");
        printf("\n2. show");
        printf("\nYor choice: ");
        scanf("%d", & option);
        switch (option) {
            case 0:
                quit();
                break;
            case 1:
                populate( & rectangle[0], & n);
                break;
            case 2:
                showOff(rectangle, max(rectangle, n));
                break;
            default:
                printf("\nInvalid option");
                break;
        }
    } while (option);
}