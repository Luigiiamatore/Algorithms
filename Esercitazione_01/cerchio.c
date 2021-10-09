#include <stdio.h>
#include <math.h>

int main(void) {
    float r;
    float area;
    printf("Raggio cerchio:\t");
    scanf("%f", &r);
    area = M_PI * r * r;
    printf("Area: %f", area);
    return 0;
}