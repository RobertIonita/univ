#include <stdlib.h>
#include <stdio.h>

void init (int *N, int *n) {
	N = (int *) malloc (*n * sizeof(int));
	if(!N) {
		printf("Can not allocate");
		exit(EXIT_FAILURE);
	}
}

void populate(int *N, int *n) {
	printf("%d", sizeof(*N));
	*n = 0;
}

int main () {
	int N, n = 320;
	init(&N, &n);
	while (n !=0 )
		populate(&N, &n);
	
	return 0;
}