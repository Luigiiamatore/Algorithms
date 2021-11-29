#include "libpsgraph.h"
#include <stdio.h>

void curvaKoch (int x, int i) {
    if (i == 0)
        draw(x);
    else {
        curvaKoch(x/3, i-1);
        turn(300);
        curvaKoch(x/3, i-1);
        turn(120);
        curvaKoch(x/3, i-1);
        turn(300);
        curvaKoch(x/3, i-1);
    }
}

int main() {
    int x, i;
    printf("Inserisci millimetri: ");
    scanf("%d", &x);
    printf("Inserisci grado: ");
    scanf("%d", &i);
    start("curvaKoch.ps");
    curvaKoch(x,i);
    end();
    return 0;
}
