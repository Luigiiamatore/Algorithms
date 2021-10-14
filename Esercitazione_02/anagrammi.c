#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int ricorrenze1 [26];
    int ricorrenze2 [26];
    char parola1[100];
    char parola2[100];
    char c1, c2;

    printf("Parola 1: ");
    scanf("%s", parola1);

    printf("Parola 2: ");
    scanf("%s", parola2);

    for(int i = 0; i < 26; i++){
        ricorrenze1[i] = 0;
        ricorrenze2[i] = 0;
    }

    if(strlen(parola1) != strlen(parola2)){
        printf("Le due parole non sono anagrammi, hanno lunghezza diversa.");
        return 0;
    }
    for(int i = 0; i < strlen(parola1); i++) {
        c1 = toupper(parola1[i]);
        ricorrenze1[c1 - 65]++; 
        c2 = toupper(parola2[i]);
        ricorrenze2[c2 - 65]++; 
    }

    int anag = 1;
    for(int i = 0; i < strlen(parola1); i++) {
        if(ricorrenze1[i] != ricorrenze2[i]) {
            anag = 0;
            break;
        }
    }

    if(anag) {
        printf("Le due parole sono anagrammi.");
    } else {
        printf("Le due parole non sono anagrammi.");
    }

    return 0;
}