#include <stdio.h>

int main(void){
    int n, div;
    printf("Inserire un numero: ");
    scanf("%d", &n);

    printf("Lista divisori:\n");
    div = n;
    while (div > 0) {
        if (n % div == 0) {
            printf("%d ", div);
        }
        div--;
    }
}