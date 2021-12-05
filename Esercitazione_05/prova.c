#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a;
    int n = 5;
    a = malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++)
        *(a + i) = calloc(5, sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n/2 || j == n/2) {
                *(*(a + i) + j) = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", *(*(a+i)+j));
        }
        printf("\n");
    }

    printf("\n%d", n/2);

    return 0;
}