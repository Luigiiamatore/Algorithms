#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int h1, m1, s1;
    int h2, m2, s2;
    int distanza;
    printf("Orario 1: ");
    scanf("%d:%d:%d", &h1, &m1, &s1);
    printf("Orario 2: ");
    scanf("%d:%d:%d", &h2, &m2, &s2);

    distanza = abs(h1 - h2) * 3600;
    distanza += abs(m1 - m2) * 60;
    distanza += abs(s1 - s2);
    printf("Distanza orari: %d secondi", distanza);
}