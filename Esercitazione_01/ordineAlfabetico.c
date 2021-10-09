#include <stdio.h>
#include <stdlib.h>

int main(void){
    char x, y;
    scanf("%c %c", &x, &y);

    printf("%d", abs(x - y));
}