#include<stdio.h>
#include<stdlib.h>

int main() {
	int *N, *aux;
	int i = 0, n;
	N = (int*)malloc(1);

	printf("Cititi numerele: \n");
	do {
		scanf("%d", &n);

		aux = (int*)realloc(N, (i+1) * sizeof(int));
		if (!aux) {
			printf("Nu pot redimensiona spatiul alocat.\n");
			exit(EXIT_FAILURE);
		}
		else {
			N = aux;
			N[i] = n;
			i++;
		}
	} while (n != 0);

	printf("Afisare in ordine inversa: ");
	for (i = i - 2; i >= 0; i--) {
		printf("%d", N[i]);
	}

	free(N);
	return 0;
}