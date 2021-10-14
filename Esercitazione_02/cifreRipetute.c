#include <stdio.h>

typedef int Bool;

int main() {
    int n;
    int cifra;
    int ricorrenze[10];
    Bool repeated = 0;
    for(int i = 0; i < 10; i++) {
        ricorrenze[i] = 0;
    }
    scanf("%d", &n);

    while(n != 0) {
        cifra = n % 10;
        n /= 10;
        ricorrenze[cifra]++;
    }

    for(int i = 0; i < 10; i++) {
        if(ricorrenze[i] >= 2) {
            repeated = 1;
            break;
        }
    }

    if(repeated){
        printf("Cifre ripetute: ");
        for(int i = 0; i < 10; i++) {
            if(ricorrenze[i] >= 2)
                printf("%d ", i);
        }
    } else {
        printf("Non ci sono cifre ripetute.");
    }

    return 0;
}