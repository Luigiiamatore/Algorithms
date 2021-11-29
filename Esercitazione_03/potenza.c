#include <stdio.h>

int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else {
        int pow;
        pow = base * power(base, --exp);
        return pow;
    }
}

int main() {
    int base, exp;
    printf("base: ");
    scanf("%d", &base);
    printf("esponente: ");
    scanf("%d", &exp);
    printf("potenza = %d", power(base, exp));
    return 0;
}