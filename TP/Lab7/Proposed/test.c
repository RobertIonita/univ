#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

void test (char **input, int * n, char * str) {
    int i = 0,
        k = 0;
    char *previous;
    for (i = 0; str[i] !='\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\t') {
            update(&(*input), ++(*n), str[i]);
        } else {
            if(previous == NULL) {
                previous = *input;
                printf("%s", previous);
            }
            else if (*input != NULL && previous[(*n)-2] == *input[0] && previous[(*n)-1] == *input[1]) {
                previous = *input;
            }
	        *input = (char *) realloc (*input, (*n = 0) * sizeof(char));
        }
    }
    printf("-%s", *input);

}
int main()
{
    char *input = NULL;
    int n = 0;
    init(&input, n);
    test(&input, &n, "abc bca");
    return 0;
}