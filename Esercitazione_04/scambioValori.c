#include <stdio.h>

void scambia (int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int p, q;
    printf("p: ");
    scanf("%d", &p);
    printf("q: ");
    scanf("%d", &q);

    scambia(&p, &q);

    printf("p: %d\nq: %d", p, q);
    return 0;
}