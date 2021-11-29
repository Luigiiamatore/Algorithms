#include <stdio.h>

int nextCollatz (int n) {
    if (n % 2 == 0) return n/2;
    else return 3*n + 1;
}

int main() {
    int n;
    int length;
    printf("Inserisci un numero e ne stamperò la sequenza di Collatz: ");
    scanf("%d", &n);

    printf("%d", n);
    length = 1;
    while (n != 1) {
        n = nextCollatz(n);
        length++;
        printf("%d ", n);
    }
    printf("\nLunghezza: %d", length);
    return 0;
}