/* 3.Scrieti o functie care primeste ca parametri un tablou de intregi si dimensiunea n a acestuia si pune in tablou maxim n numere citite de la tastatura dintr-o linie de text.
Functia va prelucra o singura linie de text(adica pana la aparitea caracterului '\n').
Functia va returna numarul de numere citite (maxim n).
Functia va ignora orice caractere diferite de cifre sau spatiu. In momentul in care este intalnit EOF, functia va returna 1.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 4

int Number(char str[10]) {
	int number = 0, i;

	for (i = 0; i < strlen(str); i++) {
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

int convertToArray(char str[100], int arr[N_MAX]) {
	int i=0, k=0, nr;
	char sliced[10][10];
	
	for(i=0; i < strlen(str); i++) {
		nr = Number(&str[i]);
		if (str[i] == ' ')
			k++;
		else {
			arr[k] *= 10;
			arr[k] += firstUnit(nr);
		}
	}
	return k > 3? 3 : k;
}

void clrArray (int *arr, int n) {
	int i;
	for (i=0; i<n; i++) {
		arr[i] = 0;
	}
}

int citeste_numere(int *arr, int n) {
	char str[20];
	int r = -1;
	clrArray(arr, n);
	gets(str);
	if(strlen(str)) {
		r = convertToArray(str, arr)+1;
	} else {
		r = -1;
	}
	
	return r > 0 ? r : -1;

}
int intem3(void) {
	int a[N_MAX];
	int i, k;
	while ((k = citeste_numere(a, N_MAX)) != -1) {
		printf("Am citit %d numere: ", k);
		for (i = 0; i < k; i++)
			printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}