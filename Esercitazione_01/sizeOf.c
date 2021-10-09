#include <stdio.h>
#include <limits.h>

int main(void){
    char c;
    signed char sc;
    unsigned char uc;
    short int sh_i;
    unsigned short int ssh_i;
    int n;

    printf("%d - %d, dimensione: %d", INT_MIN, INT_MAX, sizeof(int));
    printf("\n%d - %d, dimensione: %d", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("\n%d - %d, dimensione: %d", SCHAR_MIN, SCHAR_MAX, sizeof(signed char));
    printf("\n%d, dimensione: %d", UCHAR_MAX, sizeof(unsigned char));
    printf("\n%d - %d, dimensione: %d", SHRT_MIN, SHRT_MAX, sizeof(short int));
    printf("\n%d, dimensione: %d", USHRT_MAX, sizeof(unsigned short int));
}