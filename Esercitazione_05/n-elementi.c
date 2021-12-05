#include <stdio.h>
#include <stdlib.h>

int *read_n (int *num) {
    int *a, i;
    scanf("%d", num);

    a = malloc((*num) * sizeof(int));
    for (i = 0; i < *num; i++)
        scanf("%d", &a[i]);

    return a;
}

int main() {
    void *p;
    int num;
    p = read_n(&num);

    for (int i = 0; i < num; i++)
        printf("%d", *((int*)p+i));

    free(p);

    return 0;
}