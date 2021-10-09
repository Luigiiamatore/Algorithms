#include <stdio.h>
#include <math.h>

int main(void) {
    int n, i;
    printf("Inserire un numero: ");
    scanf("%d", &n);
        
    for(i = 2; i <= sqrt(n); i++) {
        if (n % i == 0){
            printf("Il numero non è primo.");
            return 0;
        }
    }
    printf("Il numero è primo.");

    return 0;
}