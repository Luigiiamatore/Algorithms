#include <stdio.h>

int main(void) {
    int n;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    int div = 2;
    while(n>1){
        if (n%div == 0)
        {
            n = n/div;
            printf("fattore %d\n",div);
        }
        else
        {
            div++;
        }
    }
}