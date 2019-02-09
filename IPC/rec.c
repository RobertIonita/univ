#include <stdio.h>

void func(int *x) {
    *x = 10;
}

int main(void) {
    int y = 20;
    func(&y);
    
    printf("%d", y);
    return 0;
}