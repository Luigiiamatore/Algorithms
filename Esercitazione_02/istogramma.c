#include <stdio.h>
#include <ctype.h>

int main(){
    int ricorrenze[26];
    char letto;

    for(int i = 0; i < 26; i++){
        ricorrenze[i] = 0;
    }

    printf("Inserire una frase: ");

    for(;;){
        scanf("%c", &letto);
        if(letto == '.'){
            break;
        }
        letto = toupper(letto);
        ricorrenze[letto-65]++;
    }

    for(int i = 0; i < 26; i++){
        if(ricorrenze[i] != 0){
            printf("%c ", i+65);
            for(int j = 0; j < ricorrenze[i]; j++){
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}