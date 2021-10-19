#include <stdio.h>
#define DIM 1000

int main() {
    int nBit;
    int bit[DIM];

    printf("numero bit: ");
    scanf("%d", &nBit);

    for (int i = 0; i < nBit; i++) {
        scanf("%d", &bit[i]);
    }

    for (int i = 0; i < nBit - 1; i++) {
        for (int j = 0; j < nBit - 1; j++) {
            if (bit[j] > bit[j+1]) {
                bit[j] = 0;
                bit[j+1] = 1;
            }
        }
    }

    for (int i = 0; i < nBit; i++) {
        printf("%d ", bit[i]);
    }

    return 0;
}