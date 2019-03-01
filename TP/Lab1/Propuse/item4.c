/*4.Se cere sa se scrie o functie care primeste ca parametru un vector de n numere intregi si pune in vectorul original pe primele pozitii toate numerele prime pe care le-a gasit in vector. 
Valorile de pe celelate pozitii nu conteaza.
Functia va returna numarul de numere prime gasite.
Pentru testarea daca un numar este prim , se va folosi o functie care primeste ca parametru acel numar si va returna 0 sau 1.*/
#include <stdio.h>
#include <stdlib.h>

int prime(int x) {
	int i;
	for (i = 2; i < x / 2+1; i++) {
		if (x % i == 0)
			return 0;
	}
	
	return (x == 1) ? 0 : 1;
}

int matches(int x[], int y) {
	int k = 0;
	int i;

	for (i = 0; i < y; i++) {
		if (prime(x[i]) == 1) {
			x[k++] = x[i];
		}
	}
	for (i = 0; i < k; i++) {
		printf("\nModified vector: %d", x[i]);
	}

	return k;
}


int item4() {
	int vect[100];
	int n, i;

	printf("\nInsert N: ");
	scanf("%d", & n);

	printf("\nVector's elements are: \n");
	for (int i = 0; i < n; i++) {
		printf("\nvect[%d]: ", i);
		scanf("%d", & vect[i]);
	}
	printf("\nNr of primes is: %d", matches(vect, n));
	return 0;
}