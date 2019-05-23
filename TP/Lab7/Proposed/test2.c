
#include <stdlib.h>
#include <stdio.h>

void init (char **N, int n) {
	*N = (char *) malloc (n * sizeof(char));
	if(!*N) {
		printf("Can not allocate");
		exit(EXIT_FAILURE);
	}
}
void update (char **N, int n, char x) {
	char *try;
	try = (char *) realloc (*N, n * sizeof(char));
	if(!try) {
		printf("Can not reallocate");
		exit(EXIT_FAILURE);
	} else {
		**N = *try;
		(*N)[n-1] = x;
	}
}

void populate(char **N, int n, char *x) {
	printf("Insert Nr: ");
	scanf(" %c", &(*x));
	update(&(*N), n, *x);
}

void showOff(char *N, int n) {
	for (int i = n-1; i >= 0; i--)
		printf("%c ", N[i]);
}
int main () {
	char *N = NULL,
		x = !0;
	int n = 0;
	init(&N, n);
	while (x != '0')
		populate(&N, ++n, &x);
	showOff(N, n);
	free(N);
	return 0;
}