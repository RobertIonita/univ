// no requirements

#include <stdio.h>

void displayBinary(int n)
{
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
        printf("%d", ((n >> i) & 1));
}

int makeNth1(int nr, int n)
{
    nr = nr | (1 << n);
    return nr;
}

int makeNth0(int nr, int n)
{
    nr = nr & ~(1 << n);
    return nr;
}
unsigned short checkNthBit(int nr, int n)
{
    return (nr & (1 << n)) > 1;
}
int complementNthBit(int nr, int n)
{
    return nr ^ (1 << n);
}
unsigned short countOnes(int nr)
{
    unsigned short k = 0;
    for (size_t i = 0; i < sizeof(int) * 8; i++)
        if (nr & (1 << i))
            k++;
    return k;
}
unsigned short smartCountOnes(int nr)
{
    unsigned short k = 0;
    do {
        nr &= nr-1;
        k++;
    } while (nr);
    return k;
}
unsigned short isPower(int nr) {
    return !(nr & (nr-1));
}
unsigned short biggestDevisor(int nr) {
    return nr ^ (nr & (nr-1));
}

unsigned short MSBIndex(long n) {
    for (size_t i = 0; i <= sizeof(int); i++)
        n |= (n >> (1 << i));
	return smartCountOnes(n) - 1;
}
void menu(int *x, unsigned short *o, unsigned short *n)
{
    printf("\n0. Quit");
    printf("\n1. Display binary");
    printf("\n2. Make Nth bit 1");
    printf("\n3. Make Nth bit 0");
    printf("\n4. Check if Nth bit is 1");
    printf("\n5. Complement Nth bit");
    printf("\n6. Count ones");
    printf("\n7. Check if is power of 2");
    printf("\n8. Biggest power of 2 that is divisor");
    printf("\n9. Index of MSB");
    printf("\nUr choice: ");
    scanf("%hu", o);
    if (*o)
    {
        printf("\nInsert an integer: ");
        scanf("%d", x);
        if (*o > 1 && *o < 6)
        {
            printf("\nInsert Nth bit:");
            scanf("%hu", n);
        }
    }
}

int main()
{
    int x;
    unsigned short
        o,
        n;
    while (1)
    {
        menu(&x, &o, &n);
        switch (o)
        {
        case 0:
            return 0;
            break;
        case 1:
            displayBinary(x);
            break;
        case 2:
            printf("\nProcessed: %d", makeNth1(x, n));
            break;
        case 3:
            printf("\nProcessed: %d", makeNth0(x, n));
            break;
        case 4:
            printf("\nAnswer: %hu", checkNthBit(x, n));
            break;
        case 5:
            printf("\nProcessed: %d", complementNthBit(x, n));
            break;
        case 6:
            printf("\nAnswer: comparison:%hu, subtraction: %hu", countOnes(x), smartCountOnes(x));
            break;
        case 7:
            printf("\nAnswer: %hu", isPower(x));
            break;
        case 8:
            printf("\nAnswer: %hu", biggestDevisor(x));
            break;
        case 9:
            printf("\nAnswer: %hu", MSBIndex(x));
            break;
        default:
            printf("\nInvalid option");
            break;
        }
    }
    printf("%d in binary: ", x);
    displayBinary(x);
}