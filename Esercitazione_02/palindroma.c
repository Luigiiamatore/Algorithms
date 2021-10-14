#include <stdio.h>
#include <string.h>

int main() {
    char parola[100];
    char letto;
    int len;
    printf("parola: ");
    for (int i = 0; i < 100; i++) {
        scanf("%c", &letto);
        if(letto == '.') {
            parola[i] = '\0';
            break;
        }
        parola[i] = letto;
    }

    len = strlen(parola);
    for(int i = 0; i < len; i++) {
        if(parola[i] != parola[len - 1 - i]){
            printf("La parola non è palindroma.");
            return 0;
        }
    }

    printf("La parola è palindroma.");

    return 0;
}