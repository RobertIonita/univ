#include <stdio.h>
#include <string.h>

typedef struct {
	int hour;
	float degree;
} meteo;


void populate(meteo * day, int *counter) {
    ( *counter) ++;
    printf("\nGive values\n");
    printf("Time: ");
    scanf("%d", & day[*counter].hour);
    printf("Temerature: ");
    scanf("%f", & day[*counter].degree);
}
void showOff(meteo * day, int counter) {
    printf("\n%2d:00 - %4.1f°C",
        day[counter].hour,
        day[counter].degree
    );
}

void select(meteo *day, int counter) {
    int start, end,
        i;
    printf("\nInsert start time: ");
    scanf("%d", &start);
    printf("Insert end time: ");
    scanf("%d",&end);
    for(i = 0; i <= counter; i++) {
        if (day[i].hour >= start && day[i].hour <= end) {
            showOff(day, i);
        }
    }
}

int main() {
	meteo today[10];
	int i,
        option, n=-1,
        index;
	
	while(1) {
        printf("\n1.Add");
        printf("\n2.Display");
        printf("\n2.Select");
        printf("\n0.Exit");
		printf("\nInsert option: "); 
        scanf("%d", &option);
		switch (option){
            case 1:
                populate(& today[0], & n);
                break;
            case 2:
                for(i = 0; i <= n; i++) {
                    showOff(today, i);
                }
                break;
            case 3:
                select(today, n);
                break;
            case 0:
                return 0;
            default: 
                printf("\nInvalid option");
            break;
		}
	}
}