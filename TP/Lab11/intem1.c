#include <stdio.h>
#include <stdlib.h>

void write (int nr, char * path) {
    FILE * f;
    if ((f = fopen(path, "wt")) == NULL) {
        printf("error");
    } else {
        for (size_t i = 0; i < nr; i++)
        {
            for (size_t j = 0; j < nr; j++)
            {
                if (j==i)
                {
                    fprintf(f, "0");
                } else if (j < i)
                {
                    fprintf(f, "-");
                } else
                {
                    fprintf(f, "+");
                }
            }
            fprintf(f, "\n");
            
        }
        
        fclose(f);
    }
}

int main() {
    int n;

    printf("Insert nr: ");
    scanf("%d", &n);

    write(n, "TP/Lab11/output1.txt");
}