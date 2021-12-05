#include <stdio.h>

void max_secondmax (int a[], int n, int *max, int *second_max) {
    if (n == 1) {
        *max = *a;
        *second_max = *a;
        return;
    } else {
        if (*a > *(a+1)) {
            *max = *a;
            *second_max = *(a+1);
        } else {
            *max = *(a+1);
            *second_max = *a;
        }

        for (int *i = a + 2; i < a + n; i++) {
            if (*i > *max) {
                *second_max = *max;
                *max = *i;
            } else if (*i > *second_max)
                *second_max = *i;
        }
        return;
    }
}

int main() {
    int dim;
    int max, second_max;

    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &dim);
    int a[dim];
    for (int i = 0; i < dim; i++)
        scanf("%d", &a[i]);

    if (dim > 0) {
        max_secondmax(a, dim, &max, &second_max);
        printf("Il numero più grande è: %d\nIl secondo numero più grande è: %d", max, second_max);
    }

    return 0;
}