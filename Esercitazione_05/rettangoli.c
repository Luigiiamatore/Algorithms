#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Punto;

typedef struct {
    Punto p1;
    Punto p2;
} Rettangolo;

int main () {
    float b, h, area, duep;
    Rettangolo *r;
    r = malloc(sizeof(Rettangolo));

    if (r == NULL) {
        printf("Errore di allocazione");
        exit(EXIT_FAILURE);
    }

    printf ("Inserisci le coordinate del punto in basso a sinistra\n");
    scanf (" %f %f", &r -> p1.x, &r -> p1.y);
    printf ("Inserisci le coordinate del punto in alto a destra\n");
    scanf ("%f%f", &r -> p2.x, &r -> p2.y);
    b = r -> p2.x - r -> p1.x;
    h = r -> p2.y - r -> p1.y;
    area = b * h;
    duep = 2 * (b + h);
    printf ("L’area del rettangolo vale %f, il perimetro vale %f\n", area, duep);
    free(r);

    return 0;
}