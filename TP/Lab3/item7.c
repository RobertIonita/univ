#include <stdio.h>

#define MAX 250


int Number(char str[10]) {
	int number = 0, i;

	for (i = 0; str[i] != '\0'; i++) {
		if(str[i] != ' ' && str[i] != '\n') {
			number *= 10;
			number += str[i]-48;
		} else{
			break;
		}
	}
	return number;
}

int firstUnit(int nbr) {
	while (nbr > 10) {
		nbr /=10;
	}
	return nbr;
}

int convertToArray(char str[100], int (*arr)[]) {
	int i=0, k=0, nr;
	char sliced[10][10];
	
	for(i=0; str[i] != '\0'; i++) {
		nr = Number(&str[i]);
		if (str[i] == ' ')
			k++;
		else {
			(*arr)[k] *= 10;
			(*arr)[k] += firstUnit(nr);
		}
	}
	return k;
}
 
void showOff(int (*arr)[], int n, int s) {
    int i;
    for(i = 0; i < n; i++) {
        s += (*arr)[i];
        if ((*arr)[i])
            printf("%d ", (*arr)[i] );
    }
    printf("\nSumm is: %d", s);
}

void filter (char (*string)[], int (*arr)[]) {
    int i, nr;
    for(i = 0; (*string)[i] != '\0'; i++) {
        nr = (*string)[i]-48;
        if ( (*string)[i] < '0' || (*string)[i] > '9') {
            (*string)[i] = ' ';
        }
    }
}

int main() {
    char str[MAX];
    int numbers[MAX/2],
        i, n,
        summ = 0;

    printf("Insert string: ");
    scanf("%s", str);

    filter(&str, &numbers);
    n = convertToArray(str, &numbers)+1;
    
    printf("\nNumbers are: "); showOff(&numbers, n, summ);
    return 0;
}