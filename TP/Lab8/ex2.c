#include <stdio.h>
#include <stdlib.h>
void tip_void_un_param(int nr) {

}
int tip_int_un_param(int nr) {
    return 0;
}
void tip_void_doi_param(int nr,int nr1) {
}
int main(void)
{
    void (*un_pointer) (int nr);
    un_pointer=&tip_void_un_param;
    // un_pointer=&tip_int_un_param;
    // un_pointer=&tip_void_doi_param;
    return 0;
}