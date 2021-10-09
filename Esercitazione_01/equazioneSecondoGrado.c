#include <stdio.h>
#include <math.h>

int main(void){
    int a,b,c;
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    float delta = - ((b * b) - 4 * a * c);

    printf("Le soluzioni dell'equazioe sono:\n");
    printf("x1 = %f + i*%f\n", -b / 2*a, sqrt(delta) / 2*a);
    printf("x2 = %f + i*%f\n", -b / 2*a, -sqrt(delta) / 2*a);
}