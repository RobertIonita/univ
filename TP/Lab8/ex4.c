#include <stdio.h>
#include <math.h>

float sinus(int n) {
    return sin(n);
}
float cosin(int n) {
    return cos(n);
}
float max(float( * un_pointer_la_functie)(int)) {
    int i;
    float valoare;
    float max = 0;
    for (i = 0; i < 10; i++) {
        valoare = ( * un_pointer_la_functie)(i);
        if (max < valoare)
            max = valoare;
    }
    return max;
}

int main(void) {
    printf("Maxim pentru sinus: %f.\n", max( & sinus));
    printf("Maxim pentru cosinus: %f.\n", max( & cosin));
    return 0;
}