#include <stdio.h>

int main() {
    int max;
    int read;

    printf("max: ");
    scanf("%d", &max);

    printf("sequenza: ");
    for (int i = 0; i <= max; i++) {
        if (i == max) {
            printf("%d", i);
            break;
        }
        scanf("%d", &read);
        if (read != i) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}