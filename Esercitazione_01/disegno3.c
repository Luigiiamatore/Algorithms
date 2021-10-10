#include <stdio.h>

int main(void){
    int n;
    printf("n = ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n + 2; j++){
            if((n - i == 3 && j == 0) || (n - i == 2 && j == 1) || (j + i == n + 1))
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}