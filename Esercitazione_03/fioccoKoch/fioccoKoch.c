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

void fioccoKoch (int x, int i) {
    start("fioccoKoch.ps");
    turn(300);
    curvaKoch(x, i);
    turn(120);
    curvaKoch(x, i);
    turn(120);
    curvaKoch(x, i);
    end();
}

int main() {
    int x, i;
    printf("Inserire i millimetri: ");
    scanf("%d", &x);
    printf("Inserire il grado: ");
    scanf("%d", &i);
    fioccoKoch(x, i);
    return 0;
}