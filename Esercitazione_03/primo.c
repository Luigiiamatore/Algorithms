#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
typedef int bool;

bool isPrime (int n) {
    for (int div = 2; div < sqrt(n); div++) {
        if (n % div == 0) 
            return false;
    }
    return true;
}

int main() {
    int n;
    printf("Inserisci un numero e ti dirò se è un numero primo o no: ");
    scanf("%d", &n);
    if (isPrime(n))
        printf("Il numero %d è un numero primo!", n);
    else
        printf("Il numero %d non è un numero primo...", n);
    
    return 0;
}