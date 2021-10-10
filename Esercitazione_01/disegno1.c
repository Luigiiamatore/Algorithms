#include <stdio.h>

int main(void) {
    int n;
    printf("n = ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i % 2 != 0) {
                if(j % 2 == 0)
                    printf("o");
                else
                    printf("+");
            } else {
                if(j % 2 == 0)
                    printf("+");
                else
                    printf("o");
            }
            printf(" ");
        }
        printf("\n");
    }
}