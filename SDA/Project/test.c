#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test (char (*arr)[4], char * str) {
    int k = 0,
        j = 0,
        i = 0;
    for (i = 0; str[i] !='\0'; i++)
    {
        if (str[i] != '/') {
            arr[k][j++] = str[i];
        } else {
            arr[k][j] = '\0';
            k++; j = 0;
        }
    }
    for (int i = 0; i < 3; i++)
        printf("\n[%d]: %s", i, arr[i] );
}
int main()
{
    char arr[3][4];
    sort(arr, "12/05/2019");
    return 0;
}