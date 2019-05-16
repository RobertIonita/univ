#include <stdlib.h>
#include <stdio.h>

void init (int **N, int n) {
	*N = (int *) malloc (n * sizeof(int));
	if(!*N) {
		printf("Can not allocate");
		exit(EXIT_FAILURE);
	}
}
void update (int **N, int n, int x) {
	int *try;
	try = (int *) realloc (*N, n * sizeof(int));
	if(!try) {
		printf("Can not reallocate");
		exit(EXIT_FAILURE);
	} else {
		**N = *try;
		(*N)[n-1] = x;
	}
}

void populate(int **N, int n, int *x) {
	printf("Insert Nr: ");
	scanf("%d", &(*x));
	update(&(*N), n, *x);
}

void showOff(int *N, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", N[i]);
}
int main () {
	int *N = NULL,
		n = 0,
		x = !0;
	init(&N, n);
	while (x != 0)
		populate(&N, ++n, &x);
	showOff(N, n);
	free(N);
	return 0;
}